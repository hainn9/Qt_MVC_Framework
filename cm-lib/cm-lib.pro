QT -= gui
QT += sql

TEMPLATE = lib
DEFINES += CMLIB_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

INCLUDEPATH += source

SOURCES += \
    source/controllers/commandcontroller.cpp \
    source/controllers/databasecontroller.cpp \
    source/controllers/mastercontroller.cpp \
    source/data/datadecorator.cpp \
    source/data/datetimedecorator.cpp \
    source/data/entity.cpp \
    source/data/enumdecorator.cpp \
    source/data/intdecorator.cpp \
    source/data/stringdecorator.cpp \
    source/framework/command.cpp \
    source/framework/objectfactory.cpp \
    source/model/address.cpp \
    source/model/appointment.cpp \
    source/model/client.cpp \
    source/model/clientsearch.cpp \
    source/model/contact.cpp

HEADERS += \
    source/cm-lib_global.h \
    source/controllers/commandcontroller.h \
    source/controllers/databasecontroller.h \
    source/controllers/icommandcontroller.h \
    source/controllers/idatabasecontroller.h \
    source/controllers/inavigationcontroller.h \
    source/controllers/mastercontroller.h \
    source/controllers/navigationcontroller.h \
    source/data/datadecorator.h \
    source/data/datetimedecorator.h \
    source/data/entity.h \
    source/data/entitycollection.h \
    source/data/enumdecorator.h \
    source/data/intdecorator.h \
    source/data/stringdecorator.h \
    source/framework/command.h \
    source/framework/iobjectfactory.h \
    source/framework/objectfactory.h \
    source/model/address.h \
    source/model/appointment.h \
    source/model/client.h \
    source/model/clientsearch.h \
    source/model/contact.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
