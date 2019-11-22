#include "intdecorator.h"
#include <QVariant>
namespace cm {
namespace data {

class IntDecorator::IntDecoratorPrivate
{
public:
    IntDecoratorPrivate(IntDecorator* pIntDecorator, const int& pValue)
        :intDecorator(pIntDecorator),
          value(pValue)
    {}

    IntDecorator* intDecorator{nullptr};
    int value;
};

IntDecorator::IntDecorator(Entity *parent, const QString& key, const QString& label, const int& value)
    :DataDecorator(parent, key, label)
{
    intDecorator_priv.reset(new IntDecoratorPrivate(this, value));
}

IntDecorator::~IntDecorator()
{

}

IntDecorator& IntDecorator::setValue(const int &value)
{
    if (value != intDecorator_priv->value)
    {
        intDecorator_priv->value = value;
        emit valueChanged();
    }
    return *this;
}

const int& IntDecorator::value() const
{
    return intDecorator_priv->value;
}

QJsonValue IntDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(intDecorator_priv->value));
}

void IntDecorator::update(const QJsonObject &jsonObj)
{
    if (jsonObj.contains(key()))
    {
        setValue(jsonObj.value(key()).toInt());
    }
    else
    {
        setValue(0);
    }
}

}
}
