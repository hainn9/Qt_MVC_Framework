#include "mastercontroller.h"

using namespace cm::models;
using namespace cm::framework;

namespace cm {
namespace controllers {

class MasterController::MasterControllerPrivate
{
public:
    MasterControllerPrivate(MasterController* pMasterController, IObjectFactory* _objectFactory)
        :masterController(pMasterController),
          objectFactory(_objectFactory)
    {
        databaseController = objectFactory->createDatabaseController(pMasterController);
        navigationController = objectFactory->createNavigationController(pMasterController);
        client = objectFactory->createClient(pMasterController);
        clientSearch = objectFactory->createClientSearch(pMasterController, databaseController);
        commandController = objectFactory->createCommandController(pMasterController, databaseController, navigationController, client, clientSearch);
    }

    MasterController* masterController{nullptr};
    INavigationController* navigationController{nullptr};
    ICommandController* commandController{nullptr};
    IDatabaseController* databaseController{nullptr};
    Client* client{nullptr};
    ClientSearch* clientSearch{nullptr};
    IObjectFactory* objectFactory{nullptr};
    QString welcomeMessage = "This is MasterController";
};

MasterController::MasterController(QObject *parent, framework::IObjectFactory *objectFactory) : QObject(parent)
{
    masterController_priv.reset(new MasterControllerPrivate(this, objectFactory));
}

MasterController::~MasterController()
{

}

INavigationController* MasterController::navigationController()
{
    return masterController_priv->navigationController;
}

ICommandController* MasterController::commandController()
{
    return masterController_priv->commandController;
}

IDatabaseController* MasterController::databaseController()
{
    return masterController_priv->databaseController;
}

Client* MasterController::client()
{
    return masterController_priv->client;
}

ClientSearch* MasterController::clientSearch()
{
    return masterController_priv->clientSearch;
}

const QString& MasterController::welcomeMessage() const
{
    return masterController_priv->welcomeMessage;
}

void MasterController::selectClient(Client *client)
{
    masterController_priv->navigationController->goEditClientView(client);
}

}}
