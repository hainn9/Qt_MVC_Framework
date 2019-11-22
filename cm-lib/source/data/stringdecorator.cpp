#include "stringdecorator.h"
#include <QVariant>
namespace cm {
namespace data {

class StringDecorator::StringDecoratorPrivate
{
public:
    StringDecoratorPrivate(StringDecorator* pStringDecorator, const QString& pValue)
        :stringDecorator(pStringDecorator),
          value(pValue)
    {}

    StringDecorator* stringDecorator{nullptr};
    QString value;
};

StringDecorator::StringDecorator(Entity *parent, const QString& key, const QString& label, const QString& value)
    :DataDecorator(parent, key, label)
{
    stringDecorator_priv.reset(new StringDecoratorPrivate(this, value));
}

StringDecorator::~StringDecorator()
{

}

StringDecorator& StringDecorator::setValue(const QString &value)
{
    if (value != stringDecorator_priv->value)
    {
        stringDecorator_priv->value = value;
        emit valueChanged();
    }
    return *this;
}

const QString& StringDecorator::value() const
{
    return stringDecorator_priv->value;
}

QJsonValue StringDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(stringDecorator_priv->value));
}

void StringDecorator::update(const QJsonObject &jsonObj)
{
    if (jsonObj.contains(key()))
    {
        setValue(jsonObj.value(key()).toString());
    }
    else
    {
        setValue("");
    }
}

}
}
