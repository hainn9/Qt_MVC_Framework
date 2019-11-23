#include "client.h"

using namespace cm::data;

namespace cm {
namespace models {

Client::Client(QObject* parent)
    :Entity(parent, "client")
{
    referrence = static_cast<StringDecorator*>(addDataDecorator(new StringDecorator(this, "referrence", "Referrence")));
    name = static_cast<StringDecorator*>(addDataDecorator(new StringDecorator(this, "name", "Name")));
    supplyAddress = static_cast<Address*>(addEntity(new Address(this), "supplyAddress"));
    billingAddress = static_cast<Address*>(addEntity(new Address(this), "billingAddress"));
    appointment = static_cast<EntityCollection<Appointment>*>(addEntityCollection(new EntityCollection<Appointment>(this, "appointment")));
    contact = static_cast<EntityCollection<Contact>*>(addEntityCollection(new EntityCollection<Contact>(this, "contact")));
    setPrimaryKey(referrence);
}

Client::Client(QObject* parent, const QJsonObject& jsonObj)
    :Client(parent)
{
    update(jsonObj);
}

QQmlListProperty<Appointment> Client::ui_appointment()
{
    return QQmlListProperty<Appointment>(this, appointment->deriveEntities());
}

QQmlListProperty<Contact> Client::ui_contact()
{
    return QQmlListProperty<Contact>(this, contact->deriveEntities());
}

}}
