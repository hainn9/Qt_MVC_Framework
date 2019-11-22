#include "enumdecorator.h"
#include <QVariant>
namespace cm {
namespace data {

class EnumDecorator::EnumDecoratorPrivate
{
public:
    EnumDecoratorPrivate(EnumDecorator* pIntDecorator, const int& pValue, const std::map<int, QString>& pDescriptionMapper)
        :intDecorator(pIntDecorator),
          value(pValue),
          descriptionMapper(pDescriptionMapper)
    {}

    EnumDecorator* intDecorator{nullptr};
    int value;
    std::map<int, QString> descriptionMapper;
};

EnumDecorator::EnumDecorator(Entity *parent, const QString& key, const QString& label,
                             const int& value, const std::map<int, QString>& pDescriptionMapper)
    :DataDecorator(parent, key, label)
{
    enumDecorator_priv.reset(new EnumDecoratorPrivate(this, value, pDescriptionMapper));
}

EnumDecorator::~EnumDecorator()
{

}

EnumDecorator& EnumDecorator::setValue(const int &value)
{
    if (value != enumDecorator_priv->value)
    {
        enumDecorator_priv->value = value;
        emit valueChanged();
    }
    return *this;
}

const int& EnumDecorator::value() const
{
    return enumDecorator_priv->value;
}

QString EnumDecorator::valueDescription() const
{
    if (enumDecorator_priv->descriptionMapper.find(enumDecorator_priv->value) != enumDecorator_priv->descriptionMapper.end()) {
        return enumDecorator_priv->descriptionMapper.at(enumDecorator_priv->value);
    } else {
        return "";
    }
}

QJsonValue EnumDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(enumDecorator_priv->value));
}

void EnumDecorator::update(const QJsonObject &jsonObj)
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
