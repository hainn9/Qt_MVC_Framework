#include "mastercontroller.h"

using namespace cm::models;

namespace cm {
namespace controllers {

class MasterController::MasterControllerPrivate
{
public:
    MasterControllerPrivate(MasterController* pMasterController)
        :masterController(pMasterController)
    {
        databaseController = new DatabaseController(pMasterController);
        navigationController = new NavigationController(pMasterController);
        client = new Client(pMasterController);
        clientSearch = new ClientSearch(pMasterController, databaseController);
        commandController = new CommandController(pMasterController, databaseController, navigationController, client, clientSearch);
    }

    MasterController* masterController{nullptr};
    NavigationController* navigationController{nullptr};
    CommandController* commandController{nullptr};
    DatabaseController* databaseController{nullptr};
    Client* client{nullptr};
    ClientSearch* clientSearch{nullptr};
    QString welcomeMessage = "This is MasterController";
};

MasterController::MasterController(QObject *parent) : QObject(parent)
{
    masterController_priv.reset(new MasterControllerPrivate(this));
}

MasterController::~MasterController()
{

}

NavigationController* MasterController::navigationController()
{
    return masterController_priv->navigationController;
}

CommandController* MasterController::commandController()
{
    return masterController_priv->commandController;
}

DatabaseController* MasterController::databaseController()
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
