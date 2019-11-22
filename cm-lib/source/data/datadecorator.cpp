#include "datadecorator.h"

namespace cm {
namespace data {

class DataDecorator::DataDecoratorPrivate
{
public:
    DataDecoratorPrivate(Entity* pEntity, const QString& pKey, const QString& pLabel)
        :parentEntity(pEntity),
          key(pKey),
          label(pLabel)
    {}

    Entity* parentEntity;
    QString key;
    QString label;
};

DataDecorator::DataDecorator(Entity* parent, const QString& key, const QString& label)
    :QObject(reinterpret_cast<QObject*>(parent))
{
    dataDecorator_priv.reset(new DataDecoratorPrivate(parent, key, label));
}

DataDecorator::~DataDecorator()
{

}

const QString& DataDecorator::key() const
{
    return dataDecorator_priv->key;
}

const QString& DataDecorator::label() const
{
    return dataDecorator_priv->label;
}

Entity* DataDecorator::parentEntity()
{
    return dataDecorator_priv->parentEntity;
}

}
}
