TEMPLATE = app
TARGET = player

QT += network \
      xml \
      multimedia \
      multimediawidgets \
      widgets

HEADERS = \
    player.h \
    playlistmodel.h \
    histogramwidget.h \
    bodypart.h \
    info.h
SOURCES = main.cpp \
    player.cpp \
    playlistmodel.cpp \
    histogramwidget.cpp \
    bodypart.cpp \
    info.cpp

maemo* {
    DEFINES += PLAYER_NO_COLOROPTIONS
}

target.path = $$[QT_INSTALL_EXAMPLES]/multimediawidgets/player
INSTALLS += target
