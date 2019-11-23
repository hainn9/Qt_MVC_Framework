#ifndef INTDECORATOR_H
#define INTDECORATOR_H


#include "datadecorator.h"

namespace cm {
namespace data {

class CMLIB_EXPORT IntDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(int ui_value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit IntDecorator(Entity *parent = nullptr, const QString& key = "ItemKey", const QString& label = "", const int& value = 0);
    ~IntDecorator();

    IntDecorator& setValue(const int& value);
    const int& value() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject &jsonObj) override;

signals:
    void valueChanged();

public slots:

private:
    class IntDecoratorPrivate;
    QScopedPointer<IntDecoratorPrivate> intDecorator_priv;
};

}}

#endif // INTDECORATOR_H
