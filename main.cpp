#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QCursor>

#include "datamodel.h"



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // QGuiApplication::setOverrideCursor(QCursor(Qt::BlankCursor));

    qmlRegisterUncreatableType<DataModel>("com.druck.models", 1, 0, "DataModel", "DataModel is uncreatable type");

    // declare data model objects
    DataModel model1, model2;

    // initialise models
    model1.setSalary(10000);
    model2.setSalary(20000);

    QQmlApplicationEngine engine;

    // make data models visible to QML
    engine.rootContext()->setContextProperty("TheModelOne", &model1);
    engine.rootContext()->setContextProperty("TheModelTwo", &model2);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
