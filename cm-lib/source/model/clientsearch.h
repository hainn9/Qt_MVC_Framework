#ifndef CLIENTSEARCH_H
#define CLIENTSEARCH_H

#include <QScopedPointer>
#include <data/stringdecorator.h>
#include <data/entity.h>
#include <data/entitycollection.h>
#include <controllers/idatabasecontroller.h>
#include <model/client.h>
#include <cm-lib_global.h>

namespace cm {
namespace models {

class CMLIB_EXPORT ClientSearch : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY(cm::data::StringDecorator* ui_searchText READ searchText CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::models::Client> ui_searchResults READ ui_searchResults NOTIFY searchResultsChanged)
public:
    ClientSearch(QObject* parent = nullptr, controllers::IDatabaseController* idatabaseController = nullptr);
    ~ClientSearch();

    data::StringDecorator* searchText();
    QQmlListProperty<Client> ui_searchResults();
    void search();

signals:
    void searchResultsChanged();

private:
    class ClientSearchPrivate;
    QScopedPointer<ClientSearchPrivate> clientSearch_priv;
};

}
}
#endif // CLIENTSEARCH_H
