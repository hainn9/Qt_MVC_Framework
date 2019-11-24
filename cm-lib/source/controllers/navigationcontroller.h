#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <controllers/inavigationcontroller.h>

namespace cm {
namespace controllers {

class CMLIB_EXPORT NavigationController : public INavigationController
{
    Q_OBJECT
public:
    explicit NavigationController(QObject* pParent = nullptr)
        :INavigationController(pParent)
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
