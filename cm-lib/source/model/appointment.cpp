#include "appointment.h"

using namespace cm::data;

namespace cm {
namespace models {

Appointment::Appointment(QObject* parent)
    :Entity(parent, "appointment")
{
    startAt = static_cast<DateTimeDecorator*>(addDataDecorator(new DateTimeDecorator(this, "startAt", "Start At")));
    endAt = static_cast<DateTimeDecorator*>(addDataDecorator(new DateTimeDecorator(this, "endAt", "End At")));
    note = static_cast<StringDecorator*>(addDataDecorator(new StringDecorator(this, "note", "Note")));
}

Appointment::Appointment(QObject* parent, const QJsonObject& jsonObj)
    :Appointment(parent)
{
    update(jsonObj);
}

}
}
