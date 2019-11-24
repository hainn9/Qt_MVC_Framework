#include "commandcontroller.h"

#include <QList>
#include <QDebug>

using namespace cm::framework;
using namespace cm::models;
namespace cm {
namespace controllers {

class CommandController::CommandControllerPrivate
{
public:
    CommandControllerPrivate(CommandController* pCommandController, IDatabaseController* _databaseController, INavigationController* _navigationController, Client* _newClient, ClientSearch* _clientSearch)
        :commandController(pCommandController),
          databaseController(_databaseController),
          navigationController(_navigationController),
          newClient(_newClient),
          clientSearch(_clientSearch)
    {
        Command* createClientSaveCommand = new Command(commandController, QChar( 0xf0c7 ), "Save");
        QObject::connect(createClientSaveCommand, &Command::executed, commandController, &CommandController::onCreateClientSaveExecuted);
        createClientViewContextCommands.append(createClientSaveCommand);

        Command* findClientSearchCommand = new Command(commandController, QChar( 0xf002 ), "Search");
        QObject::connect(findClientSearchCommand, &Command::executed, commandController, &CommandController::onFindClientSearchExecuted);
        findClientViewContextCommands.append(findClientSearchCommand);

        Command* editClientSaveCommand = new Command(commandController, QChar( 0xf0c7 ), "Save");
        QObject::connect(editClientSaveCommand, &Command::executed, commandController, &CommandController::onEditClientSaveExecuted);
        editClientViewContextCommands.append(editClientSaveCommand);

        Command* editClientDeleteCommand = new Command(commandController, QChar( 0xf235 ), "Delete");
        QObject::connect(editClientDeleteCommand, &Command::executed, commandController, &CommandController::onEditClientDeleteExecuted);
        editClientViewContextCommands.append(editClientDeleteCommand);
    }

    CommandController* commandController{nullptr};
    QList<Command*> createClientViewContextCommands{};
    QList<Command*> findClientViewContextCommands{};
    QList<Command*> editClientViewContextCommands{};
    IDatabaseController* databaseController{nullptr};
    INavigationController* navigationController{nullptr};
    Client* newClient{nullptr};
    ClientSearch* clientSearch{nullptr};
    Client* selectedClient{nullptr};
};

CommandController::CommandController(QObject *parent, IDatabaseController *idatabaseController, INavigationController* inavigationController, models::Client *newClient, ClientSearch *clientSearch)
    : ICommandController(parent)
{
    commandController_priv.reset(new CommandControllerPrivate(this, idatabaseController, inavigationController, newClient, clientSearch));
}

CommandController::~CommandController()
{

}

QQmlListProperty<Command> CommandController::ui_createClientViewContextCommand()
{
    return QQmlListProperty<Command>(this, commandController_priv->createClientViewContextCommands);
}

QQmlListProperty<Command> CommandController::ui_findClientViewContextCommand()
{
    return QQmlListProperty<Command>(this, commandController_priv->findClientViewContextCommands);
}

QQmlListProperty<Command> CommandController::ui_editClientViewContextCommand()
{
    return QQmlListProperty<Command>(this, commandController_priv->editClientViewContextCommands);
}

void CommandController::setSelectedClient(Client *client)
{
    commandController_priv->selectedClient = client;
}

void CommandController::onCreateClientSaveExecuted()
{
    qDebug() << "Executed the Save command";
    commandController_priv->databaseController->createRow(commandController_priv->newClient->key(),
                                                          commandController_priv->newClient->id(),
                                                          commandController_priv->newClient->toJson());
    qDebug() << "New Client Saved";
//    commandController_priv->clientSearch->searchText()->setValue(commandController_priv->newClient->id());
//    commandController_priv->clientSearch->search();
//    commandController_priv->navigationController->goFindClientView();
}

void CommandController::onFindClientSearchExecuted()
{
    qDebug() << "Executed the Search command";
    commandController_priv->clientSearch->search();
}

void CommandController::onEditClientSaveExecuted()
{
    qDebug() << "Executed the Save command";
    commandController_priv->databaseController->updateRow(commandController_priv->selectedClient->key(),
                                                          commandController_priv->selectedClient->id(),
                                                          commandController_priv->selectedClient->toJson());
    qDebug() << "Saved Edit client";
}

void CommandController::onEditClientDeleteExecuted()
{
    qDebug() << "Executed the Delete command";
    commandController_priv->databaseController->deleteRow(commandController_priv->selectedClient->key(),
                                                          commandController_priv->selectedClient->id());
    commandController_priv->selectedClient = nullptr;
    qDebug() << "Deleted client";
    commandController_priv->clientSearch->search();
    commandController_priv->navigationController->goDashboardView();
}

}}
