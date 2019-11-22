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
        navigationController = new NavigationController(pMasterController);
        commandController = new CommandController(pMasterController);
        client = new Client(pMasterController);
    }

    MasterController* masterController{nullptr};
    NavigationController* navigationController{nullptr};
    CommandController* commandController{nullptr};
    Client* client{nullptr};
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

Client* MasterController::client()
{
    return masterController_priv->client;
}

const QString& MasterController::welcomeMessage() const
{
    return masterController_priv->welcomeMessage;
}

}}
