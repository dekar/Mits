QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/clirunner.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mitshpacket.cpp \
    src/packetsender.cpp

HEADERS += \
    src/clirunner.h \
    src/mainwindow.h \
    src/mitshpacket.h \
    src/packetsender.h

FORMS += \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

UI_DIR = build/moc
OBJECTS_DIR = build/obj
DESTDIR = build/bin
MOC_DIR = build/moc
