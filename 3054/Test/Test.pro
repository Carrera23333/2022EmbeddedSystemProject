#QT += core
#QT -= gui

CONFIG += c++11

TARGET = Test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp



# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#LIBS += -L/home/m/hitbot/build-small_scara_interface-Desktop_Qt_5_8_0_GCC_64bit-Release -lsmall_scara_interface
LIBS += -L/home/carrera/jixeibiQT/Test/hitbot_lib

HEADERS += \
    ControlBeanEx.h \
    hitbot_interface.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/hitbot_lib/release/ -lsmall_scara_interface
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/hitbot_lib/debug/ -lsmall_scara_interface
else:unix: LIBS += -L$$PWD/hitbot_lib/ -lsmall_scara_interface

INCLUDEPATH += $$PWD/hitbot_lib
DEPENDPATH += $$PWD/hitbot_lib
