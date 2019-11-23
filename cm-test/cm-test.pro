QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

#TEMPLATE = app

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

INCLUDEPATH += source \
    ../cm-lib/source

SOURCES +=  \
    source/main.cpp \
    source/model/tst_clienttest.cpp \
    source/testsuite.cpp

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib

HEADERS += \
    source/testsuite.h
