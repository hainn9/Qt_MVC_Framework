#ifndef ADDRESS_H
#define ADDRESS_H

#include <cm-lib_global.h>
#include "data/entity.h"
#include "data/stringdecorator.h"

namespace cm {
namespace models {
class CMLIB_EXPORT Address : public data::Entity
{
    Q_OBJECT
    Q_PROPERTY(cm::data::StringDecorator* ui_building MEMBER building CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_street MEMBER street CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_city MEMBER city CONSTANT)
    Q_PROPERTY(cm::data::StringDecorator* ui_postcode MEMBER postcode CONSTANT)
    Q_PROPERTY(QString fullAddress READ fullAddress CONSTANT)
public:
    Address(QObject* parent = nullptr);
    Address(QObject* parent, const QJsonObject& jsonObj);

    ~Address() {}

    data::StringDecorator* building{nullptr};
    data::StringDecorator* street{nullptr};
    data::StringDecorator* city{nullptr};
    data::StringDecorator* postcode{nullptr};

    QString fullAddress() const;
};

}}

#endif // ADDRESS_H
