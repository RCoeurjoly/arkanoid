SOURCES += \
    main.cpp \
    obj_dib.cpp \
    pared.cpp \
    ladrillo.cpp \
    pelota.cpp \
    nave.cpp \
    misil.cpp

HEADERS += \
    obj_dib.h \
    pared.h \
    ladrillo.h \
    pelota.h \
    nave.h \
    misil.h

CONFIG += console
QT += opengl
LIBS += -lglut -lGL -lGLU
