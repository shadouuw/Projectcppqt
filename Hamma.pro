QT       += core gui
QT       += core gui charts
QT       += core network
QT += printsupport
QT += network
QT  +=sql

LIBS += -LC:/OpenSSL-Win64/bin

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG(debug, debug|release){
    DEFINES += DEBUG_LOGOUT_ON
    message("Debug Build")
}

CONFIG(release, debug|release){
    message("Release Build")
}
# The following define makes your compiler   emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abonnement.cpp \
    conexion.cpp \
    departement.cpp \
    don.cpp \
    donneur.cpp \
    email.cpp \
    equipe.cpp \
    equipement.cpp \
    evenement.cpp \
    generator/qrcode_generator.cpp \
    joueur.cpp \
    main.cpp \
    mainwindow.cpp \
    match.cpp \
    personnel.cpp \
    smtp.cpp \
    stats.cpp \
    ticket.cpp \
    tournoi.cpp


HEADERS += \
    abonnement.h \
    conexion.h \
    departement.h \
    don.h \
    donneur.h \
    email.h \
    equipe.h \
    equipement.h \
    evenement.h \
    generator/qrcode_generator.h \
    joueur.h \
    libs_inc/qrencode.h \
    mainwindow.h \
    match.h \
    personnel.h \
    smtp.h \
    stats.h \
    ticket.h \
    tournoi.h

FORMS += \
    dialog.ui \
    email.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    img.qrc \
    translations.qrc

DISTFILES += \
    generator/qrencode.dll


INCLUDEPATH += libs_inc \
        generator

linux-g++-64 {
    LIBS += -L../libs/linux/x64/
    LIBS += -lqrencode
}
win32-msvc {
    contains(TARGET_ARCH, x86_64) {
        ARCHITECTURE = x64
        LIBS += -L../libs/win/x64/
    } else {
        ARCHITECTURE = x86
        LIBS += -L../libs/win/x86/
    }
    message("ARCHITECTURE="$$ARCHITECTURE)
}



