#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QCursor>
#include <QList>

#include "datamodel.h"
#include "datalist.h"



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // hide cursor for touch app
    // QGuiApplication::setOverrideCursor(QCursor(Qt::BlankCursor));

    qmlRegisterUncreatableType<DataModel>("com.druck.models", 1, 0, "DataModel", "DataModel is uncreatable type");
    qmlRegisterUncreatableType<DataList>("com.druck.models", 1, 0, "DataList", "DataList is uncreatable type");

    // declare data model objects
    // QList<DataModel*> dataList;
    DataList dataList;
    DataModel *model;

    model = new DataModel();
    model->setSalary(10000);
    dataList.add(model);

    model = new DataModel();
    model->setSalary(20000);
    dataList.add(model);

    // DataModel model1, model2;

    // initialise models
    //model1.setSalary(10000);
    // model2.setSalary(20000);


    // dataList.data.s ().    .s)->setSalary(10000);
    // dataList.data().at(1)->setSalary(20000);

    QQmlApplicationEngine engine;

    // make data models visible to QML
//    engine.rootContext()->setContextProperty("TheModelOne", &model1);
//    engine.rootContext()->setContextProperty("TheModelTwo", &model2);
//    engine.rootContext()->setContextProperty("TheModelOne", dataList[0]);
//    engine.rootContext()->setContextProperty("TheModelTwo", dataList[1]);
    engine.rootContext()->setContextProperty("TheDataList", &dataList);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
