#include "dynamicQMLWindow.h"



DynamicQMLWindow::DynamicQMLWindow(QObject* parent) : QObject(parent)
{
    QObject::connect(this, SIGNAL(askReload()), this, SLOT(reloadQml()));
    _mview = new QQuickView();
    _mengine = _mview->engine();
    _mdirsToMonitor = QStringList(".");
}

DynamicQMLWindow::DynamicQMLWindow(QQuickView *view) :
    _mview(view), _mdirsToMonitor(QStringList("."))
{
    QObject::connect(this, SIGNAL(askReload()), this, SLOT(reloadQml()));
    _mengine = _mview->engine();

    startMonitoring();
}

DynamicQMLWindow::~DynamicQMLWindow()
{

}

void DynamicQMLWindow::show()
{
    _mview->show();
}

void DynamicQMLWindow::startMonitoring()
{
    _mwatcher = new QFileSystemWatcher();
    _mwatcher->addPaths(_mdirsToMonitor);

    QObject::connect(_mwatcher, SIGNAL(directoryChanged(const QString&)), this, SLOT(reloadQml()) );
}

void DynamicQMLWindow::setViewSource(QUrl &source)
{
    _mengine = _mview->engine();
    _mengine->clearComponentCache();
    _mview->setSource(source);
}

void DynamicQMLWindow::reloadQml()
{
    QUrl tmp = _mview->source(); //we save current source
    _mview->setSource(QUrl()); //we set an empty source

    setViewSource(tmp); //we load old source

    startMonitoring();
}

