#include "editor_comp_structs.h"

/* =========================== */
/*      Class Constructor      */
/* =========================== */

// Default constructor
EditorCompStructs::EditorCompStructs(QWidget &parent) : parent_(&parent)
{
    // Dual column layout
    layoutMain_ = new QHBoxLayout;
    layoutRight_ = new QVBoxLayout;

    // List Widget
    listComps_ = new QListWidget;
    listComps_->setMinimumWidth(MIN_LIST_WIDGET_WIDTH);
    listComps_->setMaximumWidth(MIN_LIST_WIDGET_WIDTH);

    // Right column heading
    QFont font;
    font.setBold(true);
    font.setPointSize(16);

    // League heading / short name
    lblShortName_ = new QLabel("");
    lblShortName_->setFont(font);
    lblShortName_->setMaximumHeight(25);
    layoutRight_->addWidget(lblShortName_);

    // League/structure details
    frmDetails_ = new QFormLayout;

    QLabel *lblLongName = new QLabel("Long Name:");
    lblLongName_ = new QLabel();
    frmDetails_->addRow(lblLongName, lblLongName_);

    QLabel *lblOffsetA = new QLabel("Offset A:");
    lblOffsetA_ = new QLabel();
    frmDetails_->addRow(lblOffsetA, lblOffsetA_);

    QLabel *lblOffsetB = new QLabel("Offset B:");
    lblOffsetB_ = new QLabel();
    frmDetails_->addRow(lblOffsetB, lblOffsetB_);

    grpDetails_ = new QGroupBox("Details");
    grpDetails_->setLayout(frmDetails_);
    layoutRight_->addWidget(grpDetails_);

    // League size
    frmLeagueSize_ = new QFormLayout;

    QLabel *lblLeagueSizePos = new QLabel("Offset:");
    lblLeagueSizePos_ = new QLabel();
    frmLeagueSize_->addRow(lblLeagueSizePos, lblLeagueSizePos_);

    QLabel *lblLeagueSizeRelativePos = new QLabel("Relative position:");
    lblLeagueSizeRelativePos_ = new QLabel();
    frmLeagueSize_->addRow(lblLeagueSizeRelativePos, lblLeagueSizeRelativePos_);

    QLabel *lblLeagueSizeHex = new QLabel("Current setting:");
    lblLeagueSizeHex_ = new QLabel();
    frmLeagueSize_->addRow(lblLeagueSizeHex, lblLeagueSizeHex_);

    QLabel *lblLeagueSizeComboBox = new QLabel("Edit setting:");
    comboLeagueSize_ = new QComboBox();
    frmLeagueSize_->addRow(lblLeagueSizeComboBox, comboLeagueSize_);

    grpLeagueSize_ = new QGroupBox("League Size");
    grpLeagueSize_->setLayout(frmLeagueSize_);
    layoutRight_->addWidget(grpLeagueSize_);

    // Playoffs
    frmPlayoffs_ = new QFormLayout;

    QLabel *lblPlayoffsPos = new QLabel("Offset:");
    lblPlayoffsPos_ = new QLabel();
    frmPlayoffs_->addRow(lblPlayoffsPos, lblPlayoffsPos_);

    QLabel *lblPlayoffsRelativePos = new QLabel("Relative position:");
    lblPlayoffsRelativePos_ = new QLabel();
    frmPlayoffs_->addRow(lblPlayoffsRelativePos, lblPlayoffsRelativePos_);

    QLabel *lblPlayoffsHex = new QLabel("Current setting:");
    lblPlayoffsHex_ = new QLabel();
    frmPlayoffs_->addRow(lblPlayoffsHex, lblPlayoffsHex_);

    QLabel *lblPlayoffsComboBox = new QLabel("Edit setting:");
    comboPlayoffs_ = new QComboBox();
    frmPlayoffs_->addRow(lblPlayoffsComboBox, comboPlayoffs_);

    grpPlayoffs_ = new QGroupBox("Playoffs");
    grpPlayoffs_->setLayout(frmPlayoffs_);
    layoutRight_->addWidget(grpPlayoffs_);

    // Schedule
    frmSchedule_ = new QFormLayout;

    QLabel *lblSchedulePos = new QLabel("Offset:");
    lblSchedulePos_ = new QLabel();
    frmSchedule_->addRow(lblSchedulePos, lblSchedulePos_);

    QLabel *lblScheduleRelativePos = new QLabel("Relative position:");
    lblScheduleRelativePos_ = new QLabel();
    frmSchedule_->addRow(lblScheduleRelativePos, lblScheduleRelativePos_);

    QLabel *lblScheduleHex = new QLabel("Current setting:");
    lblScheduleHex_ = new QLabel();
    frmSchedule_->addRow(lblScheduleHex, lblScheduleHex_);

    QLabel *lblScheduleComboBox = new QLabel("Edit setting:");
    comboSchedule_ = new QComboBox();
    frmSchedule_->addRow(lblScheduleComboBox, comboSchedule_);

    grpSchedule_ = new QGroupBox("Schedule / Playoff Structure");
    grpSchedule_->setLayout(frmSchedule_);
    layoutRight_->addWidget(grpSchedule_);

    // Structure
    frmStructure_ = new QFormLayout;

    QLabel *lblStructurePos = new QLabel("Offset:");
    lblStructurePos_ = new QLabel();
    frmStructure_->addRow(lblStructurePos, lblStructurePos_);

    QLabel *lblStructureRelativePos = new QLabel("Relative position:");
    lblStructureRelativePos_ = new QLabel();
    frmStructure_->addRow(lblStructureRelativePos, lblStructureRelativePos_);

    QLabel *lblStructureHex = new QLabel("Current setting:");
    lblStructureHex_ = new QLabel();
    frmStructure_->addRow(lblStructureHex, lblStructureHex_);

    QLabel *lblStructureComboBox = new QLabel("Edit setting:");
    comboStructure_ = new QComboBox();
    frmStructure_->addRow(lblStructureComboBox, comboStructure_);

    grpStructure_ = new QGroupBox("League Structure / Playoff Structure / OT Rule");
    grpStructure_->setLayout(frmStructure_);
    layoutRight_->addWidget(grpStructure_);

    QSpacerItem *spacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layoutRight_->addItem(spacer);

    // Set layout
    layoutMain_->addWidget(listComps_);         // List widget -> main layout
    layoutMain_->addLayout(layoutRight_);       // Right column -> main layout
    parent_->setLayout(layoutMain_);            // Main layout -> tab widget

    QObject::connect(listComps_, SIGNAL(currentRowChanged(int)), this, SLOT(on_listComps_currentRowChanged(int)));  // List widget
}


