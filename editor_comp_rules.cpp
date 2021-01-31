#include "editor_comp_rules.h"


/* =========================== */
/*      Class Constructor      */
/* =========================== */

// Default constructor
EditorCompRules::EditorCompRules(QWidget &parent) : parent_(&parent)
{
    // Dual column layout
    layoutMain_ = new QHBoxLayout;
    layoutRight_ = new QVBoxLayout;

    // List Widget
    listComps_ = new QListWidget;
    listComps_->setMinimumWidth(MIN_LIST_WIDGET_WIDTH);
    listComps_->setMaximumWidth(MAX_LIST_WIDGET_WIDTH);

    // Right column heading
    QFont font;
    font.setBold(true);
    font.setPointSize(16);

    // League heading / short name
    lblShortName_ = new QLabel("");
    lblShortName_->setFont(font);
    lblShortName_->setMaximumHeight(25);
    layoutRight_->addWidget(lblShortName_);

    // League/rule details
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

    // Line up rules
    frmLineUp_ = new QFormLayout;

    QLabel *lblLineUpPos = new QLabel("Offset:");
    lblLineUpPos_ = new QLabel();
    frmLineUp_->addRow(lblLineUpPos, lblLineUpPos_);

    QLabel *lblLineUpRelativePos = new QLabel("Relative position:");
    lblLineUpRelativePos_ = new QLabel();
    frmLineUp_->addRow(lblLineUpRelativePos, lblLineUpRelativePos_);

    QLabel *lblLineUpHex = new QLabel("Current setting:");
    lblLineUpHex_ = new QLabel();
    frmLineUp_->addRow(lblLineUpHex, lblLineUpHex_);

    QLabel *lblLineUpComboBox = new QLabel("Edit setting:");
    comboLineUp_ = new QComboBox();
    frmLineUp_->addRow(lblLineUpComboBox, comboLineUp_);

    grpLineUp_ = new QGroupBox("Line Up Rule");
    grpLineUp_->setLayout(frmLineUp_);
    layoutRight_->addWidget(grpLineUp_);

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
void EditorCompRules::init()
{
    listComps_->clear();

    // List widget containing competitions
    for(auto itr = CompRules::vect_.begin(); itr < CompRules::vect_.end(); ++itr)
        listComps_->addItem(new QListWidgetItem(itr->getShortName()));

    // Combo box of line up rules
    for(auto itr = CompRules::preLineUp_.begin(); itr < CompRules::preLineUp_.end(); ++itr)
        comboLineUp_->addItem(itr->getDescAndData());

    // Initialise the list widget with the first item/row (must be initialised before connecting the slots/signals)
    listComps_->setCurrentRow(0);

    // Combo boxes (must be connected after initialising the list widget - otherwise the first entry will be overwritten at start-up)
    QObject::connect(comboLineUp_, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboLineUp_currentIndexChanged(int)));  // Line up rule
}

// Clear list widget
void EditorCompRules::clear()
{
    listComps_->clear();
}


/* ============================ */
/*      List Box Functions      */
/* ============================ */

// Populate form with details of selected competition
void EditorCompRules::on_listComps_currentRowChanged(int currentRow)
{
    currentRow_ = currentRow;

    // Short name
    lblShortName_->setText(CompRules::vect_[currentRow_].getShortName());

    // Details
    lblLongName_->setText(CompRules::vect_[currentRow_].getLongName());
    lblOffsetA_->setText(CompRules::vect_[currentRow_].getOffsetA());
    lblOffsetB_->setText(CompRules::vect_[currentRow_].getOffsetB());

    // Line up rule
    lblLineUpPos_->setText(CompRules::vect_[currentRow_].getLineUpRulePos());
    lblLineUpRelativePos_->setText(CompRules::vect_[currentRow_].getLineUpRuleRelativePos());
    lblLineUpHex_->setText(CompRules::vect_[currentRow_].getLineUpRuleString());
    comboLineUp_->setCurrentIndex(CompRules::vect_[currentRow_].getLineUpRuleIndex());
}


/* ================================ */
/*      Line Up Rule Functions      */
/* ================================ */

// Update the line up rule following a change of selection on the combo box
void EditorCompRules::on_comboLineUp_currentIndexChanged(int currentIndex)
{
    CompRules::vect_[currentRow_].setLineUpRule(currentIndex);
    lblLineUpHex_->setText(CompRules::vect_[currentRow_].getLineUpRuleString());
}
