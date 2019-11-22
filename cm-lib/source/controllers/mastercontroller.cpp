#include "mastercontroller.h"

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
    }

    MasterController* masterController{nullptr};
    NavigationController* navigationController{nullptr};
    CommandController* commandController{nullptr};
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

const QString& MasterController::welcomeMessage() const
{
    return masterController_priv->welcomeMessage;
}

}}
