#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <cm-lib_global.h>
#include <data/entity.h>
#include <data/stringdecorator.h>
#include <data/datetimedecorator.h>

namespace cm {
namespace models {


class CMLIB_EXPORT Appointment : public  data::Entity
{
    Q_OBJECT
    Q_PROPERTY(cm::data::DateTimeDecorator* ui_startAt MEMBER startAt CONSTANT)
    Q_PROPERTY(cm::data::DateTimeDecorator* ui_endAt MEMBER endAt CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_note MEMBER note CONSTANT)
public:
    Appointment(QObject* parent = nullptr);
    Appointment(QObject* parent, const QJsonObject& jsonObj);

    ~Appointment() {}

    data::DateTimeDecorator* startAt{nullptr};
    data::DateTimeDecorator* endAt{nullptr};
    data::StringDecorator* note{nullptr};
};

}
}

#endif // APPOINTMENT_H
