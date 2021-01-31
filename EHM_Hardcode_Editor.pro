#-------------------------------------------------
#
# Project created by QtCreator 2014-04-20T10:58:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Enable as many compiler warnings as possible
CONFIG += warn_on

TARGET = EHM_Hardcode_Editor
TEMPLATE = app

RC_FILE = ehm_hardcode_editor.rc
RESOURCES = ehm_hardcode_editor.qrc

win32 {
DEFINES += BUILDTIME=\\\"$$system('echo %time%')\\\"
DEFINES += BUILDDATE=\\\"$$system('echo %date%')\\\"
} else {
DEFINES += BUILDTIME=\\\"$$system(date '+%H:%M')\\\"
DEFINES += BUILDDATE=\\\"$$system(date '+%d/%m/%y')\\\"
}

SOURCES += main.cpp\
        editor.cpp \
    comp_rules.cpp \
    editor_comp_rules.cpp \
    preset.cpp \
    text.cpp \
    editor_folder_paths.cpp \
    editor_comp_names.cpp \
    comp_structs.cpp \
    rule.cpp \
    editor_comp_structs.cpp

HEADERS  += editor.h \
    comp_rules.h \
    editor_comp_rules.h \
    preset.h \
    text.h \
    editor_folder_paths.h \
    editor_comp_names.h \
    comp_structs.h \
    rule.h \
    editor_comp_structs.h \
    common.h

FORMS    += editor.ui
