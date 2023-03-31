QT       += core gui texttospeech

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    csvclass.cpp \
    main.cpp \
    mainwindow.cpp \
    randthread.cpp

HEADERS += \
    csvclass.h \
    mainwindow.h \
    randthread.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    lottery_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Icon.qrc

RC_ICONS = Icon\dog.ico
TARGET = lottery