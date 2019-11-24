#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <controllers/icommandcontroller.h>

namespace cm {
namespace controllers {
class CMLIB_EXPORT CommandController : public ICommandController
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommand READ ui_createClientViewContextCommand CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommand READ ui_findClientViewContextCommand CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_editClientViewContextCommand READ ui_editClientViewContextCommand CONSTANT)
public:
    explicit CommandController(QObject *parent = nullptr, IDatabaseController* idatabaseController = nullptr, INavigationController* inavigationController = nullptr, models::Client* newClient = nullptr, models::ClientSearch* clientSearch = nullptr);
    ~CommandController();

    QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommand() override;
    QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommand() override;
    QQmlListProperty<cm::framework::Command> ui_editClientViewContextCommand() override;

signals:

public slots:
    void setSelectedClient(cm::models::Client* client) override;
    void onCreateClientSaveExecuted() override;
    void onFindClientSearchExecuted() override;
    void onEditClientSaveExecuted() override;
    void onEditClientDeleteExecuted() override;

private:
    class CommandControllerPrivate;
    QScopedPointer<CommandControllerPrivate> commandController_priv;
};

}}
#endif // COMMANDCONTROLLER_H
