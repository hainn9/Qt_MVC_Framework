#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QString>
#include <QScopedPointer>

#include <cm-lib_global.h>
#include <controllers/navigationcontroller.h>
#include <controllers/commandcontroller.h>
#include <controllers/databasecontroller.h>
#include <model/client.h>
#include <model/clientsearch.h>

namespace cm {
namespace controllers {

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString ui_welcomeMessage READ welcomeMessage CONSTANT )
    Q_PROPERTY( cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT )
    Q_PROPERTY( cm::controllers::CommandController* ui_commandController READ commandController CONSTANT )
    Q_PROPERTY( cm::controllers::DatabaseController* ui_databaseController READ databaseController CONSTANT )
    Q_PROPERTY( cm::models::Client* ui_client READ client CONSTANT )
    Q_PROPERTY( cm::models::ClientSearch* ui_clientSearch READ clientSearch CONSTANT )
public:
    explicit MasterController(QObject *parent = nullptr);
    ~MasterController();

    NavigationController* navigationController();
    CommandController* commandController();
    DatabaseController* databaseController();
    models::Client* client();
    models::ClientSearch* clientSearch();
    const QString& welcomeMessage() const;


signals:

public slots:
    void selectClient(cm::models::Client* client);

private:
    class MasterControllerPrivate;
    QScopedPointer<MasterControllerPrivate> masterController_priv;
};

}}
#endif // MASTERCONTROLLER_H
