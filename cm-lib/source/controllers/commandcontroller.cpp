#include "commandcontroller.h"

#include <QList>
#include <QDebug>

using namespace cm::framework;
namespace cm {
namespace controllers {

class CommandController::CommandControllerPrivate
{
public:
    CommandControllerPrivate(CommandController* pCommandController)
        :commandController(pCommandController)
    {
        Command* createClientSaveCommand = new Command(commandController, QChar( 0xf0c7 ), "Save");
        QObject::connect(createClientSaveCommand, &Command::executed, commandController, &CommandController::onCreateClientSaveExecuted);
        createClientViewContextCommands.append(createClientSaveCommand);
    }

    CommandController* commandController{nullptr};
    QList<Command*> createClientViewContextCommands{};
};

CommandController::CommandController(QObject *parent) : QObject(parent)
{
    commandController_priv.reset(new CommandControllerPrivate(this));
}

CommandController::~CommandController()
{

}

QQmlListProperty<Command> CommandController::ui_createClientViewContextCommand()
{
    return QQmlListProperty<Command>(this, commandController_priv->createClientViewContextCommands);
}

void CommandController::onCreateClientSaveExecuted()
{
    qDebug() << "Executed the Save command";
}

}}
