#include "comp_structs.h"

QVector<CompStructs> CompStructs::vect_;
QVector<Preset> CompStructs::preLeagueSize_;
QVector<Preset> CompStructs::prePlayoffs_;
QVector<Preset> CompStructs::preSchedule_;
QVector<Preset> CompStructs::preStructure_;
QByteArray *CompStructs::data_ = nullptr;


/* =========================== */
/*      Class Constructor      */
/* =========================== */

// Default constructor
CompStructs::CompStructs(QString name, int pos, int posLeagueSize, int posPlayoffs, int posSchedule, int posStructure, unsigned short textCapacity) :
    pos_(pos)
{
    compName_ = new Text(pos_, name, textCapacity); // Text capacity is needed because the NHL has a 00 straight after the text field

    // Set default values
    if(posLeagueSize == 0x0)
        posLeagueSize = getOffsetB_Hex() + 97;

    if(posPlayoffs == 0x0)
        posPlayoffs = posLeagueSize - 52;

    if(posSchedule == 0x0)
        posSchedule = posLeagueSize - 44;

    if(posStructure == 0x0)
        posStructure = posLeagueSize + 52;

    // Prevent any negative offsets
    if(posPlayoffs < 0)
        posPlayoffs = 0x0;

    if(posStructure < 0)
        posStructure = 0x0;

    if(posSchedule < 0)
        posSchedule = 0x0;

    // Set positions and indexes
    sLeagueSize_.setPos(posLeagueSize);
    sLeagueSize_.setIndex(Preset::findIndex(preLeagueSize_, data_->mid(sLeagueSize_.getPosInt(), 4), name));

    sPlayoffs_.setPos(posPlayoffs);
    sPlayoffs_.setIndex(Preset::findIndex(prePlayoffs_, data_->mid(sPlayoffs_.getPosInt(), 4), name));

    sSchedule_.setPos(posSchedule);
    sSchedule_.setIndex(Preset::findIndex(preSchedule_, data_->mid(sSchedule_.getPosInt(), 4), name));

    sStructure_.setPos(posStructure);
    sStructure_.setIndex(Preset::findIndex(preStructure_, data_->mid(sStructure_.getPosInt(), 4), name));
}


/* ============================= */
/*      Data Initialisation      */
/* ============================= */

