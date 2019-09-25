#-------------------------------------------------
#
# Project created by QtCreator 2019-08-01T15:28:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 20190802
TEMPLATE = app
QT += serialport#串口
 QT += sql#数据库
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    cha_xun.cpp \
    chuang_jian_shu_ju_ku.cpp \
        main.cpp \
        mainwindow.cpp \
    ruler.cpp \
    she_bei_can_shu.cpp \
    chuan_kou.cpp \
    xun_jian.cpp

HEADERS += \
    cha_xun.h \
    chuang_jian_shu_ju_ku.h \
        mainwindow.h \
    ruler.h \
    she_bei_can_shu.h \
    chuan_kou.h \
    xun_jian.h

FORMS += \
    cha_xun.ui \
    chuang_jian_shu_ju_ku.ui \
        mainwindow.ui \
    she_bei_can_shu.ui \
    chuan_kou.ui \
    xun_jian.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
#这部分是右键添加静态链接库生成的.添加python的libs所在位置和include文件夹位置.然后选择静态库.把python程序下的libs下复制libspython37.a重命名为libpython37d.a文件
#win32:CONFIG(release, debug|release):
 LIBS += -L'C:/Program Files/Python37/libs/' -lpython37
#else:win32:CONFIG(debug, debug|release): LIBS += -L'C:/Program Files/Python37/libs/' -lpython37a

INCLUDEPATH += 'C:/Program Files/Python37/include'
DEPENDPATH += 'C:/Program Files/Python37/include'

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += 'C:/Program Files/Python37/libs/libpython37.a'
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += 'C:/Program Files/Python37/libs/libpython37d.a'
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += 'C:/Program Files/Python37/libs/python37.lib'
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += 'C:/Program Files/Python37/libs/python37d.lib'
#把python文件放入到调试文件夹exe同级
DISTFILES += \
    debug/test_py.py \
    test_py.py
