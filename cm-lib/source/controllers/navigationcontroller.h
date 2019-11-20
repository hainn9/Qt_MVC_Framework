#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <model/client.h>
#include <cm-lib_global.h>
#include <QObject>

namespace cm {
namespace controllers {

class CMLIB_EXPORT NavigationController : public QObject
{
    Q_OBJECT
public:
    explicit NavigationController(QObject* pParent = nullptr)
        :QObject(pParent)
    {}

signals:
    void goDashboardView();
    void goCreateClientView();
    void goFindClientView();
    void goEditClientView(cm::models::Client* client);
};

}
}

#endif // NAVIGATIONCONTROLLER_H
