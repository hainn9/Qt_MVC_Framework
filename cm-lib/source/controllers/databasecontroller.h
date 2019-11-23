#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <controllers/idatabasecontroller.h>
#include <QScopedPointer>

namespace cm {
namespace controllers {
class CMLIB_EXPORT DatabaseController : public IDatabaseController
{
    Q_OBJECT
public:
    explicit DatabaseController(QObject* parent = nullptr);
    ~DatabaseController();

    bool createRow(const QString &tableName, const QString &id, const QJsonObject &jsonObj) const override;
    bool deleteRow(const QString &tableName, const QString &id) const override;
    bool updateRow(const QString &tableName, const QString &id, const QJsonObject &jsonObj) const override;
    QJsonArray find(const QString &tableName, const QString &searchPattern) const override;
    QJsonObject readRow(const QString &tableName, const QString &id) const override;

private:
    class DatabaseControllerPrivate;
    QScopedPointer<DatabaseControllerPrivate> dbCtrl_priv;
};

}}

#endif // DATABASECONTROLLER_H
