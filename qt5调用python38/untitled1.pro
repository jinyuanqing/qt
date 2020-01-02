QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#这部分是右键添加静态链接库生成的.添加python的libs所在位置和include文件夹位置.然后选择静态库.把python程序下的libs下复制libspython37.a重命名为libpython37d.a文件
#win32:CONFIG(release, debug|release):
 LIBS += -L'C:/Program Files/Python38/libs/' -lpython38
#else:win32:CONFIG(debug, debug|release): LIBS += -L'C:/Program Files/Python37/libs/' -lpython37a

INCLUDEPATH += 'C:/Program Files/Python38/include'
DEPENDPATH += 'C:/Program Files/Python38/include'
win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += 'C:/Program Files/Python38/libs/python38.lib'
#win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += 'C:/Program Files/Python38/libs/libpython38.a'
#else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += 'C:/Program Files/Python38/libs/libpython38d.a'
#else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += 'C:/Program Files/Python38/libs/python38.lib'
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += 'C:/Program Files/Python37/libs/python37d.lib'
#把python文件放入到调试文件夹exe同级
