#include "databasecontroller.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QJsonDocument>
#include <QDebug>

namespace cm {
namespace controllers {

class DatabaseController::DatabaseControllerPrivate
{
public:
    DatabaseControllerPrivate(DatabaseController* _databaseController)
        :databaseController(_databaseController)
    {
        if(initialize()) {
            qDebug() << "Database created using Sqlite version: " + sqliteVersion();
            if(createTable()) {
                qDebug() << "Database table created";
            } else {
                qDebug() << "Table created fail";
            }
        } else {
            qDebug() << "Unable to open database";
        }
    }

    DatabaseController* databaseController{nullptr};
    QSqlDatabase sqlDB;

private:
    bool initialize()
    {
        sqlDB = QSqlDatabase::addDatabase("QSQLITE", "cm");
        sqlDB.setDatabaseName("cm.sqlite");
        return sqlDB.open();
    }

    bool createJsonTable(const QString& tableName) const
    {
        QSqlQuery query(sqlDB);
        QString sqlStatement = "CREATE TABLE IF NOT EXISTS " + tableName + " (id text primary key, json text not null)";

        if(!query.prepare(sqlStatement))
            return false;
        return query.exec();
    }

    bool createTable()
    {
        return createJsonTable("client");
    }

    QString sqliteVersion() const
    {
        QSqlQuery query(sqlDB);
        query.exec("SELECT sqlite_version()");
        if(query.next())
            return query.value(0).toString();
        return QString::number(-1);
    }
};

DatabaseController::DatabaseController(QObject* parent)
    :IDatabaseController(parent)
{
    dbCtrl_priv.reset(new DatabaseControllerPrivate(this));
}

DatabaseController::~DatabaseController()
{

}

bool DatabaseController::createRow(const QString &tableName, const QString &id, const QJsonObject &jsonObj) const
{
    if(tableName.isEmpty() || id.isEmpty() || jsonObj.isEmpty())
        return false;
    QSqlQuery query(dbCtrl_priv->sqlDB);
    QString sqlStatement = "INSERT OR REPLACE INTO " + tableName + " (id, json) VALUES (:id, :json)";
    if(!query.prepare(sqlStatement))
        return false;
    query.bindValue(":id", QVariant(id));
    query.bindValue(":json", QVariant(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact)));
    if(!query.exec())
        return false;

    return query.numRowsAffected() > 0;
}

bool DatabaseController::deleteRow(const QString &tableName, const QString &id) const
{
    if(tableName.isEmpty() || id.isEmpty())
        return false;
    QSqlQuery query(dbCtrl_priv->sqlDB);
    QString sqlStatement = "DELETE FROM " + tableName + " WHERE id=:id";
    if(!query.prepare(sqlStatement))
        return false;
    query.bindValue(":id", QVariant(id));
    if(!query.exec())
        return false;
    return query.numRowsAffected() > 0;
}

QJsonObject DatabaseController::readRow(const QString &tableName, const QString &id) const
{
    if(tableName.isEmpty() || id.isEmpty())
        return {};
    QSqlQuery query(dbCtrl_priv->sqlDB);
    QString sqlStatement = "SELECT json FROM " + tableName + "WHERE id=:id";
    if(!query.prepare(sqlStatement))
        return {};
    query.bindValue(":id", QVariant(id));
    if(!query.exec())
        return {};
    if(!query.first())
        return {};

    auto json = query.value(0).toByteArray();
    auto jsonDoc = QJsonDocument::fromJson(json);

    if(!jsonDoc.isObject())
        return {};
    return jsonDoc.object();
}

QJsonArray DatabaseController::find(const QString &tableName, const QString &searchPattern) const
{
    if(tableName.isEmpty() || searchPattern.isEmpty())
        return {};
    QSqlQuery query(dbCtrl_priv->sqlDB);
    QString sqlStatement = "SELECT json FROM " + tableName + " where lower (json) like :searchPattern";
    if(!query.prepare(sqlStatement))
        return {};
    query.bindValue(":searchPattern", QVariant("%" + searchPattern.toLower() + "%"));
    if(!query.exec())
        return {};
    QJsonArray retValue;
    while (query.next()) {
        auto json = query.value(0).toByteArray();
        auto jsonDoc = QJsonDocument::fromJson(json);
        if(jsonDoc.isObject()) {
            retValue.append(jsonDoc.object());
        }
    }
    return retValue;
}

bool DatabaseController::updateRow(const QString &tableName, const QString &id, const QJsonObject &jsonObj) const
{
    if(tableName.isEmpty() || id.isEmpty() || jsonObj.isEmpty())
        return false;
    QSqlQuery query(dbCtrl_priv->sqlDB);
    QString sqlStatement = "UPDATE " + tableName + " SET json=:json WHERE id=:id";
    if(!query.prepare(sqlStatement))
        return false;
    query.bindValue(":id", QVariant(id));
    query.bindValue(":json", QVariant(QJsonDocument(jsonObj).toJson(QJsonDocument::Compact)));
    if(!query.exec())
        return false;

    return query.numRowsAffected() > 0;
}

}
}
