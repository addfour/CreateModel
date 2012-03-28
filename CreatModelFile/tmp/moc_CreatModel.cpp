/****************************************************************************
** Meta object code from reading C++ file 'CreatModel.h'
**
** Created: Tue Mar 27 09:32:08 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CreatModel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CreatModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CreatModel[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      23,   11,   11,   11, 0x08,
      34,   11,   11,   11, 0x08,
      47,   11,   42,   11, 0x08,
      56,   11,   42,   11, 0x08,
      67,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      89,   85,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CreatModel[] = {
    "CreatModel\0\0OnAppend()\0OnDelete()\0"
    "OnNew()\0bool\0OnSave()\0OnSaveAs()\0"
    "OnOpen()\0OnQuit()\0pos\0showContextMenu(QPoint)\0"
};

const QMetaObject CreatModel::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CreatModel,
      qt_meta_data_CreatModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CreatModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CreatModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CreatModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreatModel))
        return static_cast<void*>(const_cast< CreatModel*>(this));
    return QDialog::qt_metacast(_clname);
}

int CreatModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: OnAppend(); break;
        case 1: OnDelete(); break;
        case 2: OnNew(); break;
        case 3: { bool _r = OnSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = OnSaveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: OnOpen(); break;
        case 6: OnQuit(); break;
        case 7: showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
