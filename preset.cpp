#include "preset.h"


/* =========================== */
/*      Class Constructor      */
/* =========================== */

// Default constructor
Preset::Preset(QString hex, QString description, int index) :
    description_(description),
    index_(static_cast<short>(index))
{
    data_ = QByteArray::fromHex(hex.toLatin1());

    std::reverse(data_.begin(), data_.end()); // Reverse the array for endianess
}

Preset::Preset(QByteArray &data, QString description, int index) :
    description_(description),
    data_(data),
    index_(static_cast<short>(index))
{

}


/* ================== */
/*      Get Data      */
/* ================== */

// Get data as a hex string
QString Preset::getData()
{
    QString tmpStr;

    // Read the bytes from left to right so as to account for the endianess
    for(int i = data_.size() - 1; i >= 0; --i) {
        QString hex = QString("%1").arg(static_cast<unsigned char>(data_[i]), 2, 16, QChar('0')).toUpper();

        if(i > 0)
            hex.append(" ");

        tmpStr.append(hex);
    }

    return tmpStr;
}

// Get description and hex as a string
QString Preset::getDescAndData()
{
    return (getData() + ": " + getDesc());
}

// Find the index of the preset vector matching the source array (and add the source to the vector if no match is found)
short Preset::findIndex(QVector<Preset> &vect, const QByteArray &source, QString desc)
{
    // Attempt to match the source with an existing preset in the vector
    for(auto itr = vect.begin(); itr < vect.end(); ++itr)
    {
        if(itr->data_ == source)
            return itr->getIndex();
    }

    // If no match is found, add the source data to the preset vector
    vect.push_back(Preset(source, desc, vect.size()));

    return vect.size() - 1;
}
