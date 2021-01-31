#ifndef EDITOR_H
#define EDITOR_H

#include <QByteArray>
#include <QCloseEvent>
#include <QDataStream>
#include <QDesktopServices>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLocale>
#include <QMainWindow>
#include <QMessageBox>
#include <QString>

#include "comp_rules.h"
#include "comp_structs.h"
#include "editor_comp_names.h"
#include "editor_comp_rules.h"
#include "editor_comp_structs.h"
#include "editor_folder_paths.h"
#include "text.h"

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    QByteArray data_;

    explicit Editor(QWidget *parent = 0);
    ~Editor();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionAbout_triggered();

    void on_actionVisit_EHM_Hardcode_Editor_Forum_triggered();

    void on_actionExit_triggered();

private:
    Ui::Editor *ui;

    QLabel statusBar_;

    QString fileName_;
    QString filePath_;

    EditorCompNames *editorCompNames_;
    EditorCompRules *editorCompRules_;
    EditorCompStructs *editorCompStructs_;
    EditorFolderPaths *editorFolderPaths_;

    // I/O Functions
    bool openFile();
    bool saveFile();
    bool verifyFile();

    // Initialisation Functions
    void initData(bool enabled);
    bool initEditor(bool enabled);
    void initUI(bool enabled);

    // Set data
    void updateStatusBar();

    // Quit the application
    void closeEvent(QCloseEvent *event);
};

#endif // EDITOR_H
