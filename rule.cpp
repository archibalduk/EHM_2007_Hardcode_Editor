#include "rule.h"

Rule::Rule(int pos) :
    pos_(pos),
    index_(0)
{
}

Rule::Rule() :
    pos_(0),
    index_(0)
{
}


/* ================== */
/*      Get Data      */
/* ================== */

// Get rule as a hex string
QString Rule::getHex(QByteArray *data)
{
    QString tmpStr;

    // Read the bytes from left to right so as to account for the endianess
    for(int x = (pos_ + 3), y = pos_; x >= y; --x) {
        QString hex = QString("%1").arg(static_cast<unsigned char>(data->at(x)), 2, 16, QChar('0')).toUpper();

        if(x > y)
            hex.append(" ");

        tmpStr.append(hex);
    }

    return tmpStr;
}
