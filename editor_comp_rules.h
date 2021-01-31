#ifndef EDITOR_COMP_RULES_H
#define EDITOR_COMP_RULES_H

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
#include "comp_rules.h"
#include "preset.h"

class EditorCompRules : public QObject
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

    // Line up rules
    QFormLayout *frmLineUp_;
    QGroupBox *grpLineUp_;
    QLabel *lblLineUpHex_;
    QLabel *lblLineUpPos_;
    QLabel *lblLineUpRelativePos_;
    QComboBox * comboLineUp_;

    int currentRow_;

private slots:
    void on_listComps_currentRowChanged(int currentRow);
    void on_comboLineUp_currentIndexChanged(int currentIndex);

public:
    EditorCompRules(QWidget &parent);
    EditorCompRules() {}
    ~EditorCompRules() {}

    void clear();
    void init();
};

#endif // EDITOR_COMP_RULES_H
