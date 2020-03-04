QT -= gui

unix{
  LIBS    += -lcrypto -lssl
  DEFINES += unix
}

TEMPLATE = lib
DEFINES += SYMMETRICCIPHERS_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0s

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/SymmetricCiphers_global.h \
    src/aescrypt.h \
    src/blowfishcrypt.h \
    src/cryptclassbase.h \
    src/key.h \
    src/tripledescrypt.h \
    src/utility.h

SOURCES += \
    src/aescrypt.cpp \
    src/blowfishcrypt.cpp \
    src/cryptclassbase.cpp \
    src/key.cpp \
    src/tripledescrypt.cpp \
    src/utility.cpp
