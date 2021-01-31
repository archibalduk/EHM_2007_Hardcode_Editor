#ifndef PRESET_H
#define PRESET_H

#include <algorithm>
#include <QByteArray>
#include <QString>
#include <QVector>

class Preset
{
private:
    QString description_;
    short index_;

public:
    QByteArray data_;

    Preset(QString hex, QString description, int index);
    Preset(QByteArray &data, QString description, int index);
    Preset() {}
    ~Preset() {}

    QString getData();
    QString getDesc() { return description_; }
    QString getDescAndData();
    short getIndex() { return index_; }
    QByteArray getRawData() { return data_; }
    int getSize() { return data_.size(); }

    static short findIndex(QVector<Preset> &vect, const QByteArray &source, QString desc);
};

#endif // PRESET_H
