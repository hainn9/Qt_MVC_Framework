#include "clientsearch.h"
#include <QDebug>
using namespace cm::data;
using namespace cm::controllers;
namespace cm {
namespace models {

class ClientSearch::ClientSearchPrivate
{
public:
    ClientSearchPrivate(ClientSearch* parent, IDatabaseController* _databaseController)
        :clientSearch(parent),
          idatabaseController(_databaseController)
    {}

    ClientSearch* clientSearch{nullptr};
    IDatabaseController* idatabaseController{nullptr};
    StringDecorator* searchText{nullptr};
    EntityCollection<Client>* searchResults{nullptr};
};

ClientSearch::ClientSearch(QObject* parent, IDatabaseController* idatabaseController)
    :Entity(parent, "clientSearch")
{
    clientSearch_priv.reset(new ClientSearchPrivate(this, idatabaseController));
    clientSearch_priv->searchText = static_cast<StringDecorator*>(addDataDecorator(new StringDecorator(this, "searchText", "Search Pattern")));
    clientSearch_priv->searchResults = static_cast<EntityCollection<Client>*>(addEntityCollection(new EntityCollection<Client>(this, "searchResults")));
    connect(clientSearch_priv->searchResults, &EntityCollection<Client>::collectionChanged, this, &ClientSearch::searchResultsChanged);
}

ClientSearch::~ClientSearch()
{

}

StringDecorator *ClientSearch::searchText()
{
    return clientSearch_priv->searchText;
}

QQmlListProperty<Client> ClientSearch::ui_searchResults()
{
    return QQmlListProperty<Client>(this, clientSearch_priv->searchResults->deriveEntities());
}

void ClientSearch::search()
{
    qDebug() << "Searching for " << clientSearch_priv->searchText->value() << "...";
    auto results = clientSearch_priv->idatabaseController->find("client", clientSearch_priv->searchText->value());
    clientSearch_priv->searchResults->update(results);
    qDebug() << "Found" << clientSearch_priv->searchResults->baseEntities().size() << "matches";
}

}
}
