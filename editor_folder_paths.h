#ifndef EDITOR_FOLDER_PATHS_H
#define EDITOR_FOLDER_PATHS_H

#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QVector>
#include <QWidget>

#include "text.h"

class EditorFolderPaths : public QObject
{
    Q_OBJECT

private:
    // Parent widget and layout
    QWidget *parent_;
    QGridLayout *layout_;

    // Parent
    QVector<Text*> pathParent_;
    QGroupBox *groupParent_;
    QFormLayout *formParent_;

    // Data
    QVector<Text*> pathData_;
    QGroupBox *groupData_;
    QFormLayout *formData_;

    // Backgrounds
    QVector<Text*> pathBackgrounds_;
    QGroupBox *groupBackgrounds_;
    QFormLayout *formBackgrounds_;

    // Flags
    QVector<Text*> pathFlags_;
    QGroupBox *groupFlags_;
    QFormLayout *formFlags_;

    // Intro
    QVector<Text*> pathIntro_;
    QGroupBox *groupIntro_;
    QFormLayout *formIntro_;

    // Logos
    QVector<Text*> pathLogos_;
    QGroupBox *groupLogos_;
    QFormLayout *formLogos_;

    // My Documents
    QFormLayout *formMyDocs_;
    QGroupBox *groupMyDocs_;
    QVector<Text*> pathMyDocs_;

    // News
    QVector<Text*> pathNews_;
    QGroupBox *groupNews_;
    QFormLayout *formNews_;

    // Pictures
    QVector<Text*> pathPictures_;
    QGroupBox *groupPictures_;
    QFormLayout *formPictures_;

    // Rinks
    QVector<Text*> pathRinks_;
    QGroupBox *groupRinks_;
    QFormLayout *formRinks_;

public:
    EditorFolderPaths(QWidget &parent);
    EditorFolderPaths() {}
    ~EditorFolderPaths() {}

    void init();
    void initData();
    void initUI();
};

#endif // EDITOR_FOLDER_PATHS_H
