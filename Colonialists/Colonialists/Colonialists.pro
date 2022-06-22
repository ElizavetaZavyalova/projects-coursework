QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cards.cpp \
    dialog.cpp \
    game2_newPress.cpp \
    game3_newPaint.cpp \
    game_new.butons.cpp \
    game_newActions.cpp \
    game_newInit.cpp \
    game_newbot.cpp \
    hex.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    road.cpp \
    save.cpp \
    settings.cpp \
    town.cpp \
    trader_and_help.cpp

HEADERS += \
    dialog.h \
    game_new.h \
    game_objects.h \
    mainwindow.h \
    settings.h \
    trader_and_help.h

FORMS += \
    dialog.ui \
    game_new.ui \
    mainwindow.ui \
    settings.ui

TRANSLATIONS += \
    Colonialists_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    C:/Users/HONOR/OneDrive/Изображения/колонизаторы/Песок.jpg \
    Save.txt \
    res/1.png \
    res/2.png \
    res/3.png \
    res/4.png \
    res/5.png \
    res/6.png \
    res/cards/bigest_army.png \
    res/cards/c.png \
    res/cards/g.png \
    res/cards/i.png \
    res/cards/k.png \
    res/cards/l.png \
    res/cards/long_roud.png \
    res/cards/m.png \
    res/cards/r.png \
    res/cards/t.png \
    res/cards/u.png \
    res/cube/1.png \
    res/cube/2.png \
    res/cube/3.png \
    res/cube/4.png \
    res/cube/5.png \
    res/cube/6.png \
    res/hex/clay.png \
    res/hex/fief_M.png \
    res/hex/millet.png \
    res/hex/shipbe.png \
    res/hex/stone.png \
    res/hex/tree.png \
    res/icons/clay.png \
    res/icons/cost.png \
    res/icons/fon.jpg \
    res/icons/i1.png \
    res/icons/k1.png \
    res/icons/knite.png \
    res/icons/m1.png \
    res/icons/map.jpg \
    res/icons/milet.png \
    res/icons/r1.png \
    res/icons/shipbe.png \
    res/icons/stone.png \
    res/icons/tree.png \
    res/ships/screne_new.png \
    res/ships/ship21clay.png \
    res/ships/ship21millet.png \
    res/ships/ship21ship.png \
    res/ships/ship21stown.png \
    res/ships/ship21tree.png \
    res/ships/ship31.png \
    res/ships/ship41.png \
    res/towns/house1Red.png \
    res/towns/house1White.png \
    res/towns/house1Yellow.png \
    res/towns/house1blue.png \
    res/towns/house2Red.png \
    res/towns/house2Yellow.png \
    res/towns/house2blue.png \
    res/towns/house2white.png \
    res/towns/roudblue.jpg \
    res/towns/roudred.jpg \
    res/towns/roudwhite.jpg \
    res/towns/roudyellow.jpg \
    res/Без имени.png

RESOURCES += \
    ToolBarspicture.qrc
