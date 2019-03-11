#include "WindowManager.h"

WindowManager::WindowManager()
{
    rootContext()->setContextProperty("WindowManager",this);
}

WindowManager::~WindowManager(){

}

void WindowManager::push(const QUrl &url)
{
    load(url);
}

void WindowManager::pop()
{
    QList<QObject*> objects = rootObjects();
    if(objects.empty()) {
        return;
    }
    objects.last()->deleteLater();
}

void WindowManager::replace(const QUrl &url)
{
    pop();
    push(url);
}
