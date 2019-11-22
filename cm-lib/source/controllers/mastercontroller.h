#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QString>
#include <QScopedPointer>

#include <cm-lib_global.h>
#include <controllers/navigationcontroller.h>
#include <controllers/commandcontroller.h>
#include <model/client.h>

namespace cm {
namespace controllers {

class CMLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY( QString ui_welcomeMessage READ welcomeMessage CONSTANT )
    Q_PROPERTY( cm::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT )
    Q_PROPERTY( cm::controllers::CommandController* ui_commandController READ commandController CONSTANT )
    Q_PROPERTY(cm::models::Client* ui_client READ client CONSTANT)
public:
    explicit MasterController(QObject *parent = nullptr);
    ~MasterController();

    NavigationController* navigationController();
    CommandController* commandController();
    models::Client* client();
    const QString& welcomeMessage() const;


signals:

public slots:

private:
    class MasterControllerPrivate;
    QScopedPointer<MasterControllerPrivate> masterController_priv;
};

}}
#endif // MASTERCONTROLLER_H
