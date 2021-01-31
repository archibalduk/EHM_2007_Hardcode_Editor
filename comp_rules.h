#ifndef COMP_RULES_H
#define COMP_RULES_H

#include <QByteArray>
#include <QDataStream>
#include <QString>
#include <QVector>

#include "preset.h"
#include "rule.h"
#include "text.h"

class CompRules
{
private:
    // Offsets
    int pos_;
    Rule rLineUp_;

    // Competition Name
    Text *compName_;

    // Static data
    static QByteArray *data_;

/*
    enum ENUM_LENGTHS {
        LENGTH_NAME_SHORT = 64,
        LENGTH_NAME_STANDARD = 72,
        LENGTH_NAME_LONG = 80
    };
*/

public:
    CompRules(QString name, int pos, int posRuleLineUp);
    CompRules() {}
    ~CompRules() {}

    // String functions
    QString getLongName() { return compName_->getText(); }
    QString getShortName() { return compName_->getDesc();; }
    QString getOffsetA() { return QString("%1").arg(pos_, 8, 16, QChar('0')).toUpper(); }   // Return the position of the first byte of the Long Name
    QString getOffsetB() { return QString("%1").arg((pos_ + compName_->getSize() - 1), 8, 16, QChar('0')).toUpper(); }   // Return the position of the last byte of the Long Name

    // Line up rule
    short getLineUpRuleIndex() { return rLineUp_.getIndex(); }
    QString getLineUpRulePos() { return rLineUp_.getPosHex(); }
    QString getLineUpRuleRelativePos() { return QString::number(rLineUp_.getRelativePos(pos_  + compName_->getSize() - 1)); }
    QString getLineUpRuleString() { return rLineUp_.getHex(data_); }
    void setLineUpRule(int &i);

    // Static functions
    static void init(QByteArray &data);

    // Static data
    static QVector<CompRules> vect_;
    static QVector<Preset> preLineUp_;
};

#endif // COMP_RULES_H
