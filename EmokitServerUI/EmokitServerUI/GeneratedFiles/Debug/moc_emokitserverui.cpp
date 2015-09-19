/****************************************************************************
** Meta object code from reading C++ file 'emokitserverui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../emokitserverui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emokitserverui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EmokitServerUI_t {
    QByteArrayData data[14];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmokitServerUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmokitServerUI_t qt_meta_stringdata_EmokitServerUI = {
    {
QT_MOC_LITERAL(0, 0, 14), // "EmokitServerUI"
QT_MOC_LITERAL(1, 15, 14), // "setting_Dialog"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "graph_Dialog"
QT_MOC_LITERAL(4, 44, 11), // "file_Dialog"
QT_MOC_LITERAL(5, 56, 12), // "start_Server"
QT_MOC_LITERAL(6, 69, 11), // "stop_Server"
QT_MOC_LITERAL(7, 81, 9), // "clear_Msg"
QT_MOC_LITERAL(8, 91, 12), // "RecvDataSlot"
QT_MOC_LITERAL(9, 104, 1), // "a"
QT_MOC_LITERAL(10, 106, 4), // "type"
QT_MOC_LITERAL(11, 111, 18), // "UserListViewInsert"
QT_MOC_LITERAL(12, 130, 3), // "key"
QT_MOC_LITERAL(13, 134, 18) // "UserListViewDelete"

    },
    "EmokitServerUI\0setting_Dialog\0\0"
    "graph_Dialog\0file_Dialog\0start_Server\0"
    "stop_Server\0clear_Msg\0RecvDataSlot\0a\0"
    "type\0UserListViewInsert\0key\0"
    "UserListViewDelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmokitServerUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    2,   65,    2, 0x08 /* Private */,
      11,    1,   70,    2, 0x08 /* Private */,
      13,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void EmokitServerUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EmokitServerUI *_t = static_cast<EmokitServerUI *>(_o);
        switch (_id) {
        case 0: _t->setting_Dialog(); break;
        case 1: _t->graph_Dialog(); break;
        case 2: _t->file_Dialog(); break;
        case 3: _t->start_Server(); break;
        case 4: _t->stop_Server(); break;
        case 5: _t->clear_Msg(); break;
        case 6: _t->RecvDataSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->UserListViewInsert((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->UserListViewDelete((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject EmokitServerUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_EmokitServerUI.data,
      qt_meta_data_EmokitServerUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EmokitServerUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmokitServerUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EmokitServerUI.stringdata))
        return static_cast<void*>(const_cast< EmokitServerUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int EmokitServerUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
