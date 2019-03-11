#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include "MacroHelper.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QUrl>

class WindowManager : public QQmlApplicationEngine
{
    Q_OBJECT
    SINGLETON_IDLER(WindowManager)

Q_SIGNALS:

public Q_SLOTS:
    void push(const QUrl &url);
    void pop();
    void replace(const QUrl &url);
};

#endif // WINDOWMANAGER_H
