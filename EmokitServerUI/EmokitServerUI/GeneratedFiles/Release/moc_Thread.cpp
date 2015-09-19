/****************************************************************************
** Meta object code from reading C++ file 'Thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RecvThread_t {
    QByteArrayData data[11];
    char stringdata[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecvThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecvThread_t qt_meta_stringdata_RecvThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RecvThread"
QT_MOC_LITERAL(1, 11, 14), // "RecvDataSignal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 1), // "a"
QT_MOC_LITERAL(4, 29, 4), // "type"
QT_MOC_LITERAL(5, 34, 16), // "UpdateDataSignal"
QT_MOC_LITERAL(6, 51, 8), // "channel1"
QT_MOC_LITERAL(7, 60, 8), // "channel2"
QT_MOC_LITERAL(8, 69, 11), // "LoginSignal"
QT_MOC_LITERAL(9, 81, 3), // "key"
QT_MOC_LITERAL(10, 85, 12) // "LogOutSignal"

    },
    "RecvThread\0RecvDataSignal\0\0a\0type\0"
    "UpdateDataSignal\0channel1\0channel2\0"
    "LoginSignal\0key\0LogOutSignal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecvThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    2,   39,    2, 0x06 /* Public */,
       8,    1,   44,    2, 0x06 /* Public */,
      10,    1,   47,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void RecvThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RecvThread *_t = static_cast<RecvThread *>(_o);
        switch (_id) {
        case 0: _t->RecvDataSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->UpdateDataSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->LoginSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->LogOutSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RecvThread::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecvThread::RecvDataSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (RecvThread::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecvThread::UpdateDataSignal)) {
                *result = 1;
            }
        }
        {
            typedef void (RecvThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecvThread::LoginSignal)) {
                *result = 2;
            }
        }
        {
            typedef void (RecvThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RecvThread::LogOutSignal)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject RecvThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_RecvThread.data,
      qt_meta_data_RecvThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RecvThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecvThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RecvThread.stringdata))
        return static_cast<void*>(const_cast< RecvThread*>(this));
    return QThread::qt_metacast(_clname);
}

int RecvThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void RecvThread::RecvDataSignal(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RecvThread::UpdateDataSignal(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RecvThread::LoginSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RecvThread::LogOutSignal(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
