#include "comp_rules.h"

QVector<CompRules> CompRules::vect_;
QVector<Preset> CompRules::preLineUp_;
QByteArray *CompRules::data_ = nullptr;


/* =========================== */
/*      Class Constructor      */
/* =========================== */

// Default constructor
CompRules::CompRules(QString name, int pos, int posRuleLineUp) :
    pos_(pos)
{
    compName_ = new Text(pos_, name);
    rLineUp_.setPos(posRuleLineUp);
    rLineUp_.setIndex(Preset::findIndex(preLineUp_, data_->mid(rLineUp_.getPosInt(), 4), name));
}


/* ============================= */
/*      Data Initialisation      */
/* ============================= */

// Point to the exe data and initialise the various vectors
void CompRules::init(QByteArray &data)
{
    // Assign static pointer to the exe data
    data_ = &data;
    Text::init(data);

    vect_.clear();

    // Push back the various line up rule presets
    preLineUp_.push_back(Preset("0x8F20F0", "No restrictions (Austria) Doesn't work???", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F28C0", "No restrictions (Denmark)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F1DD0", "No restrictions (France)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8EE430", "No restrictions (LNAH)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F5F90", "No restrictions (NHL)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8EE430", "No restrictions (Switzerland)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F2430", "Max 3 foreigners (Czech Republic)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F2BE0", "Max 4 foreigners (Finland)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8EFFC0", "Max 6 foreigners (Austria / Slovenia)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F1930", "Max 10 foreigners (UK EIHL)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F1A20", "Max 11 foreigners", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F1220", "Max 11 foreigners (UK)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8EFCD0", "Max 89 foreigners", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F0B60", "Max 98 foreigners (Norway)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F0510", "Max 3 foreigners & Min 2 20-year olds (Russia)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F0420", "Max 3 foreigners & Min 2 22-year olds (Russia)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F00B0", "Max 4 foreigners & Min 1 20-year olds (Slovakia)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F1CE0", "Max 11 foreigners & Min 5 25-year olds (Germany)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F1470", "Max 0 non-EUs & Max 4 foreigners (UK EPIHL)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8EFA70", "Max 2 non-EUs (Sweden)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F0F10", "Max 3 non-EUs (Italy)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F44B0", "Max 3 overagers (OHL)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F3D30", "Max 3 overagers (QMJHL)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F40F0", "Max 3 overagers & Max 3 under 16-year olds (WHL)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F36A0", "Max 6 overagers & Min 4 rookies (<30 junior GP) (Canada)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F4D90", "Max 4 vets (>280 pro GP) & Min 5 d\'mentals (<128 pro GP) (CHL)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F5460", "Max 4 veterans (>260 pro GP) (ECHL)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F5C40", "Max 5 veterans (>260 pro GP) (AHL)", preLineUp_.size()));
    preLineUp_.push_back(Preset("0x8F4800", "Max 7 veterans (>300 pro GP) & Min 3 rookies (<40 pro GP) (UHL)", preLineUp_.size()));


    // Push back the various competition rules
    vect_.push_back(CompRules("(AUT) Austria", 0x7B02D0, 0x7B043C));
    vect_.push_back(CompRules("(CAN) Alberta Junior Hockey League", 0x7B0F90, 0x7B0EF4));
    vect_.push_back(CompRules("(CAN) British Columbia Hockey League", 0x7B0E68, 0x7B0DCC));
    vect_.push_back(CompRules("(CAN) Ligue Nord-Américaine de Hockey", 0x7B1100, 0x7B118C));
    vect_.push_back(CompRules("(CAN) Ontario Hockey League", 0x7B1478, 0x7B1504));
    vect_.push_back(CompRules("(CAN) Quebec Major Junior Hockey League", 0x7B1228, 0x7B12B4));
    vect_.push_back(CompRules("(CAN) Saskatchewan Junior Hockey League", 0x7B0FD8, 0x7B1064));
    vect_.push_back(CompRules("(CAN) Western Hockey League", 0x7B1350, 0x7B13DC));
    vect_.push_back(CompRules("(CZE) Czech Republic", 0x7B04D8, 0x7B055C));
    vect_.push_back(CompRules("(DEN) Denmark", 0x7B07B8, 0x7B0844));
    vect_.push_back(CompRules("(FIN) Finland", 0x7B09C0, 0x7B0CEC));
    vect_.push_back(CompRules("(FRA) France", 0x7B00C8, 0x7B0154));
    vect_.push_back(CompRules("(GBR) Elite Ice Hockey League", 0x7AFE78, 0x7AFDDC));
    vect_.push_back(CompRules("(GBR) English Premier Ice Hockey League", 0x7AFC70, 0x7AFCFC));
    vect_.push_back(CompRules("(GBR) UK Lower Leagues", 0x7AFB50, 0x7AFBD4));
    vect_.push_back(CompRules("(GER) Germany", 0x7AFEC0, 0x7B002C));
    vect_.push_back(CompRules("(ITA) Italy", 0x7AF950, 0x7AF9D4));
    vect_.push_back(CompRules("(NOR) Norway", 0x7AF748, 0x7AF7D4));
    vect_.push_back(CompRules("(RUS) Russian Lower Leagues", 0x7AF4F0, 0x7AF57C));
    vect_.push_back(CompRules("(RUS) Russian Superleague", 0x7AF6F8, 0x7AF65C));
    vect_.push_back(CompRules("(SLO) Slovenia", 0x7AF000, 0x7AF24C));
    vect_.push_back(CompRules("(SVK) Slovakia", 0x7AF2E8, 0x7AF374));
    vect_.push_back(CompRules("(SWE) Sweden", 0x7AEED8, 0x7AEF64));
    vect_.push_back(CompRules("(USA) American Hockey League", 0x7B1918, 0x7B19A4));
    vect_.push_back(CompRules("(USA) Central Hockey League", 0x7B16C8, 0x7B1754));
    vect_.push_back(CompRules("(USA) East Coast Hockey League", 0x7B17F0, 0x7B187C));
    vect_.push_back(CompRules("(USA) National Hockey League", 0x7B1A40, 0x7B1ACC));
    vect_.push_back(CompRules("(USA) United Hockey League", 0x7B15A0, 0x7B162C));
}


/* ================== */
/*      Set Data      */
/* ================== */

// Set line up rule
void CompRules::setLineUpRule(int &i)
{
    rLineUp_.setIndex(i);

    data_->replace(rLineUp_.getPosInt(), preLineUp_[i].getSize(), preLineUp_[i].getRawData());
}
