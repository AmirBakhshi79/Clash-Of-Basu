TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    game.cpp \
    state.cpp \
    gamestate.cpp \
    entity.cpp \
    mainmenu.cpp \
    button.cpp \
    giant.cpp \
    tile.cpp \
    heroabstractclass.cpp \
    snipper.cpp \
    drmarry.cpp \
    commander.cpp \
    mrsghost.cpp \
    alphaman.cpp \
    kratos.cpp \
    leon.cpp \
    robi.cpp \
    professor.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib/release/ -lsfml-graphics
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib/debug/ -lsfml-graphics
else:unix: LIBS += -L$$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib/ -lsfml-graphics

INCLUDEPATH += $$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib
DEPENDPATH += $$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib/release/ -lsfml-system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib/debug/ -lsfml-system
else:unix: LIBS += -L$$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib/ -lsfml-system

INCLUDEPATH += $$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/include
DEPENDPATH += $$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib/release/ -lsfml-window
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib/debug/ -lsfml-window
else:unix: LIBS += -L$$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/lib/ -lsfml-window

INCLUDEPATH += $$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/include
DEPENDPATH += $$PWD/../../../../../home/bakhshi/Downloads/SFML-2.5.1-Compiled/include

HEADERS += \
    game.h \
    state.h \
    state.h \
    gamestate.h \
    entity.h \
    mainmenu.h \
    button.h \
    giant.h \
    tile.h \
    heroabstractclass.h \
    snipper.h \
    drmarry.h \
    commander.h \
    mrsghost.h \
    alphaman.h \
    kratos.h \
    leon.h \
    robi.h \
    professor.h
