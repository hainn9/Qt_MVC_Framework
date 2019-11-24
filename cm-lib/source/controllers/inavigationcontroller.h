#ifndef INAVIGATIONCONTROLLER_H
#define INAVIGATIONCONTROLLER_H

#include <model/client.h>
#include <cm-lib_global.h>
#include <QObject>

namespace cm {
namespace controllers {

class CMLIB_EXPORT INavigationController : public QObject
{
    Q_OBJECT
public:
    explicit INavigationController(QObject* pParent = nullptr)
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

#endif // INAVIGATIONCONTROLLER_H
