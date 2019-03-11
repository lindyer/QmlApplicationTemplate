#include "AppVersion.h"

#include <QCoreApplication>
#include <QFileInfo>
#include <QDate>

uint AppVersion::_major = 0;
uint AppVersion::_minor = 0;
uint AppVersion::_revision = 0;
AppVersion::Stage AppVersion::_stage = AppVersion::Alpha;
AppVersion::Category AppVersion::_category = AppVersion::Community;

AppVersion::AppVersion()
{

}

AppVersion::~AppVersion()
{

}

QString AppVersion::versionDescription()
{
    QFileInfo info(qApp->applicationFilePath());
    QString buildDate = info.lastModified().toString("yyMMdd");
    return QString("%1.%2.%3.%4_%5").arg(_major).arg(_minor).arg(_revision).arg(buildDate).arg(stageDescription(_stage));
}

void AppVersion::setVersion(uint major, uint minor, uint revision, AppVersion::Stage stage,Category category)
{
    _major = major;
    _minor = minor;
    _revision = revision;
    _stage = stage;
    _category = category;
}

QString AppVersion::stageDescription(AppVersion::Stage stage)
{
    switch (stage) {
    case Alpha: return "Alpha";
    case Beta: return "Beta";
    case RC: return "RC";
    case Release: return "Release";
    }
    return QString();
}
