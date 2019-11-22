#include "command.h"
namespace cm {
namespace framework {
class Command::CommandPrivate
{
public:
    CommandPrivate(const QString& pIconCharacter, const QString& pDescription, std::function<bool()> pCanExecute)
        :iconCharacter(pIconCharacter),
          description(pDescription),
          canExecute(pCanExecute)
    {}

    QString iconCharacter;
    QString description;
    std::function<bool()> canExecute;
};

Command::Command(QObject* parent, const QString& pIconCharacter, const QString& pDescription, std::function<bool()>pCanExecute)
    :QObject(parent)
{
    command_priv.reset(new CommandPrivate(pIconCharacter, pDescription, pCanExecute));
}

Command::~Command()
{

}

const QString& Command::iconCharacter() const
{
    return command_priv->iconCharacter;
}

const QString& Command::description() const
{
    return command_priv->description;
}

bool Command::canExecute() const
{
    return command_priv->canExecute();
}

}}
