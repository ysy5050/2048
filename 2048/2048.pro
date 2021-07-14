QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    App/app.cpp \
    Model/model.cpp \
    View/commandsink.cpp \
    View/propertysink.cpp \
    View/view.cpp \
    ViewModel/layoutcommand.cpp \
    ViewModel/movecommand.cpp \
    ViewModel/viewmodel.cpp \
    ViewModel/viewmodelsink.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    App/app.h \
    Common/Command.h \
    Common/square.h \
    Model/model.h \
    View/commandsink.h \
    View/propertysink.h \
    View/view.h \
    ViewModel/layoutcommand.h \
    ViewModel/movecommand.h \
    ViewModel/viewmodel.h \
    ViewModel/viewmodelsink.h \
    command.h \
    mainwindow.h

FORMS += \
    View/view.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
