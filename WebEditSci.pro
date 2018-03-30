#-------------------------------------------------
#
# Project created by QtCreator 2016-01-26T21:17:42
#
#-------------------------------------------------
# AUTHOR : Amaury KNOCKAERT

QT       += core gui widgets

LIBS += -lqscintilla2_qt5

CONFIG += qscintilla2

TARGET = WebEditSci
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tabwidget.cpp \
    editor.cpp \
    textfile.cpp \
    fileinfodialog.cpp

HEADERS  += mainwindow.h \
    tabwidget.h \
    editor.h \
    textfile.h \
    fileinfodialog.h

RESOURCES += \
    res.qrc


#RC_FILE += \
 #   myapp.rc

