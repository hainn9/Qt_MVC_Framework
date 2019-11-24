#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QString>
#include <QScopedPointer>

#include <cm-lib_global.h>
#include <controllers/inavigationcontroller.h>
#include <controllers/icommandcontroller.h>
#include <controllers/idatabasecontroller.h>
#include <model/client.h>
#include <model/clientsearch.h>
#include <framework/iobjectfactory.h>

namespace cm {
namespace controllers {

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString ui_welcomeMessage READ welcomeMessage CONSTANT )
    Q_PROPERTY( cm::controllers::INavigationController* ui_navigationController READ navigationController CONSTANT )
    Q_PROPERTY( cm::controllers::ICommandController* ui_commandController READ commandController CONSTANT )
    Q_PROPERTY( cm::controllers::IDatabaseController* ui_databaseController READ databaseController CONSTANT )
    Q_PROPERTY( cm::models::Client* ui_client READ client CONSTANT )
    Q_PROPERTY( cm::models::ClientSearch* ui_clientSearch READ clientSearch CONSTANT )
public:
    explicit MasterController(QObject *parent = nullptr, framework::IObjectFactory* objectFactory = nullptr);
    ~MasterController();

    INavigationController* navigationController();
    ICommandController* commandController();
    IDatabaseController* databaseController();
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
