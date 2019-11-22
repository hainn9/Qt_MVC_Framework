#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include <QScopedPointer>
#include <QString>
#include <cm-lib_global.h>
#include <functional>

namespace cm {
namespace framework {

class CMLIB_EXPORT Command : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_iconCharacter READ iconCharacter CONSTANT)
    Q_PROPERTY(QString ui_description READ description CONSTANT)
    Q_PROPERTY(bool ui_canExecute READ canExecute NOTIFY canExecuteChanged)
public:
    explicit Command(QObject *parent = nullptr,
                     const QString& pIconCharacter = "",
                     const QString& pDescription = "",
                     std::function<bool()>pCanExecute = [](){ return true; });
    ~Command();

    const QString& iconCharacter() const;
    const QString& description() const;
    bool canExecute() const;

signals:
    void canExecuteChanged();
    void executed();

public slots:

private:
    class CommandPrivate;
    QScopedPointer<CommandPrivate> command_priv;
};

}}
#endif // COMMAND_H
