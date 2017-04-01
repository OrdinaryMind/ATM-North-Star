TEMPLATE = lib
TARGET = lib_console_output
CONFIG = staticlib

QMAKE_CXXFLAGS += -std=c++11

QMAKE_CXX = ccache g++


INCLUDEPATH += \
    $$PWD/messengers \
    $$PWD/output_configuration \

HEADERS += \
    $$PWD/messengers/*.h \
    $$PWD/output_configuration/*.h \

SOURCES += \
    $$PWD/messengers/*.cpp \
    $$PWD/output_configuration/*.cpp \


