#include "datetimedecorator.h"
#include <QVariant>
#include <QString>
namespace cm {
namespace data {

class DateTimeDecorator::DateTimeDecoratorPrivate
{
public:
    DateTimeDecoratorPrivate(DateTimeDecorator* pDateTimeDecorator, const QDateTime& pValue)
        :datetimeDecorator(pDateTimeDecorator),
          value(pValue)
    {}

    DateTimeDecorator* datetimeDecorator{nullptr};
    QDateTime value;
};

DateTimeDecorator::DateTimeDecorator(Entity *parent, const QString& key, const QString& label, const QDateTime& value)
    :DataDecorator(parent, key, label)
{
    datetimeDecorator_priv.reset(new DateTimeDecoratorPrivate(this, value));
}

DateTimeDecorator::~DateTimeDecorator()
{

}

DateTimeDecorator &DateTimeDecorator::setValue(const QDateTime &value)
{
    if (value != datetimeDecorator_priv->value)
    {
        datetimeDecorator_priv->value = value;
        emit valueChanged();
    }
    return *this;
}

const QDateTime &DateTimeDecorator::value() const
{
    return datetimeDecorator_priv->value;
}

QString DateTimeDecorator::toIsoString() const
{
    if (datetimeDecorator_priv->value.isNull())
    {
        return "";
    }
    else
    {
        return datetimeDecorator_priv->value.toString(Qt::ISODate);
    }
}

QString DateTimeDecorator::toPrettyDateString() const
{
    if (datetimeDecorator_priv->value.isNull())
    {
        return "Not set";
    }
    else
    {
        return datetimeDecorator_priv->value.toString("d MMM yyyy");
    }
}

QString DateTimeDecorator::toPrettyTimeString() const
{
    if (datetimeDecorator_priv->value.isNull()) {
        return "Not set";
    } else {
        return datetimeDecorator_priv->value.toString("hh:mm ap");
    }
}

QString DateTimeDecorator::toPrettyString() const
{
    if (datetimeDecorator_priv->value.isNull()) {
        return "Not set";
    } else {
        return datetimeDecorator_priv->value.toString("ddd d MMM yyyy @ HH:mm:ss");
    }
}

QJsonValue DateTimeDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(datetimeDecorator_priv->value));
}

void DateTimeDecorator::update(const QJsonObject &jsonObj)
{
    if (jsonObj.contains(key()))
    {
        setValue(QDateTime::fromString(jsonObj.value(key()).toString()));
    }
    else
    {
        setValue(QDateTime::currentDateTime());
    }
}

}
}
