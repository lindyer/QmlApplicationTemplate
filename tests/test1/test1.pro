QT += quick
CONFIG += c++11
TEMPLATE = app
TARGET = QmlApplicationTemplateTest

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp \
    Email.cpp

include(../../src/base/AppBase.pri)
INCLUDEPATH += ../../src/base

RESOURCES += qml.qrc


HEADERS += \
    Email.h

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =
