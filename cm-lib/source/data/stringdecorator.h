#ifndef STRINGDECORATOR_H
#define STRINGDECORATOR_H

#include "datadecorator.h"

namespace cm {
namespace data {

class CMLIB_EXPORT StringDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)
public:
    explicit StringDecorator(Entity *parent = nullptr, const QString& key = "ItemKey", const QString& label = "", const QString& value = "");
    ~StringDecorator();

    StringDecorator& setValue(const QString& value);
    const QString& value() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject &jsonObj) override;

signals:
    void valueChanged();

public slots:

private:
    class StringDecoratorPrivate;
    QScopedPointer<StringDecoratorPrivate> stringDecorator_priv;
};

}}

#endif // STRINGDECORATOR_H
