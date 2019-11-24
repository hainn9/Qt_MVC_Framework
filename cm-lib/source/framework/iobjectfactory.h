#ifndef IOBJECTFACTORY_H
#define IOBJECTFACTORY_H

#include <cm-lib_global.h>
#include <QObject>
#include <controllers/icommandcontroller.h>
#include <controllers/idatabasecontroller.h>
#include <controllers/inavigationcontroller.h>
#include <model/client.h>
#include <model/clientsearch.h>

namespace cm {
namespace framework {

class CMLIB_EXPORT IObjectFactory : public QObject
{
    Q_OBJECT
public:
    virtual ~IObjectFactory() {}

    virtual models::Client* createClient(QObject* parent) const = 0;
    virtual models::ClientSearch* createClientSearch(QObject* parent, controllers::IDatabaseController* databaseController) const = 0;
    virtual controllers::ICommandController* createCommandController(QObject* parent, controllers::IDatabaseController* databaseController, controllers::INavigationController* navigationController,
                                                                     models::Client* client, models::ClientSearch* clientSearch) const = 0;
    virtual controllers::INavigationController* createNavigationController(QObject* parent) const = 0;
    virtual controllers::IDatabaseController* createDatabaseController(QObject* parent) const = 0;
};

}
}

#endif // IOBJECTFACTORY_H
