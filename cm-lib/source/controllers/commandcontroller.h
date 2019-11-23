#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QObject>
#include <QtQml/QQmlListProperty>
#include <cm-lib_global.h>
#include <framework/command.h>
#include <controllers/idatabasecontroller.h>
#include <controllers/navigationcontroller.h>
#include <model/client.h>
#include <model/clientsearch.h>

namespace cm {
namespace controllers {
class CMLIB_EXPORT CommandController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommand READ ui_createClientViewContextCommand CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommand READ ui_findClientViewContextCommand CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_editClientViewContextCommand READ ui_editClientViewContextCommand CONSTANT)
public:
    explicit CommandController(QObject *parent = nullptr, IDatabaseController* idatabaseController = nullptr, NavigationController* navigationController = nullptr, models::Client* newClient = nullptr, models::ClientSearch* clientSearch = nullptr);
    ~CommandController();

    QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommand();
    QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommand();
    QQmlListProperty<cm::framework::Command> ui_editClientViewContextCommand();

signals:

public slots:
    void setSelectedClient(cm::models::Client* client);
    void onCreateClientSaveExecuted();
    void onFindClientSearchExecuted();
    void onEditClientSaveExecuted();
    void onEditClientDeleteExecuted();

private:
    class CommandControllerPrivate;
    QScopedPointer<CommandControllerPrivate> commandController_priv;
};

}}
#endif // COMMANDCONTROLLER_H
