#include "contact.h"

using namespace cm::data;

namespace cm {
namespace models {

Contact::Contact(QObject* parent)
    :Entity(parent, "contact"),
      m_contactTypeMapper(std::map<int, QString>{
                            { eContactType::Unknown, "" }
                          , { eContactType::Telephone, "Telephone" }
                          , { eContactType::Email, "Email" }
                          , { eContactType::Fax, "Fax" }
                            })
{
    contactType = static_cast<EnumDecorator*>(addDataDecorator(new EnumDecorator(this, "contactType", "Contact Type", 0, m_contactTypeMapper)));
}

Contact::Contact(QObject* parent, const QJsonObject& jsonObj)
    :Contact(parent)
{
    update(jsonObj);
}

}
}
