#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <framework/iobjectfactory.h>
namespace cm {
namespace framework {

class CMLIB_EXPORT ObjectFactory : public IObjectFactory
{
    Q_OBJECT
public:
    ObjectFactory();

    controllers::IDatabaseController * createDatabaseController(QObject *parent) const override;
    controllers::INavigationController * createNavigationController(QObject *parent) const override;
    controllers::ICommandController * createCommandController(QObject *parent, controllers::IDatabaseController *databaseController, controllers::INavigationController *navigationController, models::Client *client, models::ClientSearch *clientSearch) const override;
    models::Client * createClient(QObject *parent) const override;
    models::ClientSearch * createClientSearch(QObject *parent, controllers::IDatabaseController *databaseController) const override;
};

}
}
#endif // OBJECTFACTORY_H
