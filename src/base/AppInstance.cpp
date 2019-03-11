#include "AppInstance.h"
#include "WindowManager.h"


std::function<void(AppType &,WindowManager &)> AppInstance::initFn;
AppInstance::AppInstance() {

}

AppInstance::~AppInstance() {

}

int AppInstance::run(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#ifdef QT_WIDGETS_LIB
    QApplication app(argc,argv);
#else
    QGuiApplication app(argc,argv);
#endif
    WindowManager &wm = WindowManager::instance();

    if(initFn) {
        initFn(app, wm);
    }

    return app.exec();
}
