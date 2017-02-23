#include <QApplication>
#include <QQuickView>
#include <QDebug>
#include <dynamicQMLWindow.h>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQuickView *view = new QQuickView();

    QString mainQmlFile("main.qml");

    //instantiate dynamic qml object
    DynamicQMLWindow* dqw = new DynamicQMLWindow(view);
    dqw->_mview->setMinimumWidth(640);
    dqw->_mview->setMinimumHeight(480);

    //set source file to the view and show it
    dqw->_mview->setSource(QUrl::fromLocalFile(mainQmlFile));
    dqw->show();

    return app.exec();
}

