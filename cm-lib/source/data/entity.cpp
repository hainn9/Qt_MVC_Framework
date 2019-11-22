#include "entity.h"
#include <QJsonArray>

namespace cm {
namespace data {

class Entity::EntityPrivate
{
public:
    EntityPrivate(Entity* pEntity, const QString& pKey)
        :entity(pEntity),
          key(pKey)
    {}

    Entity* entity{nullptr};
    QString key;
    std::map<QString, Entity*> entityMap;
    std::map<QString, DataDecorator*> dataDecoratorMap;
    std::map<QString, EntityCollectionBase*> collectionMap;
};

Entity::Entity(QObject* parent, const QString& key)
    :QObject((parent))
{
    entity_priv.reset(new EntityPrivate(this, key));
}

Entity::Entity(QObject* parent, const QString& key, const QJsonObject& jsonObj)
    :Entity(parent, key)
{
    update(jsonObj);
}

Entity::~Entity()
{

}

const QString& Entity::key() const
{
    return entity_priv->key;
}

void Entity::update(const QJsonObject &jsonObj)
{
    // Update datadecorator
    for(std::pair<QString, DataDecorator*> d : entity_priv->dataDecoratorMap) {
        d.second->update(jsonObj);
    }

    // Update entity
    for(std::pair<QString, Entity*> e : entity_priv->entityMap) {
        e.second->update(jsonObj.value(e.first).toObject());
    }

    // Update collection
    for(std::pair<QString, EntityCollectionBase*> c : entity_priv->collectionMap) {
        c.second->update(jsonObj.value(c.first).toArray());
    }
}

QJsonObject Entity::toJson() const
{
    QJsonObject retObj;
    for(std::pair<QString, DataDecorator*> d : entity_priv->dataDecoratorMap) {
        retObj.insert(d.first, d.second->jsonValue());
    }

    for(std::pair<QString, Entity*> e : entity_priv->entityMap) {
        retObj.insert(e.first, e.second->toJson());
    }

    for(std::pair<QString, EntityCollectionBase*> c : entity_priv->collectionMap) {
        QJsonArray jsonArray;
        for(Entity* e : c.second->baseEntities()) {
            jsonArray.append(e->toJson());
        }
        retObj.insert(c.first, jsonArray);
    }

    return retObj;
}

Entity* Entity::addEntity(Entity *entity, const QString &key)
{
    if (entity_priv->entityMap.find(key) == entity_priv->entityMap.end()) {
        entity_priv->entityMap[key] = entity;
        emit entitiesChanged();
    }
    return entity;
}

DataDecorator* Entity::addDataDecorator(DataDecorator *dataDecorator)
{
    if (entity_priv->dataDecoratorMap.find(dataDecorator->key()) == entity_priv->dataDecoratorMap.end()) {
        entity_priv->dataDecoratorMap[dataDecorator->key()] = dataDecorator;
        emit dataDecoratorsChanged();
    }
    return dataDecorator;
}

EntityCollectionBase* Entity::addEntityCollection(EntityCollectionBase *collection)
{
    if(entity_priv->collectionMap.find(collection->getKey()) == entity_priv->collectionMap.end()) {
        entity_priv->collectionMap[collection->getKey()] = collection;
        emit entityCollectionChanged();
    }
    return collection;
}

}
}