/* ============================= */
/*      Data Initialisation      */
/* ============================= */

// Initialise data
void EditorCompStructs::init()
{
    listComps_->clear();

    // List widget containing competitions
    for(auto itr = CompStructs::vect_.begin(); itr < CompStructs::vect_.end(); ++itr)
        listComps_->addItem(new QListWidgetItem(itr->getShortName()));

    // Combo box of league sizes
    for(auto itr = CompStructs::preLeagueSize_.begin(); itr < CompStructs::preLeagueSize_.end(); ++itr)
        comboLeagueSize_->addItem(itr->getDescAndData());

    // Combo box of playoffs
    for(auto itr = CompStructs::prePlayoffs_.begin(); itr < CompStructs::prePlayoffs_.end(); ++itr)
        comboPlayoffs_->addItem(itr->getDescAndData());

    // Combo box of schedules
    for(auto itr = CompStructs::preSchedule_.begin(); itr < CompStructs::preSchedule_.end(); ++itr)
        comboSchedule_->addItem(itr->getDescAndData());

    // Combo box of structures
    for(auto itr = CompStructs::preStructure_.begin(); itr < CompStructs::preStructure_.end(); ++itr)
        comboStructure_->addItem(itr->getDescAndData());

    // Initialise the list widget with the first item/row (must be initialised before connecting the slots/signals)
    listComps_->setCurrentRow(0);

    // Combo boxes (must be connected after initialising the list widget - otherwise the first entry will be overwritten at start-up)
    QObject::connect(comboLeagueSize_, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboLeagueSize_currentIndexChanged(int)));  // League size
    QObject::connect(comboPlayoffs_, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboPlayoffs_currentIndexChanged(int)));  // Playoffs
    QObject::connect(comboSchedule_, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboSchedule_currentIndexChanged(int)));  // Schedule
    QObject::connect(comboStructure_, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboStructure_currentIndexChanged(int)));  // Structure
}

