/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata[345];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 24),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 4),
QT_MOC_LITERAL(4, 42, 24),
QT_MOC_LITERAL(5, 67, 33),
QT_MOC_LITERAL(6, 101, 5),
QT_MOC_LITERAL(7, 107, 34),
QT_MOC_LITERAL(8, 142, 26),
QT_MOC_LITERAL(9, 169, 24),
QT_MOC_LITERAL(10, 194, 29),
QT_MOC_LITERAL(11, 224, 27),
QT_MOC_LITERAL(12, 252, 25),
QT_MOC_LITERAL(13, 278, 29),
QT_MOC_LITERAL(14, 308, 18),
QT_MOC_LITERAL(15, 327, 17)
    },
    "MainWindow\0on_edPopSize_textChanged\0"
    "\0arg1\0on_edDNASize_textChanged\0"
    "on_cbCromType_currentIndexChanged\0"
    "index\0on_cbCrossType_currentIndexChanged\0"
    "on_edCrossProb_textChanged\0"
    "on_edMutProb_textChanged\0"
    "on_edElitimsRatio_textChanged\0"
    "on_edCrossScale_textChanged\0"
    "on_edMutScale_textChanged\0"
    "on_edElitimsScale_textChanged\0"
    "on_btStart_clicked\0on_btStop_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       5,    1,   80,    2, 0x08 /* Private */,
       7,    1,   83,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
       9,    1,   89,    2, 0x08 /* Private */,
      10,    1,   92,    2, 0x08 /* Private */,
      11,    1,   95,    2, 0x08 /* Private */,
      12,    1,   98,    2, 0x08 /* Private */,
      13,    1,  101,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_edPopSize_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_edDNASize_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_cbCromType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_cbCrossType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_edCrossProb_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_edMutProb_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_edElitimsRatio_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_edCrossScale_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_edMutScale_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_edElitimsScale_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_btStart_clicked(); break;
        case 11: _t->on_btStop_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE