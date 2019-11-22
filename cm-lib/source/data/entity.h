#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <data/datadecorator.h>
#include <data/entitycollection.h>

namespace cm {
namespace data {
class CMLIB_EXPORT Entity : public QObject
{
    Q_OBJECT
public:
    Entity(QObject *parent = nullptr, const QString& key = "EntityKey");
    Entity(QObject* parent, const QString& key, const QJsonObject& jsonObj);
    virtual ~Entity();

    const QString& key() const;
    void update(const QJsonObject& jsonObj);
    QJsonObject toJson() const;

protected:
    Entity* addEntity(Entity* entity, const QString& key);
    DataDecorator* addDataDecorator(DataDecorator* dataDecorator);
    EntityCollectionBase* addEntityCollection(EntityCollectionBase* collection);

signals:
    void entitiesChanged();
    void dataDecoratorsChanged();
    void entityCollectionChanged();

public slots:

private:
    class EntityPrivate;
    QScopedPointer<EntityPrivate> entity_priv;
};
}}
#endif // ENTITY_H
