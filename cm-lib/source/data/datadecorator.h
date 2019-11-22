#ifndef DATADECORATOR_H
#define DATADECORATOR_H

#include <QObject>
#include <QScopedPointer>
#include <QJsonObject>
#include <QJsonValue>
#include <QString>
#include <cm-lib_global.h>

namespace cm {
namespace data {

class Entity;

class CMLIB_EXPORT DataDecorator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label CONSTANT)
public:
    explicit DataDecorator(Entity *parent = nullptr, const QString& key = "ItemKey", const QString& label = "");
    virtual ~DataDecorator();

    const QString& key() const;
    const QString& label() const;
    Entity* parentEntity();

    virtual QJsonValue jsonValue() const = 0;
    virtual void update(const QJsonObject& jsonObj) = 0;
signals:

public slots:

private:
    class DataDecoratorPrivate;
    QScopedPointer<DataDecoratorPrivate> dataDecorator_priv;
};

}}
#endif // DATADECORATOR_H
