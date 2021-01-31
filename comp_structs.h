#ifndef COMP_STRUCTS_H
#define COMP_STRUCTS_H

#include <QByteArray>
#include <QDataStream>
#include <QString>
#include <QVector>

#include "preset.h"
#include "rule.h"
#include "text.h"

class CompStructs
{
private:
    // Offsets
    int pos_;
    Rule sLeagueSize_;
    Rule sPlayoffs_;
    Rule sSchedule_;
    Rule sStructure_;

    // Competition Name
    Text *compName_;

    // Static data
    static QByteArray *data_;
public:
    CompStructs(QString name, int pos, int posLeagueSize = 0x0, int posPlayoffs = 0x0, int posSchedule = 0x0, int posStructure = 0x0, unsigned short textCapacity = 0);
    CompStructs() {}
    ~CompStructs() {}

    // String functions
    QString getLongName() { return compName_->getText(); }
    QString getShortName() { return compName_->getDesc();; }
    QString getOffsetA() { return QString("%1").arg(pos_, 8, 16, QChar('0')).toUpper(); }   // Return the position of the first byte of the Long Name
    QString getOffsetB() { return QString("%1").arg(getOffsetB_Hex(), 8, 16, QChar('0')).toUpper(); }   // Return the position of the last byte of the Long Name
    int getOffsetB_Hex() { return (pos_ + compName_->getSize() - 1); }

    // League Size
    short getLeagueSizeIndex() { return sLeagueSize_.getIndex(); }
    QString getLeagueSizePos() { return sLeagueSize_.getPosHex(); }
    QString getLeagueSizeRelativePos() { return QString::number(sLeagueSize_.getRelativePos(pos_  + compName_->getSize() - 1)); }
    QString getLeagueSizeString() { return sLeagueSize_.getHex(data_); }
    void setLeagueSize(int &i);

    // Playoffs
    short getPlayoffsIndex() { return sPlayoffs_.getIndex(); }
    QString getPlayoffsPos() { return sPlayoffs_.getPosHex(); }
    QString getPlayoffsRelativePos() { return QString::number(sPlayoffs_.getRelativePos(pos_  + compName_->getSize() - 1)); }
    QString getPlayoffsString() { return sPlayoffs_.getHex(data_); }
    void setPlayoffs(int &i);

    // Schedule
    short getScheduleIndex() { return sSchedule_.getIndex(); }
    QString getSchedulePos() { return sSchedule_.getPosHex(); }
    QString getScheduleRelativePos() { return QString::number(sSchedule_.getRelativePos(pos_  + compName_->getSize() - 1)); }
    QString getScheduleString() { return sSchedule_.getHex(data_); }
    void setSchedule(int &i);

    // Structure
    short getStructureIndex() { return sStructure_.getIndex(); }
    QString getStructurePos() { return sStructure_.getPosHex(); }
    QString getStructureRelativePos() { return QString::number(sStructure_.getRelativePos(pos_  + compName_->getSize() - 1)); }
    QString getStructureString() { return sStructure_.getHex(data_); }
    void setStructure(int &i);

    // Static functions
    static void init(QByteArray &data);

    // Static data
    static QVector<CompStructs> vect_;
    static QVector<Preset> preLeagueSize_;
    static QVector<Preset> prePlayoffs_;
    static QVector<Preset> preSchedule_;
    static QVector<Preset> preStructure_;
};

#endif // COMP_STRUCTS_H
