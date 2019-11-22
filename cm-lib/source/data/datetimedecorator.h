#ifndef DATETIMEDECORATOR_H
#define DATETIMEDECORATOR_H


#include "datadecorator.h"
#include <QDateTime>

namespace cm {
namespace data {

class CMLIB_EXPORT DateTimeDecorator : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(QDateTime value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString ui_isoString READ toIsoString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyDateString READ toPrettyDateString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyTimeString READ toPrettyTimeString NOTIFY valueChanged)
    Q_PROPERTY(QString ui_prettyString READ toPrettyString NOTIFY valueChanged)
public:
    explicit DateTimeDecorator(Entity *parent = nullptr, const QString& key = "ItemKey", const QString& label = "", const QDateTime& value = QDateTime::currentDateTime());
    ~DateTimeDecorator();

    DateTimeDecorator& setValue(const QDateTime& value);
    const QDateTime& value() const;

    QString toIsoString() const;
    QString toPrettyDateString() const;
    QString toPrettyTimeString() const;
    QString toPrettyString() const;

    QJsonValue jsonValue() const override;
    void update(const QJsonObject &jsonObj) override;

signals:
    void valueChanged();

public slots:

private:
    class DateTimeDecoratorPrivate;
    QScopedPointer<DateTimeDecoratorPrivate> datetimeDecorator_priv;
};

}}

#endif // DATETIMEDECORATOR_H