// Clear list widget
void EditorCompStructs::clear()
{
    listComps_->clear();
}


/* ============================ */
/*      List Box Functions      */
/* ============================ */

// Populate form with details of selected competition
void EditorCompStructs::on_listComps_currentRowChanged(int currentRow)
{
    currentRow_ = currentRow;

    // Short name
    lblShortName_->setText(CompStructs::vect_[currentRow_].getShortName());
    //lblShortName_->setText(QString::number(CompStructs::vect_[currentRow_].getPlayoffsIndex()));

    // Details
    lblLongName_->setText(CompStructs::vect_[currentRow_].getLongName());
    lblOffsetA_->setText(CompStructs::vect_[currentRow_].getOffsetA());
    lblOffsetB_->setText(CompStructs::vect_[currentRow_].getOffsetB());

    // League Size
    lblLeagueSizePos_->setText(CompStructs::vect_[currentRow_].getLeagueSizePos());
    lblLeagueSizeRelativePos_->setText(CompStructs::vect_[currentRow_].getLeagueSizeRelativePos());
    lblLeagueSizeHex_->setText(CompStructs::vect_[currentRow_].getLeagueSizeString());
    comboLeagueSize_->setCurrentIndex(CompStructs::vect_[currentRow_].getLeagueSizeIndex());

    // Playoffs
    lblPlayoffsPos_->setText(CompStructs::vect_[currentRow_].getPlayoffsPos());
    lblPlayoffsRelativePos_->setText(CompStructs::vect_[currentRow_].getPlayoffsRelativePos());
    lblPlayoffsHex_->setText(CompStructs::vect_[currentRow_].getPlayoffsString());
    comboPlayoffs_->setCurrentIndex(CompStructs::vect_[currentRow_].getPlayoffsIndex());

    // Schedule
    lblSchedulePos_->setText(CompStructs::vect_[currentRow_].getSchedulePos());
    lblScheduleRelativePos_->setText(CompStructs::vect_[currentRow_].getScheduleRelativePos());
    lblScheduleHex_->setText(CompStructs::vect_[currentRow_].getScheduleString());
    comboSchedule_->setCurrentIndex(CompStructs::vect_[currentRow_].getScheduleIndex());

    // Structure
    lblStructurePos_->setText(CompStructs::vect_[currentRow_].getStructurePos());
    lblStructureRelativePos_->setText(CompStructs::vect_[currentRow_].getStructureRelativePos());
    lblStructureHex_->setText(CompStructs::vect_[currentRow_].getStructureString());
    comboStructure_->setCurrentIndex(CompStructs::vect_[currentRow_].getStructureIndex());
}


/* =============================== */
/*      League Size Functions      */
/* =============================== */

// Update the line up rule following a change of selection on the combo box
void EditorCompStructs::on_comboLeagueSize_currentIndexChanged(int currentIndex)
{
    CompStructs::vect_[currentRow_].setLeagueSize(currentIndex);
    lblLeagueSizeHex_->setText(CompStructs::vect_[currentRow_].getLeagueSizeString());
}


/* ============================ */
/*      Playoffs Functions      */
/* ============================ */

// Update the line up rule following a change of selection on the combo box
void EditorCompStructs::on_comboPlayoffs_currentIndexChanged(int currentIndex)
{
    CompStructs::vect_[currentRow_].setPlayoffs(currentIndex);
    lblPlayoffsHex_->setText(CompStructs::vect_[currentRow_].getPlayoffsString());
}


/* ============================ */
/*      Schedule Functions      */
/* ============================ */

// Update the line up rule following a change of selection on the combo box
void EditorCompStructs::on_comboSchedule_currentIndexChanged(int currentIndex)
{
    CompStructs::vect_[currentRow_].setSchedule(currentIndex);
    lblScheduleHex_->setText(CompStructs::vect_[currentRow_].getScheduleString());
}


/* ============================= */
/*      Structure Functions      */
/* ============================= */

// Update the line up rule following a change of selection on the combo box
void EditorCompStructs::on_comboStructure_currentIndexChanged(int currentIndex)
{
    CompStructs::vect_[currentRow_].setStructure(currentIndex);
    lblStructureHex_->setText(CompStructs::vect_[currentRow_].getStructureString());
}
