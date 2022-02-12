TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        manejoArchivo.cpp

DISTFILES += \
    Data_base/codificado.dat \
    Data_base/natural.txt

HEADERS += \
    manejoArchivo.h
