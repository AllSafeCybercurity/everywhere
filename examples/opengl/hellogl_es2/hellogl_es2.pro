######################################################################
# Automatically generated by qmake (2.01a) Thu Oct 4 19:01:12 2007
######################################################################

TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

# Input
SOURCES += main.cpp
SOURCES += glwidget.cpp
SOURCES += mainwindow.cpp
SOURCES += bubble.cpp

HEADERS += glwidget.h
HEADERS += mainwindow.h
HEADERS += bubble.h

RESOURCES += texture.qrc
QT += opengl

# install
target.path = $$[QT_INSTALL_EXAMPLES]/opengl/hellogl_es2
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS hellogl_es2.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/opengl/hellogl_es2
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)

maemo5 {
    # Debian package name may not contain numbers or special characters
    # such as '_', lets change this in Maemo.
    TARGET = helloglestwo
    include($$QT_SOURCE_TREE/examples/maemo5pkgrules.pri)
}

symbian: warning(This example might not fully work on Symbian platform)
simulator: warning(This example might not fully work on Simulator platform)
