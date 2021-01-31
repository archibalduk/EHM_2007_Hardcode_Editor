#include "editor_folder_paths.h"

/* =========================== */
/*      Class Constructor      */
/* =========================== */

// Default constructor
EditorFolderPaths::EditorFolderPaths(QWidget &parent) : parent_(&parent)
{
    layout_ = new QGridLayout(parent_);

    groupParent_ = new QGroupBox("Parent Folder");
    formParent_ = new QFormLayout;
    groupParent_->setLayout(formParent_);
    layout_->addWidget(groupParent_, 0, 0);

    groupMyDocs_ = new QGroupBox("My Documents");
    formMyDocs_ = new QFormLayout;
    groupMyDocs_->setLayout(formMyDocs_);
    layout_->addWidget(groupMyDocs_, 1, 0);

    groupData_ = new QGroupBox("Data");
    formData_ = new QFormLayout;
    groupData_->setLayout(formData_);
    layout_->addWidget(groupData_, 2, 0, 2, 1);

    groupPictures_ = new QGroupBox("Data\\Pictures");
    formPictures_ = new QFormLayout;
    groupPictures_->setLayout(formPictures_);
    layout_->addWidget(groupPictures_, 0, 1);

    groupBackgrounds_ = new QGroupBox("Data\\Pictures\\Backgrounds");
    formBackgrounds_ = new QFormLayout;
    groupBackgrounds_->setLayout(formBackgrounds_);
    layout_->addWidget(groupBackgrounds_, 1, 1, 2, 1);

    groupFlags_ = new QGroupBox("Data\\Pictures\\Flags");
    formFlags_ = new QFormLayout;
    groupFlags_->setLayout(formFlags_);
    layout_->addWidget(groupFlags_, 3, 1);

    groupIntro_ = new QGroupBox("Data\\Pictures\\Intro");
    formIntro_ = new QFormLayout;
    groupIntro_->setLayout(formIntro_);
    layout_->addWidget(groupIntro_, 0, 2);

    groupLogos_ = new QGroupBox("Data\\Pictures\\Logos");
    formLogos_ = new QFormLayout;
    groupLogos_->setLayout(formLogos_);
    layout_->addWidget(groupLogos_, 1, 2, 3, 1);

    groupNews_ = new QGroupBox("Data\\Pictures\\News");
    formNews_ = new QFormLayout;
    groupNews_->setLayout(formNews_);
    layout_->addWidget(groupNews_, 0, 3, 2, 1);

    groupRinks_ = new QGroupBox("Data\\Pictures\\Rinks");
    formRinks_ = new QFormLayout;
    groupRinks_->setLayout(formRinks_);
    layout_->addWidget(groupRinks_, 2, 3, 2, 1);
}


/* ============================= */
/*      Data Initialisation      */
/* ============================= */

// Initialise the data and the UI
void EditorFolderPaths::init()
{
    initData();
    initUI();
}

