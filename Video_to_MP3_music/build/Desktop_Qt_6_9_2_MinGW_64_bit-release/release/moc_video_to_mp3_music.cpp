/****************************************************************************
** Meta object code from reading C++ file 'video_to_mp3_music.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../video_to_mp3_music.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video_to_mp3_music.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN18Video_to_MP3_musicE_t {};
} // unnamed namespace

template <> constexpr inline auto Video_to_MP3_music::qt_create_metaobjectdata<qt_meta_tag_ZN18Video_to_MP3_musicE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Video_to_MP3_music",
        "on_quit_clicked",
        "",
        "onmusicFormClick",
        "PageId",
        "on_volume_clicked",
        "on_addlocal_clicked",
        "onUpdateLikeMusic",
        "isLike",
        "musicId",
        "onPlayStateChanged",
        "onPlayMusic",
        "currentList",
        "onPlayClicked",
        "on_playprev_clicked",
        "on_playnext_clicked",
        "on_playmode_clicked",
        "onMediaStatusChanged",
        "QMediaPlayer::MediaStatus",
        "status",
        "onPlayAll",
        "PageType",
        "pagetype",
        "playAllOfCommonPage",
        "commonPage*",
        "commonPage",
        "index",
        "onSourseChanged",
        "setCurrentPlayingPage",
        "page",
        "setMusicSilence",
        "isMuted",
        "onDurationChanged",
        "duration",
        "onPositionChanged",
        "setMusicSilderChanged",
        "value",
        "setMetadataAvailableChanged",
        "on_lrcPagebtn_clicked",
        "on_skin_clicked",
        "on_min_clicked",
        "on_max_clicked",
        "quitMusic"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_quit_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onmusicFormClick'
        QtMocHelpers::SlotData<void(int)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Slot 'on_volume_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_addlocal_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onUpdateLikeMusic'
        QtMocHelpers::SlotData<void(bool, QString)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 8 }, { QMetaType::QString, 9 },
        }}),
        // Slot 'onPlayStateChanged'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onPlayMusic'
        QtMocHelpers::SlotData<void(const QString &, const QVector<QString> &)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 9 }, { QMetaType::QStringList, 12 },
        }}),
        // Slot 'onPlayClicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_playprev_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_playnext_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_playmode_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onMediaStatusChanged'
        QtMocHelpers::SlotData<void(QMediaPlayer::MediaStatus)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 18, 19 },
        }}),
        // Slot 'onPlayAll'
        QtMocHelpers::SlotData<void(PageType)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 21, 22 },
        }}),
        // Slot 'playAllOfCommonPage'
        QtMocHelpers::SlotData<void(commonPage *, int)>(23, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 24, 25 }, { QMetaType::Int, 26 },
        }}),
        // Slot 'onSourseChanged'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'setCurrentPlayingPage'
        QtMocHelpers::SlotData<void(commonPage *)>(28, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 24, 29 },
        }}),
        // Slot 'setMusicSilence'
        QtMocHelpers::SlotData<void(bool)>(30, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 31 },
        }}),
        // Slot 'onDurationChanged'
        QtMocHelpers::SlotData<void(qint64)>(32, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 33 },
        }}),
        // Slot 'onPositionChanged'
        QtMocHelpers::SlotData<void(qint64)>(34, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 33 },
        }}),
        // Slot 'setMusicSilderChanged'
        QtMocHelpers::SlotData<void(float)>(35, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Float, 36 },
        }}),
        // Slot 'setMetadataAvailableChanged'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_lrcPagebtn_clicked'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_skin_clicked'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_min_clicked'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_max_clicked'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'quitMusic'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Video_to_MP3_music, qt_meta_tag_ZN18Video_to_MP3_musicE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Video_to_MP3_music::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18Video_to_MP3_musicE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18Video_to_MP3_musicE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18Video_to_MP3_musicE_t>.metaTypes,
    nullptr
} };

void Video_to_MP3_music::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Video_to_MP3_music *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_quit_clicked(); break;
        case 1: _t->onmusicFormClick((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->on_volume_clicked(); break;
        case 3: _t->on_addlocal_clicked(); break;
        case 4: _t->onUpdateLikeMusic((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->onPlayStateChanged(); break;
        case 6: _t->onPlayMusic((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[2]))); break;
        case 7: _t->onPlayClicked(); break;
        case 8: _t->on_playprev_clicked(); break;
        case 9: _t->on_playnext_clicked(); break;
        case 10: _t->on_playmode_clicked(); break;
        case 11: _t->onMediaStatusChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::MediaStatus>>(_a[1]))); break;
        case 12: _t->onPlayAll((*reinterpret_cast< std::add_pointer_t<PageType>>(_a[1]))); break;
        case 13: _t->playAllOfCommonPage((*reinterpret_cast< std::add_pointer_t<commonPage*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 14: _t->onSourseChanged(); break;
        case 15: _t->setCurrentPlayingPage((*reinterpret_cast< std::add_pointer_t<commonPage*>>(_a[1]))); break;
        case 16: _t->setMusicSilence((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->onDurationChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 18: _t->onPositionChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 19: _t->setMusicSilderChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 20: _t->setMetadataAvailableChanged(); break;
        case 21: _t->on_lrcPagebtn_clicked(); break;
        case 22: _t->on_skin_clicked(); break;
        case 23: _t->on_min_clicked(); break;
        case 24: _t->on_max_clicked(); break;
        case 25: _t->quitMusic(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< commonPage* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< commonPage* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *Video_to_MP3_music::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Video_to_MP3_music::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18Video_to_MP3_musicE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Video_to_MP3_music::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}
QT_WARNING_POP
