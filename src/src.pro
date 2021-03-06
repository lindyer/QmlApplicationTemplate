QT += quick
CONFIG += c++11 warn_on
TEMPLATE = app
TARGET = AppName

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp

include(base/AppBase.pri)
INCLUDEPATH += base

#RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = $$PWD/plugins

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

