#ifndef ENUMERATEDECORATOR_H
#define ENUMERATEDECORATOR_H

#include "datadecorator.h"
#include <map>

namespace cm {
namespace data {

class CMLIB_EXPORT EnumDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(int value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString ui_valueDescription READ valueDescription NOTIFY valueChanged)
public:
    explicit EnumDecorator(Entity *parent = nullptr, const QString& key = "ItemKey", const QString& label = "",
                           const int& value = 0, const std::map<int, QString>& pDescriptionMapper = std::map<int, QString>());
    ~EnumDecorator();

    EnumDecorator& setValue(const int& value);
    const int& value() const;

    QString valueDescription() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject &jsonObj) override;

signals:
    void valueChanged();

public slots:

private:
    class EnumDecoratorPrivate;
    QScopedPointer<EnumDecoratorPrivate> enumDecorator_priv;
};

}}

#endif // ENUMERATEDECORATOR_H
