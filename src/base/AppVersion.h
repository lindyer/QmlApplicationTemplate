#ifndef APPVERSION_H
#define APPVERSION_H

#include "MacroHelper.h"

#include <QObject>

class AppVersion : public QObject
{
    Q_OBJECT
    SINGLETON(AppVersion)
public:
    enum Stage {
        Alpha,
        Beta,
        RC,
        Release,
    };
    enum Category {
        Community,
        Commercial,
    };

public Q_SLOTS:
    static QString versionDescription() ;
    static void setVersion(uint major,uint minor,uint revision,Stage stage,Category category = Community);
    static QString stageDescription(Stage stage);

private:

private:
    static uint _major;
    static uint _minor;
    static uint _revision;
    static Stage _stage;
    static Category _category;
};

#endif // APPVERSION_H
