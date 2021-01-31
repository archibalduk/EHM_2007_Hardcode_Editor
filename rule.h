#ifndef RULE_H
#define RULE_H

#include <QByteArray>
#include <QString>

class Rule
{
private:
    int pos_;
    int index_;

public:
    Rule(int pos);
    Rule();
    ~Rule() {}

    // Get data
    QString getHex(QByteArray *data);
    int getIndex() { return index_; }
    QString getPosHex() { return QString("%1").arg(pos_, 8, 16, QChar('0')).toUpper(); }
    int getPosInt() { return pos_; }
    int getRelativePos(int reference) { return pos_ - reference; }

    // Set data
    void setIndex(int index) { index_ = index; }
    void setPos(int pos) { pos_ = pos; }
};

#endif // RULE_H
