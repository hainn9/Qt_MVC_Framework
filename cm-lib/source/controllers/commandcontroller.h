#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QObject>
#include <QtQml/QQmlListProperty>
#include <cm-lib_global.h>
#include <framework/command.h>

namespace cm {
namespace controllers {
class CMLIB_EXPORT CommandController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommand READ ui_createClientViewContextCommand CONSTANT)
public:
    explicit CommandController(QObject *parent = nullptr);
    ~CommandController();

    QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommand();

signals:

public slots:
    void onCreateClientSaveExecuted();

private:
    class CommandControllerPrivate;
    QScopedPointer<CommandControllerPrivate> commandController_priv;
};

}}
#endif // COMMANDCONTROLLER_H
