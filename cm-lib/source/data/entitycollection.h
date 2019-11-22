#ifndef ENTITYCOLLECTION_H
#define ENTITYCOLLECTION_H

#include <QObject>
#include <cm-lib_global.h>
#include <QList>
#include <QJsonArray>
#include <QJsonValue>
namespace cm {
namespace data {

class Entity;

class CMLIB_EXPORT EntityCollectionObject : public QObject
{
    Q_OBJECT
public:
    explicit EntityCollectionObject(QObject* parent = nullptr) : QObject(parent) {}

    virtual ~EntityCollectionObject() {}

signals:
    void collectionChanged();
};

class EntityCollectionBase : public EntityCollectionObject
{
public:
    EntityCollectionBase(QObject* parent = nullptr, const QString& pKey = "CollectionKey")
        :EntityCollectionObject(parent),
          m_key(pKey)
    {}

    virtual ~EntityCollectionBase() {}

    QString getKey() const
    {
        return m_key;
    }

    virtual void clear() = 0;
    virtual void update(const QJsonArray& pJsonArr) = 0;
    virtual std::vector<Entity*> baseEntities() = 0;

    template<class T>
    QList<T*>& deriveEntities();

    template<class T>
    T* addEntity(T* entity);

private:
    QString m_key;
};

template<class T>
class EntityCollection : public EntityCollectionBase
{
public:
    EntityCollection(QObject* parent = nullptr, const QString& pKey = "CollectionKey")
        :EntityCollectionBase(parent, pKey)
    {}

    ~EntityCollection() {}

    void clear() override
    {
        for(auto e : m_collections)
        {
            e->deleteLater();
        }
        m_collections.clear();
    }

    void update(const QJsonArray &pJsonArr) override
    {
        clear();
        for(const QJsonValue& jsonValue : pJsonArr)
        {
            addEntity(new T(this, jsonValue.toObject()));
        }
    }

    std::vector<Entity *> baseEntities() override
    {
        std::vector<Entity*> retValue;
        for(T* entity : m_collections)
        {
            retValue.push_back(entity);
        }
        return retValue;
    }

    QList<T*>& deriveEntities()
    {
        return m_collections;
    }

    T* addEntity(T* entity)
    {
        if(!m_collections.contains(entity)) {
            m_collections.append(entity);
            EntityCollectionBase::collectionChanged();
        }
        return entity;
    }

private:
    QList<T*> m_collections;
};

template<class T>
QList<T*>& EntityCollectionBase::deriveEntities()
{
    return dynamic_cast<const EntityCollection<T>&>(*this).deriveEntities();
}

template<class T>
T* EntityCollectionBase::addEntity(T* entity)
{
    return dynamic_cast<const EntityCollection<T>&>(*this).addEntity();
}

}
}

#endif // ENTITYCOLLECTION_H
