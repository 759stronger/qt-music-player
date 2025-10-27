QT       += core gui  multimedia network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commonpage.cpp \
    listitembox.cpp \
    lrcpage.cpp \
    main.cpp \
    music.cpp \
    musicform.cpp \
    musiclist.cpp \
    musicslider.cpp \
    recbox.cpp \
    recboxitem.cpp \
    video_to_mp3_music.cpp \
    volumetool.cpp

HEADERS += \
    commonpage.h \
    listitembox.h \
    lrcpage.h \
    music.h \
    musicform.h \
    musiclist.h \
    musicslider.h \
    recbox.h \
    recboxitem.h \
    video_to_mp3_music.h \
    volumetool.h

FORMS += \
    commonpage.ui \
    listitembox.ui \
    lrcpage.ui \
    musicform.ui \
    musicslider.ui \
    recbox.ui \
    recboxitem.ui \
    video_to_mp3_music.ui \
    volumetool.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    iamges.qrc
