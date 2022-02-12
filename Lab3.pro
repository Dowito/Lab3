TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Auxiliar.cpp \
        main.cpp \
        manejoArchivo.cpp

DISTFILES += \
    Data_base/M1S6.dat \
    Data_base/M1S6.txt \
    Data_base/M2S17.dat \
    Data_base/M2S17.txt \
    Data_base/codificado.dat \
    Data_base/natural.txt

HEADERS += \
    Auxiliar.h \
    manejoArchivo.h
