#ifndef ICOMMANDCONTROLLER_H
#define ICOMMANDCONTROLLER_H

#include <QObject>
#include <QtQml/QQmlListProperty>
#include <cm-lib_global.h>
#include <framework/command.h>
#include <controllers/idatabasecontroller.h>
#include <controllers/inavigationcontroller.h>
#include <model/client.h>
#include <model/clientsearch.h>

namespace cm {
namespace controllers {
class CMLIB_EXPORT ICommandController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommand READ ui_createClientViewContextCommand CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommand READ ui_findClientViewContextCommand CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::framework::Command> ui_editClientViewContextCommand READ ui_editClientViewContextCommand CONSTANT)
public:
    explicit ICommandController(QObject *parent = nullptr)
        :QObject(parent)
    {}
    virtual ~ICommandController() {}

    virtual QQmlListProperty<cm::framework::Command> ui_createClientViewContextCommand() = 0;
    virtual QQmlListProperty<cm::framework::Command> ui_findClientViewContextCommand() = 0;
    virtual QQmlListProperty<cm::framework::Command> ui_editClientViewContextCommand() = 0;

signals:

public slots:
    virtual void setSelectedClient(cm::models::Client* client) = 0;
    virtual void onCreateClientSaveExecuted() = 0;
    virtual void onFindClientSearchExecuted() = 0;
    virtual void onEditClientSaveExecuted() = 0;
    virtual void onEditClientDeleteExecuted() = 0;

};

}}

#endif // ICOMMANDCONTROLLER_H
