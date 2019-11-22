#ifndef CONTACT_H
#define CONTACT_H

#include <cm-lib_global.h>
#include <data/entity.h>
#include <data/enumdecorator.h>

namespace cm {
namespace models {

enum eContactType {
    Unknown = 0,
    Telephone,
    Email,
    Fax
};

class CMLIB_EXPORT Contact : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY(cm::data::EnumDecorator* ui_contactType MEMBER contactType CONSTANT)
public:
    Contact(QObject* parent = nullptr);
    Contact(QObject* parent, const QJsonObject& jsonObj);

    ~Contact() {}

    data::EnumDecorator* contactType{nullptr};

private:
    std::map<int, QString> m_contactTypeMapper;
};

}
}

#endif // CONTACT_H
