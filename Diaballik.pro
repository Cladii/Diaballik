TEMPLATE = app
CONFIG -= app_bundle
#CONFIG -= qt
CONFIG += console
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -pedantic-errors\
-std=c++17

DEFINES += QT_DEPRECATED_WARNINGS

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SOURCES += \
        model/board.cpp \
        controller/controller.cpp \
        model/game.cpp \
        main.cpp \
        observer/observable.cpp \
        view/formulaire.cpp \
        view/infoPlay.cpp \
        view/infosTurn.cpp \
        view/mainWindow.cpp \
        view/square.cpp \
        view/view.cpp \
        view/viewApplication.cpp \
        view/viewBoard.cpp

HEADERS += \
    controller/controller.h \
    model/action.h \
    model/board.h \
    model/direction.h \
    model/game.h \
    model/piece.h \
    model/player.h \
    model/playerColor.h \
    model/position.h \
    observer/observable.h \
    observer/observer.h \
    view/formulaire.h \
    view/infoPlay.h \
    view/infosTurn.h \
    view/mainWindow.h \
    view/square.h \
    view/view.h \
    view/viewApplication.h \
    view/viewBoard.h

RESOURCES += \
    ressources/pictures.qrc
