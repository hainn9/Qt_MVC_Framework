#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <controllers/mastercontroller.h>
#include <data/stringdecorator.h>
#include <data/intdecorator.h>
#include <data/enumdecorator.h>
#include <data/datetimedecorator.h>
#include <model/client.h>
#include <model/address.h>
#include <model/appointment.h>
#include <model/contact.h>
#include <model/clientsearch.h>
#include <framework/objectfactory.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<cm::controllers::MasterController>("CM", 1, 0, "MasterController");
    qmlRegisterUncreatableType<cm::controllers::INavigationController>("CM", 1, 0, "INavigationController", "Interafce");
    qmlRegisterUncreatableType<cm::controllers::ICommandController>("CM", 1, 0, "ICommandController", "Interface");
    qmlRegisterType<cm::framework::Command>("CM", 1, 0, "Command");
    qmlRegisterType<cm::data::StringDecorator>("CM", 1, 0, "StringDecorator");
    qmlRegisterType<cm::data::IntDecorator>("CM", 1, 0, "IntDecorator");
    qmlRegisterType<cm::data::EnumDecorator>("CM", 1, 0, "EnumDecorator");
    qmlRegisterType<cm::data::DateTimeDecorator>("CM", 1, 0, "DateTimeDecorator");
    qmlRegisterType<cm::models::Address>("CM", 1, 0, "Address");
    qmlRegisterType<cm::models::Appointment>("CM", 1, 0, "Appointment");
    qmlRegisterType<cm::models::Client>("CM", 1, 0, "Client");
    qmlRegisterType<cm::models::ClientSearch>("CM", 1, 0, "ClientSearch");
    qmlRegisterType<cm::models::Contact>("CM", 1, 0, "Contact");
    cm::framework::ObjectFactory objectFactory;
    cm::controllers::MasterController masterController(nullptr, &objectFactory);

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("masterController", &masterController);

    const QUrl url(QStringLiteral("qrc:/view/MasterView.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
