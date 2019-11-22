#include "address.h"

using namespace cm::data;

namespace cm {
namespace models {

Address::Address(QObject* parent)
    :Entity(parent, "address")
{
    building = static_cast<StringDecorator*>(addDataDecorator(new StringDecorator(this, "building", "Building")));
    street = static_cast<StringDecorator*>(addDataDecorator(new StringDecorator(this, "street", "Street")));
    city = static_cast<StringDecorator*>(addDataDecorator(new StringDecorator(this, "city", "City")));
    postcode = static_cast<StringDecorator*>(addDataDecorator(new StringDecorator(this, "postcode", "Post Code")));
}

Address::Address(QObject* parent, const QJsonObject& jsonObj)
    :Address(parent)
{
    update(jsonObj);
}

QString Address::fullAddress() const
{
    return building->value() + " " + street->value() + "\n" + city->value() + "\n" + postcode->value();
}

}
}
