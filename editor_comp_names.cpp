#include "editor_comp_names.h"

/* =========================== */
/*      Class Constructor      */
/* =========================== */

// Default constructor
EditorCompNames::EditorCompNames(QWidget &parent) : parent_(&parent)
{
    // Dual column layout
    layoutMain_ = new QHBoxLayout;
    layoutStack_ = new QStackedLayout;

    // List Widget
    listNations_ = new QListWidget;
    listNations_->setMinimumWidth(MIN_LIST_WIDGET_WIDTH);
    listNations_->setMaximumWidth(MIN_LIST_WIDGET_WIDTH);

    // Set layout
    layoutMain_->addWidget(listNations_);   // List widget -> main layout
    layoutMain_->addLayout(layoutStack_);   // Stacked widget -> main layout
    parent_->setLayout(layoutMain_);        // Main layout -> tab widget

    QObject::connect(listNations_, SIGNAL(currentRowChanged(int)), layoutStack_, SLOT(setCurrentIndex(int)));  // List widget
}


/* ============================= */
/*      Data Initialisation      */
/* ============================= */

// Initialise data
void EditorCompNames::init()
{
    initData();
    initUI();
}

// Initialise the data
void EditorCompNames::initData()
{
    // Have gotten as far as T-Com Extraliga 0x732A80

    // Temporary vector
    QVector<Text*> tmp;
    tmp.reserve(50);

    // International
    tmp.clear();
    itemNations_.push_back("International");
    tmp.push_back(new Text(0x737414, "World Championships"));
    tmp.push_back(new Text(0x7374E0, "World Championships Div 1"));
    tmp.push_back(new Text(0x737500, "World Championships Div 2"));
    tmp.push_back(new Text(0x737428, "World Junior Championships U-20"));
    tmp.push_back(new Text(0x737638, "World Junior Championships U-20 Div 1"));
    tmp.push_back(new Text(0x737448, "World Junior Championships U-18"));
    tmp.push_back(new Text(0x737468, "Olympic Hockey Tournament"));
    tmp.push_back(new Text(0x73761C, "Olympic Final Qualification"));
    tmp.push_back(new Text(0x737600, "Olympic Pre-Qualification"));
    tmp.push_back(new Text(0x737484, "World Cup"));
    tmp.push_back(new Text(0x737530, "Euro Ice Hockey Challenge"));
    tmp.push_back(new Text(0x737490, "European Hockey Tour"));
    tmp.push_back(new Text(0x7374A8, "Finland Games"));
    tmp.push_back(new Text(0x7374B8, "Czech Cup"));
    tmp.push_back(new Text(0x7374C4, "ROSNO Cup"));
    tmp.push_back(new Text(0x73754C, "Slovak Cup"));
    tmp.push_back(new Text(0x7374D0, "Sweden Cup"));
    tmp.push_back(new Text(0x737520, "Deutschland Cup"));
    tmp.push_back(new Text(0x7375B4, "Czech Four Nations U-20"));
    tmp.push_back(new Text(0x737564, "Finnish Four Nations U-20"));
    tmp.push_back(new Text(0x73758C, "Russian Four Nations U-20"));
    tmp.push_back(new Text(0x7375D8, "Swedish Four Nations U-20"));
    names_.push_back(tmp);

    // Austria
    tmp.clear();
    itemNations_.push_back("Austria");
    tmp.push_back(new Text(0x7329D0, "Erste Bank Eishockey Liga"));
    names_.push_back(tmp);

    // Canada
    tmp.clear();
    itemNations_.push_back("Canada");
    tmp.push_back(new Text(0x7328AC, "Ontario Hockey League"));
    tmp.push_back(new Text(0x7328C4, "Quebec Major Junior Hockey League"));
    tmp.push_back(new Text(0x732894, "Western Hockey League"));
    names_.push_back(tmp);

    // Czech Republic
    tmp.clear();
    itemNations_.push_back("Czech Republic");
    tmp.push_back(new Text(0x73292C, "Extraliga"));
    tmp.push_back(new Text(0x732940, "Elite League (Extraliga)"));
    names_.push_back(tmp);

    // Finland
    tmp.clear();
    itemNations_.push_back("Finland");
    tmp.push_back(new Text(0x7327E0, "SM-League"));
    tmp.push_back(new Text(0x7327F4, "Elite League / SM-League"));
    tmp.push_back(new Text(0x73280C, "Mestis"));
    tmp.push_back(new Text(0x73281C, "National League / Mestis"));
    tmp.push_back(new Text(0x732A50, "Suomi Division"));
    tmp.push_back(new Text(0x732A68, "First Division / Suomi Div"));
    names_.push_back(tmp);

    // Germany
    tmp.clear();
    itemNations_.push_back("Germany");
    tmp.push_back(new Text(0x732914, "Deutsche Eishockey Liga"));
    names_.push_back(tmp);

    // Great Britain
    tmp.clear();
    itemNations_.push_back("Great Britain");
    tmp.push_back(new Text(0x73297C, "Ice Hockey Superleague"));
    names_.push_back(tmp);

    // Italy
    tmp.clear();
    itemNations_.push_back("Italy");
    tmp.push_back(new Text(0x7329F4, "Serie A2"));
    tmp.push_back(new Text(0x732A08, "Division 1 / A2"));
    names_.push_back(tmp);

    // Russia
    tmp.clear();
    itemNations_.push_back("Russia");
    tmp.push_back(new Text(0x7328E8, "Superleague"));
    tmp.push_back(new Text(0x7328FC, "Elite League / RSL"));
    names_.push_back(tmp);

    // Sweden
    tmp.clear();
    itemNations_.push_back("Sweden");
    tmp.push_back(new Text(0x732834, "Elitserien"));
    names_.push_back(tmp);

    // Switzerland
    tmp.clear();
    itemNations_.push_back("Switzerland");
    tmp.push_back(new Text(0x7329A4, "National League A"));
    tmp.push_back(new Text(0x7329BC, "Elite League / NLA"));
    names_.push_back(tmp);

    // United States
    tmp.clear();
    itemNations_.push_back("United States");
    tmp.push_back(new Text(0x7327C8, "National Hockey League"));
    tmp.push_back(new Text(0x732848, "American Hockey League"));
    tmp.push_back(new Text(0x732860, "All-American League / AHL"));
    tmp.push_back(new Text(0x732874, "ECHL"));
    tmp.push_back(new Text(0x73287C, "All-American League 2 / ECHL"));
    tmp.push_back(new Text(0x732A20, "United Hockey League"));
    tmp.push_back(new Text(0x732A38, "All-American League 4 / UHL"));
    tmp.push_back(new Text(0x732954, "Hockey East"));
    tmp.push_back(new Text(0x732960, "US Colleage East / Hockey East"));
    names_.push_back(tmp);
}

// Initialise the UI
void EditorCompNames::initUI()
{
    // List widget containing nations
    listNations_->clear();

    for(int i = 0; i < itemNations_.size(); ++i) {
        listNations_->addItem(new QListWidgetItem(itemNations_[i]));    // Add each nation to the list widget
        formNations_.push_back(new QFormLayout);                        // Add form layouts for each nation
        pageNations_.push_back(new QWidget);                            // Add widget page for each nation
        Text::initForm(formNations_[i], names_[i]);                     // Initialise forms with text and labels
        pageNations_[i]->setLayout(formNations_[i]);                    // Add page widgets to the stacked layout
        layoutStack_->addWidget(pageNations_[i]);                       // Add stacked layout to tab
    }

    listNations_->setCurrentRow(0);
}
