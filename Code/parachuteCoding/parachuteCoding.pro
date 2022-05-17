QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ParachuteView.cpp \
    main.cpp \
    mainwindow.cpp \
    MessageModel.cpp \
    BinaryViewWidget.cpp

HEADERS += \
    ParachuteView.h \
    mainwindow.h \
    MessageModel.h \
    BinaryViewWidget.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    parachuteCoding_fr_BE.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
