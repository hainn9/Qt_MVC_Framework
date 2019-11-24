#include "objectfactory.h"
#include <controllers/databasecontroller.h>
#include <controllers/navigationcontroller.h>
#include <controllers/commandcontroller.h>

using namespace cm::controllers;
using namespace cm::models;

namespace cm {
namespace framework {

ObjectFactory::ObjectFactory()
    :IObjectFactory()
{

}

IDatabaseController *ObjectFactory::createDatabaseController(QObject *parent) const
{
    return new DatabaseController(parent);
}

INavigationController *ObjectFactory::createNavigationController(QObject *parent) const
{
    return new NavigationController(parent);
}

ICommandController *ObjectFactory::createCommandController(QObject *parent, IDatabaseController *databaseController, INavigationController *navigationController, Client *client, ClientSearch *clientSearch) const
{
    return new CommandController(parent, databaseController, navigationController, client, clientSearch);
}

Client *ObjectFactory::createClient(QObject *parent) const
{
    return new Client(parent);
}

ClientSearch *ObjectFactory::createClientSearch(QObject *parent, IDatabaseController *databaseController) const
{
    return new ClientSearch(parent, databaseController);
}

}
}