// Point to the exe data and initialise the various vectors
void CompStructs::init(QByteArray &data)
{
    // Assign static pointer to the exe data
    data_ = &data;
    Text::init(data);

    vect_.clear();

    // Push back the various league size presets
    preLeagueSize_.push_back(Preset("0x8F5AD0","0 Teams: Not Applicable", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x8F6BD0","1 Team", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x925BA0","1 Team", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x923A90","1 Team", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x93E5D0","1 Team", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x9498D0","1 Team", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x8F2D00","3 Teams", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x91F380","4 Teams: Memorial Cup", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x91F370","4 Teams", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x932250","5 Teams: SLO Interliga 1", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x906390","6 Teams: SLO Interliga 2", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x933810","8 Teams: AUT Elite, SLO Elite", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x9293E0","9 Teams: DEN Oddset", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x8F5E20","10 Teams: GBR Elite, NOR UPC-Ligaen, SVK Extraliga, UHL", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x92DFD0","10 Teams", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x90DD70","12 Teams", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x923930","12 Teams: FIN Mestis, GBR EPIHL, SWE Eliteserien", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x92A680","12 Teams", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x90DD60","13 Teams", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x9266B0","14 Teams: CZE Extraliga, FIN SM-League, GER Elite", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x94C170","16 Teams: SWE Allsvenskan", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x880910","17 Teams: CHL", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x93F220","18 Teams: QMJHL", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x945360","19 Teams: RUS Superleague", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x8EE3C0","20 Teams: OHL", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x88B9A0","21 Teams: WHL", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x904E30","22 Teams", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x886690","25 Teams: ECHL", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x88EDD0","27 Teams: AHL", preLeagueSize_.size()));
    preLeagueSize_.push_back(Preset("0x8F0990","30 Teams: NHL", preLeagueSize_.size()));

    // Push back the various playoffs presets
    prePlayoffs_.push_back(Preset("0x4013F0","All-Stars, DEN Cup, Euro Challenge/Tour, Exhibition, Slovak/Swiss Cup, U20 Four Nations", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x8810C0","CHL", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x887BF0","ECHL", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x88D1A0","WHL", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x890720","AHL", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x895B70","NHL", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x8C8420","FIN Suomi Div, Deutschland Cup", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x8CE9D0","OHL", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x8FD5F0","UHL", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x9049A0","Continental Cup", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x905D70","Champions Cup", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x910240","Olympic Pre-Qualification", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x911810","Olympic Final Qualification", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x914B10","Olympic Hockey Tournament", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x916380","World Cup", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x916B90","U20 World Championships (Div 1)", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x91A270","U20 World Championships", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x91A9E0","World Championships (Div 1)", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x91F470","World Championships", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x9242F0","FIN Mestis", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x926780","FIN SM-League", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x9294B0","DEN Oddset", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x92AD10","GBR EPIHL Cup", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x92C8C0","GBR EPIHL", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x92E650","GBR Challenge Cup", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x930000","GBR Elite", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x9310B0","SLO Interliga 2", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x932320","SLO Interliga 1", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x9338E0","SLO Elite", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x935980","CZE Extraliga", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x937900","NOR UPC-Ligaen", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x938EC0","CAN-RUS Challenge", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x93AE70","Memorial Cup", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x93F550","QMJHL", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x941FA0","GER Elite", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x945C40","RUS Superleague", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x948350","AUT Elite", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x94A2D0","SVK Extraliga", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x94C240","SWE Allsvenskan", prePlayoffs_.size()));
    prePlayoffs_.push_back(Preset("0x94EAE0","SWE Elitserien", prePlayoffs_.size()));

    // Push back the various schedule presets
    preSchedule_.push_back(Preset("0x4013F0","Deutschland Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x87D430","CHL", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x8813E0","ECHL", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x887F40","WHL", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x88D4C0","AHL", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x890A40","NHL", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x8C98A0","OHL", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x8FB820","UHL", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x902920","Continental Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x905720","Champions Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x906C50","Four Nations Cup (Czech Republic)", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x907A40","Four Nations Cup (Sweden)", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x908590","Four Nations Cup (Finland)", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x909030","Four Nations Cup (Russia)", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x909B40","Slovak Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x90A630","Swiss Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x90BFC0","Euro Challenge", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x90E080","Euro Hockey Tour", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x90FC30","Olympic Pre-Qualification", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x911200","Olympic Final Qualification", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x912940","Olympic Hockey Tournament", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x914BE0","World Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x916420","U20 World Championships (Div 1)", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x917CA0","U20 World Championships", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x91A3D0","World Championships (Div 1)", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x91B7C0","World Championships", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x921BE0","FIN Suomi Div", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x921CC0","FIN Mestis", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x924470","FIN SM-League", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x926B10","DEN Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x927540","DEN Oddset", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x929570","GBR EPIHL Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x92ADB0","GBR EPIHL", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x92C9B0","GBR Challenge Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x92E6F0","GBR Elite", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x9300C0","SLO Interliga 2", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x931170","SLO Interliga 1", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x9323E0","SLO Elite", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x933AF0","CZE Extraliga", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x935A50","NOR UPC-Ligean", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x937C60","CAN-RUS Challenge", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x9391E0","CAN All-Stars", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x93A4F0","Memorial Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x93B520","QMJHL", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x93FB70","GER All-Stars", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x940540","GER Elite", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x942060","RUS All-Stars", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x942B00","RUS Superleague", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x945E00","AUT All-Stars", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x946830","AUT Elite", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x948410","SVK Extraliga", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x94A390","SWE Allsvenskan", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x94C370","SWE Elitserien", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x94EBF0","UHL All-Stars", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x94F6A0","CHL All-Stars", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x950160","ECHL All-Stars", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x950D40","AHL All-Stars", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x952060","NHL All-Stars", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x9533F0","Exhibition Mini Cup", preSchedule_.size()));
    preSchedule_.push_back(Preset("0x953D20","Exhibition Mini League", preSchedule_.size()));


    // Push back the various structure presets
    preStructure_.push_back(Preset("0x87FF50","CHL", preStructure_.size()));
    preStructure_.push_back(Preset("0x885670","ECHL", preStructure_.size()));
    preStructure_.push_back(Preset("0x88B010","WHL", preStructure_.size()));
    preStructure_.push_back(Preset("0x88E490","AHL", preStructure_.size()));
    preStructure_.push_back(Preset("0x8946D0","NHL", preStructure_.size()));
    preStructure_.push_back(Preset("0x8976B0","FIN Suomi Div, Deutschland Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x8CD5B0","OHL", preStructure_.size()));
    preStructure_.push_back(Preset("0x8FC620","UHL", preStructure_.size()));
    preStructure_.push_back(Preset("0x903BE0","Continental Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x905AF0","Champions Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x907160","Four Nations Cup (Czech Republic)", preStructure_.size()));
    preStructure_.push_back(Preset("0x907CB0","Four Nations Cup (Sweden)", preStructure_.size()));
    preStructure_.push_back(Preset("0x908780","Four Nations Cup (Finland)", preStructure_.size()));
    preStructure_.push_back(Preset("0x909290","Four Nations Cup (Russia)", preStructure_.size()));
    preStructure_.push_back(Preset("0x909D30","Slovak Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x90A820","Swiss Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x90CA20","Euro Challenge", preStructure_.size()));
    preStructure_.push_back(Preset("0x90E870","Euro Hockey Tour", preStructure_.size()));
    preStructure_.push_back(Preset("0x90FFC0","Olympic Pre-Qualification", preStructure_.size()));
    preStructure_.push_back(Preset("0x911590","Olympic Final Qualification", preStructure_.size()));
    preStructure_.push_back(Preset("0x9132E0","Olympic Hockey Tournament", preStructure_.size()));
    preStructure_.push_back(Preset("0x9152B0","World Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x916870","U20 World Championships (Div 1)", preStructure_.size()));
    preStructure_.push_back(Preset("0x918570","U20 World Championships", preStructure_.size()));
    preStructure_.push_back(Preset("0x91A730","World Championships (Div 1)", preStructure_.size()));
    preStructure_.push_back(Preset("0x91C800","World Championships", preStructure_.size()));
    preStructure_.push_back(Preset("0x923A90","FIN Mestis", preStructure_.size()));
    preStructure_.push_back(Preset("0x925BA0","FIN SM-League", preStructure_.size()));
    preStructure_.push_back(Preset("0x9271B0","DEN Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x928AC0","DEN Oddset", preStructure_.size()));
    preStructure_.push_back(Preset("0x92A1C0","GBR EPIHL Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x92C050","GBR EPIHL", preStructure_.size()));
    preStructure_.push_back(Preset("0x92DA50","GBR Challenge Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x92F800","GBR Elite", preStructure_.size()));
    preStructure_.push_back(Preset("0x930B00","SLO Interliga 2", preStructure_.size()));
    preStructure_.push_back(Preset("0x931D60","SLO Interliga 1", preStructure_.size()));
    preStructure_.push_back(Preset("0x9332F0","SLO Elite", preStructure_.size()));
    preStructure_.push_back(Preset("0x934FF0","CZE Extraliga", preStructure_.size()));
    preStructure_.push_back(Preset("0x936A90","NOR UPC-Ligean", preStructure_.size()));
    preStructure_.push_back(Preset("0x93AAB0","Memorial Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x93E5D0","QMJHL", preStructure_.size()));
    preStructure_.push_back(Preset("0x9416F0","GER Elite", preStructure_.size()));
    preStructure_.push_back(Preset("0x945070","RUS Superleague", preStructure_.size()));
    preStructure_.push_back(Preset("0x947930","AUT Elite", preStructure_.size()));
    preStructure_.push_back(Preset("0x9498D0","SVK Extraliga", preStructure_.size()));
    preStructure_.push_back(Preset("0x94B260","SWE Allsvenskan", preStructure_.size()));
    preStructure_.push_back(Preset("0x94DBA0","SWE Elitserien", preStructure_.size()));
    preStructure_.push_back(Preset("0x950680","All Stars, CAN-RUS Challenge, Exhibition Mini Cup", preStructure_.size()));
    preStructure_.push_back(Preset("0x954300","Exhibition Mini League", preStructure_.size()));

    // Push back the various competitions
    vect_.push_back(CompStructs("(AUT) Erste Bank Eishockey Liga", 0x7B5224, 0x7B52F8));
    vect_.push_back(CompStructs("(AUT) Austria All-Stars", 0x7B5130));
    vect_.push_back(CompStructs("(CAN) Ontario Hockey League", 0x7ADAC4));
    vect_.push_back(CompStructs("(CAN) Quebec Major Junior Hockey League", 0x7B4C20));
    vect_.push_back(CompStructs("(CAN) Western Hockey League", 0x7A5A05));
    vect_.push_back(CompStructs("(CAN) Memorial Cup", 0x7B4B18));
    vect_.push_back(CompStructs("(CAN) Canada-Russia Challenge", 0x7B4928));
    vect_.push_back(CompStructs("(CAN) CHL All-Stars", 0x7B4A20));
    vect_.push_back(CompStructs("(CZE) Extraliga", 0x7B4710));
    vect_.push_back(CompStructs("(DEN) Oddset Ligaen", 0x7B3E68));
    vect_.push_back(CompStructs("(DEN) Danish Cup", 0x7B3D7C));
    vect_.push_back(CompStructs("(FIN) SM-League", 0x7B3C74));
    vect_.push_back(CompStructs("(FIN) Mestis", 0x7B3B70));
    vect_.push_back(CompStructs("(FIN) Suomi Division", 0x7B3A60));
    vect_.push_back(CompStructs("(GBR) Elite Ice Hockey League", 0x7B428C));
    vect_.push_back(CompStructs("(GBR) English Premier Ice Hockey League", 0x7B407C));
    vect_.push_back(CompStructs("(GBR) Challenge Cup", 0x7B4188));
    vect_.push_back(CompStructs("(GBR) EPIHL Cup", 0x7B3F70));
    vect_.push_back(CompStructs("(GER) Deutsche Eishockey Liga", 0x7B4E1C));
    vect_.push_back(CompStructs("(GER) DEL All-Stars", 0x7B4D28));
    vect_.push_back(CompStructs("(NOR) UPC-Ligaen", 0x7B4820));
    vect_.push_back(CompStructs("(RUS) Superleague", 0x7B5020));
    vect_.push_back(CompStructs("(RUS) RSL All-Stars", 0x7B4F28));
    vect_.push_back(CompStructs("(SLO) Elite League", 0x7B4608));
    vect_.push_back(CompStructs("(SLO) Interliga 1", 0x7B44A8));
    vect_.push_back(CompStructs("(SLO) Interliga 2", 0x7B4398));
    vect_.push_back(CompStructs("(SVK) T-Com Extraliga", 0x7B5360, 0x7B5400, 0x7B53CC, 0x7B53D4, 0x7B5434));
    vect_.push_back(CompStructs("(SWE) Elitserien", 0x7B5574));
    vect_.push_back(CompStructs("(SWE) Allsvenskan", 0x7B5468));
    vect_.push_back(CompStructs("(USA) National Hockey League", 0x7A5C14, 0x0, 0x0, 0x0, 0x0, 67)); // There is a 00 straight after the text field (so we must manually specify the field length)
    vect_.push_back(CompStructs("(USA) American Hockey League", 0x7A5B0C));
    vect_.push_back(CompStructs("(USA) Central Hockey League", 0x7A57C8, 0x7A5898));
    vect_.push_back(CompStructs("(USA) East Coast Hockey League", 0x7A58FC));
    vect_.push_back(CompStructs("(USA) United Hockey League", 0x7B1C30));
    vect_.push_back(CompStructs("(USA) AHL All-Stars", 0x7B5968));
    vect_.push_back(CompStructs("(USA) CHL All-Stars", 0x7B5778));
    vect_.push_back(CompStructs("(USA) ECHL All-Stars", 0x7B5870));
    vect_.push_back(CompStructs("(USA) NHL All-Stars", 0x7B5A60));
    vect_.push_back(CompStructs("(USA) UHL All-Stars", 0x7B5680));
    vect_.push_back(CompStructs("(EUR) Continental Cup", 0x7B23E8, 0x7B24D8));
    vect_.push_back(CompStructs("(EUR) Champions Cup", 0x7B2540));
    vect_.push_back(CompStructs("(EXH) Exhibition Mini Cup", 0x7B5B58));
    vect_.push_back(CompStructs("(EXH) Exhibition Mini League", 0x7B5C48));
    vect_.push_back(CompStructs("(INT) Deutschland Cup", 0x7B2CE8, 0x0, 0x0, 0x0, 0x0, 63));
    vect_.push_back(CompStructs("(INT) Euro Challenge", 0x7B2DF8, 0x7B2F40));
    vect_.push_back(CompStructs("(INT) Euro Hockey Tour", 0x7B2FA8));
    vect_.push_back(CompStructs("(INT) Olympic Hockey Tournament", 0x7B3348));
    vect_.push_back(CompStructs("(INT) Olympic Final Qualification", 0x7B3228));
    vect_.push_back(CompStructs("(INT) Olympic Pre-Qualification", 0x7B30C0, 0x7B31C0));
    vect_.push_back(CompStructs("(INT) Slovak Cup", 0x7B2AC8));
    vect_.push_back(CompStructs("(INT) Swiss Cup", 0x7B2BD8));
    vect_.push_back(CompStructs("(INT) World Championships", 0x7B38C8, 0x7B39F8));
    vect_.push_back(CompStructs("(INT) World Championships (Div 1)", 0x7B37B0));
    vect_.push_back(CompStructs("(INT) World Cup", 0x7B3468));
    vect_.push_back(CompStructs("(U20) Four Nations Cup (Czech Republic)", 0x7B2658));
    vect_.push_back(CompStructs("(U20) Four Nations Cup (Finland)", 0x7B2890));
    vect_.push_back(CompStructs("(U20) Four Nations Cup (Russia)", 0x7B29B0));
    vect_.push_back(CompStructs("(U20) Four Nations Cup (Sweden)", 0x7B2778));
    vect_.push_back(CompStructs("(U20) World Championships", 0x7B3698));
    vect_.push_back(CompStructs("(U20) World Championships (Div 1)", 0x7B3580));
}


/* ================== */
/*      Set Data      */
/* ================== */

// Set league size
void CompStructs::setLeagueSize(int &i)
{
    sLeagueSize_.setIndex(i);

    data_->replace(sLeagueSize_.getPosInt(), preLeagueSize_[i].getSize(), preLeagueSize_[i].getRawData());
}

// Set playoffs
void CompStructs::setPlayoffs(int &i)
{
    sPlayoffs_.setIndex(i);

    data_->replace(sPlayoffs_.getPosInt(), prePlayoffs_[i].getSize(), prePlayoffs_[i].getRawData());
}

// Set schedule
void CompStructs::setSchedule(int &i)
{
    sSchedule_.setIndex(i);

    data_->replace(sSchedule_.getPosInt(), preSchedule_[i].getSize(), preSchedule_[i].getRawData());
}

// Set structure
void CompStructs::setStructure(int &i)
{
    sStructure_.setIndex(i);

    data_->replace(sStructure_.getPosInt(), preStructure_[i].getSize(), preStructure_[i].getRawData());
}
