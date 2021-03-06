QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#CODECOV_TOKEN='02da3399-aa54-4478-8717-724733a57f72'

SOURCES += \
    colorconverter.cpp \
    colorpalettelist.cpp \
    dmccolorpalette.cpp \
    dmcfloss.cpp \
    handleitem.cpp \
    main.cpp \
    mainwindow.cpp \
    projectcanvas.cpp \
    resizableaidagraphitem.cpp \
    resizablehandlerect.cpp \
    resizablepixmapitem.cpp \
    view.cpp

HEADERS += \
    colorconverter.h \
    colorpalettelist.h \
    dmccolorpalette.h \
    dmcfloss.h \
    handleitem.h \
    mainwindow.h \
    projectcanvas.h \
    resizableaidagraphitem.h \
    resizablehandlerect.h \
    resizablepixmapitem.h \
    view.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
