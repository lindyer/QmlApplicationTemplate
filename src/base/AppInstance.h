#ifndef APPINSTANCE_H
#define APPINSTANCE_H

#include "MacroHelper.h"
#include "WindowManager.h"

//auto select base application type
#ifdef QT_WIDGETS_LIB
#include <QApplication>
#else
#include <QGuiApplication>
#endif

#include <QQmlApplicationEngine>
#include <functional>

#ifdef QT_WIDGETS_LIB
    using AppType = QApplication;
#else
    using AppType = QGuiApplication;
#endif

class AppInstance
{
    SINGLETON_IDLER(AppInstance)
public:
    static std::function<void(AppType &,WindowManager &)> initFn;
    static int run(int argc,char *argv[]);
private:

};

#endif // APPINSTANCE_H
