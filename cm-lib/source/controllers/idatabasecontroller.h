#ifndef IDATABASECONTROLLER_H
#define IDATABASECONTROLLER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QList>
#include <cm-lib_global.h>

namespace cm {
namespace controllers {

class CMLIB_EXPORT IDatabaseController : public QObject
{
    Q_OBJECT
public:
    IDatabaseController(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~IDatabaseController() {}

    virtual bool createRow(const QString& tableName, const QString& id, const QJsonObject& jsonObj) const = 0;
    virtual bool deleteRow(const QString& tableName, const QString& id) const = 0;
    virtual QJsonArray find(const QString& tableName, const QString& searchPattern) const = 0;
    virtual QJsonObject readRow(const QString& tableName, const QString& id) const = 0;
    virtual bool updateRow(const QString& tableName, const QString& id, const QJsonObject& jsonObj) const = 0;
};

}
}

#endif // IDATABASECONTROLLER_H
