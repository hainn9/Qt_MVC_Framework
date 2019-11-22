#ifndef CLIENT_H
#define CLIENT_H

#include <cm-lib_global.h>
#include <data/entity.h>
#include <data/entitycollection.h>
#include <data/stringdecorator.h>
#include <model/address.h>
#include <model/appointment.h>
#include <model/contact.h>

#include <QObject>
#include <QtQml/QQmlListProperty>

namespace cm {
namespace models {

class CMLIB_EXPORT Client : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY(cm::data::StringDecorator* ui_referrence MEMBER referrence CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_name MEMBER name CONSTANT)
    Q_PROPERTY(cm::models::Address* ui_supplyAddress MEMBER supplyAddress CONSTANT)
    Q_PROPERTY(cm::models::Address* ui_billingAddress MEMBER billingAddress CONSTANT)
    Q_PROPERTY(QQmlListProperty<cm::models::Appointment> ui_appointment READ ui_appointment NOTIFY appointmentChanged)
    Q_PROPERTY(QQmlListProperty<cm::models::Contact> ui_contact READ ui_contact NOTIFY contactChanged)
public:
    Client(QObject* parent = nullptr);
    Client(QObject* parent, const QJsonObject& jsonObj);

    ~Client() {}

    data::StringDecorator* referrence{nullptr};
    data::StringDecorator* name{nullptr};
    Address* supplyAddress{nullptr};
    Address* billingAddress{nullptr};
    data::EntityCollection<cm::models::Appointment>* appointment{nullptr};
    data::EntityCollection<cm::models::Contact>* contact{nullptr};

    QQmlListProperty<Appointment> ui_appointment();
    QQmlListProperty<Contact> ui_contact();
signals:
    void appointmentChanged();
    void contactChanged();
};

}}

#endif // CLIENT_H
