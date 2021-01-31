#ifndef EDITOR_COMP_STRUCTS_H
#define EDITOR_COMP_STRUCTS_H

#include <QComboBox>
#include <QFont>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QHBoxLayout>
#include <QObject>
#include <QSpacerItem>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>

#include "common.h"
#include "comp_structs.h"
#include "preset.h"

class EditorCompStructs : public QObject
{
    Q_OBJECT

private:
    // Parent
    QWidget *parent_;

    // Layout
    QVBoxLayout *layoutRight_;
    QHBoxLayout *layoutMain_;

    // Left column
    QListWidget *listComps_;

    // Right column
    QFormLayout *frmDetails_;
    QGroupBox *grpDetails_;
    QLabel *lblOffsetA_;
    QLabel *lblOffsetB_;
    QLabel *lblLongName_;
    QLabel *lblShortName_;

    // League size
    QFormLayout *frmLeagueSize_;
    QGroupBox *grpLeagueSize_;
    QLabel *lblLeagueSizeHex_;
    QLabel *lblLeagueSizePos_;
    QLabel *lblLeagueSizeRelativePos_;
    QComboBox * comboLeagueSize_;

    // Playoffs
    QFormLayout *frmPlayoffs_;
    QGroupBox *grpPlayoffs_;
    QLabel *lblPlayoffsHex_;
    QLabel *lblPlayoffsPos_;
    QLabel *lblPlayoffsRelativePos_;
    QComboBox * comboPlayoffs_;

    // Schedule
    QFormLayout *frmSchedule_;
    QGroupBox *grpSchedule_;
    QLabel *lblScheduleHex_;
    QLabel *lblSchedulePos_;
    QLabel *lblScheduleRelativePos_;
    QComboBox * comboSchedule_;

    // Structure
    QFormLayout *frmStructure_;
    QGroupBox *grpStructure_;
    QLabel *lblStructureHex_;
    QLabel *lblStructurePos_;
    QLabel *lblStructureRelativePos_;
    QComboBox * comboStructure_;

    int currentRow_;

private slots:
    void on_listComps_currentRowChanged(int currentRow);
    void on_comboLeagueSize_currentIndexChanged(int currentIndex);
    void on_comboPlayoffs_currentIndexChanged(int currentIndex);
    void on_comboSchedule_currentIndexChanged(int currentIndex);
    void on_comboStructure_currentIndexChanged(int currentIndex);

public:
    EditorCompStructs(QWidget &parent);
    EditorCompStructs() {}
    ~EditorCompStructs() {}

    void clear();
    void init();
};

#endif // EDITOR_COMP_STRUCTS_H
