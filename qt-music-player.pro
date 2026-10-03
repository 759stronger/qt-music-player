TEMPLATE = app
TARGET = Video_to_MP3_music

QT += core gui widgets multimedia network sql
CONFIG += c++17

INCLUDEPATH += \
    $$PWD/src/app \
    $$PWD/src/models \
    $$PWD/src/pages \
    $$PWD/src/widgets

SOURCES += \
    src/main.cpp \
    src/app/video_to_mp3_music.cpp \
    src/models/music.cpp \
    src/models/musiclist.cpp \
    src/pages/commonpage.cpp \
    src/pages/lrcpage.cpp \
    src/widgets/listitembox.cpp \
    src/widgets/musicform.cpp \
    src/widgets/musicslider.cpp \
    src/widgets/recbox.cpp \
    src/widgets/recboxitem.cpp \
    src/widgets/volumetool.cpp

HEADERS += \
    src/app/video_to_mp3_music.h \
    src/models/music.h \
    src/models/musiclist.h \
    src/pages/commonpage.h \
    src/pages/lrcpage.h \
    src/widgets/listitembox.h \
    src/widgets/musicform.h \
    src/widgets/musicslider.h \
    src/widgets/recbox.h \
    src/widgets/recboxitem.h \
    src/widgets/volumetool.h

FORMS += \
    src/ui/commonpage.ui \
    src/ui/listitembox.ui \
    src/ui/lrcpage.ui \
    src/ui/musicform.ui \
    src/ui/musicslider.ui \
    src/ui/recbox.ui \
    src/ui/recboxitem.ui \
    src/ui/video_to_mp3_music.ui \
    src/ui/volumetool.ui

RESOURCES += resources/images.qrc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