// Initialise the data
void EditorFolderPaths::initData()
{
    // EHM/
    pathParent_.push_back(new Text(0x798C20, "Data"));
    pathParent_.push_back(new Text(0x798BA0, "Prefs"));
    pathParent_.push_back(new Text(0x798BC0, "Temp"));

    // EHM/Data/    
    pathData_.push_back(new Text(0x798BF8, "Database"));
    pathData_.push_back(new Text(0x798B78, "Fast Start"));
    pathData_.push_back(new Text(0x798B70, "Fonts"));
    pathData_.push_back(new Text(0x798B94, "Formations"));
    pathData_.push_back(new Text(0x798BD8, "Hints"));
    pathData_.push_back(new Text(0x798C04, "Languages"));
    pathData_.push_back(new Text(0x798BE0, "Match Events"));
    pathData_.push_back(new Text(0x798C18, "Media"));
    pathData_.push_back(new Text(0x798B88, "Pictures"));
    pathData_.push_back(new Text(0x798C10, "Skins"));
    pathData_.push_back(new Text(0x798B80, "Sounds"));

    // EHM/Data/Pictures
    pathPictures_.push_back(new Text(0x621858, "Misc"));
    pathPictures_.push_back(new Text(0x6218F4, "Nonplayers"));
    pathPictures_.push_back(new Text(0x621908, "Players"));
    pathPictures_.push_back(new Text(0x621918, "Users"));

    // EHM/Data/Pictures/Backgrounds
    pathBackgrounds_.push_back(new Text(0x74FD34, "Awards"));
    pathBackgrounds_.push_back(new Text(0x74FCF8, "Clubs"));
    pathBackgrounds_.push_back(new Text(0x74FCE0, "Comps"));
    pathBackgrounds_.push_back(new Text(0x74FD14, "Nations"));
    pathBackgrounds_.push_back(new Text(0x74FD50, "Nonplayers"));
    pathBackgrounds_.push_back(new Text(0x74FD70, "Players"));
    pathBackgrounds_.push_back(new Text(0x74FD8C, "Users"));

    // EHM/Data/Pictures/Flags
    pathFlags_.push_back(new Text(0x621814, "Flags"));
    pathFlags_.push_back(new Text(0x621828, "Left"));
    pathFlags_.push_back(new Text(0x621840, "Right"));

    // EHM/Data/Pictures/Intro
    pathIntro_.push_back(new Text(0x74F848, "License"));
    pathIntro_.push_back(new Text(0x74F858, "SEGA"));
    pathIntro_.push_back(new Text(0x74F868, "SI"));
    pathIntro_.push_back(new Text(0x74F820, "Warchild"));

    // EHM/Data/Pictures/Logos
    pathLogos_.push_back(new Text(0x6217A0, "Huge"));
    pathLogos_.push_back(new Text(0x6217A8, "Large"));
    pathLogos_.push_back(new Text(0x6217B0, "Medium"));
    pathLogos_.push_back(new Text(0x6217B8, "Small"));
    pathLogos_.push_back(new Text(0x6217DC, "Awards"));
    pathLogos_.push_back(new Text(0x621860, "Club Default"));
    pathLogos_.push_back(new Text(0x6217DC, "Clubs"));
    pathLogos_.push_back(new Text(0x6217F4, "Clubs Away"));
    pathLogos_.push_back(new Text(0x621A38, "Comps"));
    pathLogos_.push_back(new Text(0x621A50, "Comps"));
    pathLogos_.push_back(new Text(0x621A68, "Comps"));
    pathLogos_.push_back(new Text(0x621AD9, "Czech PO"));
    pathLogos_.push_back(new Text(0x621A80, "NHLPA"));

    // EHM/Data/Pictures/News
    pathNews_.push_back(new Text(0x6218A9, "Set 1"));
    pathNews_.push_back(new Text(0x6218B1, "Set 1"));
    pathNews_.push_back(new Text(0x6218B8, "Awards"));
    pathNews_.push_back(new Text(0x621878, "Clubs"));
    pathNews_.push_back(new Text(0x621AB0, "Comps"));
    pathNews_.push_back(new Text(0x621AC4, "Comps"));
    pathNews_.push_back(new Text(0x621890, "Nations"));
    pathNews_.push_back(new Text(0x621A9C, "Players"));

    // EHM/Data/Pictures/Rinks
    pathRinks_.push_back(new Text(0x621940, "Rinks"));
    pathRinks_.push_back(new Text(0x62194C, "Boards"));
    pathRinks_.push_back(new Text(0x62197C, "Faceoff"));
    pathRinks_.push_back(new Text(0x621A20, "Faceoff *_B"));
    pathRinks_.push_back(new Text(0x62195C, "Faceoff Default"));
    pathRinks_.push_back(new Text(0x621990, "Faceoff Default B1"));
    pathRinks_.push_back(new Text(0x6219B4, "Faceoff Default B2"));
    pathRinks_.push_back(new Text(0x6219D8, "Faceoff Default B3"));
    pathRinks_.push_back(new Text(0x6219FC, "Faceoff Default B4"));

    // My Documents/Sports Interactive/EHM 2007/
    pathMyDocs_.push_back(new Text(0x798B44, "Games"));
    pathMyDocs_.push_back(new Text(0x798B4C, "Print"));
    pathMyDocs_.push_back(new Text(0x798B54, "Search"));
    pathMyDocs_.push_back(new Text(0x798B68, "Tactics"));
    pathMyDocs_.push_back(new Text(0x798B5C, "Training"));
}

// Initialise the user interface
void EditorFolderPaths::initUI()
{
    Text::initForm(formParent_, pathParent_);
    Text::initForm(formBackgrounds_, pathBackgrounds_);
    Text::initForm(formData_, pathData_);
    Text::initForm(formFlags_, pathFlags_);
    Text::initForm(formIntro_, pathIntro_);
    Text::initForm(formLogos_, pathLogos_);
    Text::initForm(formNews_, pathNews_);
    Text::initForm(formMyDocs_, pathMyDocs_);
    Text::initForm(formPictures_, pathPictures_);
    Text::initForm(formRinks_, pathRinks_);
}
