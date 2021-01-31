#include "editor.h"
#include "ui_editor.h"

Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);

    // Setup the application details and window title
    qApp->setApplicationName("EHM 2007 Hardcode Editor");
    qApp->setApplicationVersion("0.0.3");
    this->setWindowTitle(qApp->applicationName() + " v" + qApp->applicationVersion());
    this->setMinimumSize(1024, 700);

    // Application icon
    qApp->setWindowIcon(QIcon("tbl.ico"));

    // Application images
    ui->logoContainer->setPixmap(QPixmap(":/images/logo_128.png"));

    // Default file name and path
    fileName_ = "ehm2007.exe";
    filePath_ = "C:/Program Files (x86)/Sports Interactive/NHL Eastside Hockey Manager 2007/";

    // Status bar
    statusBar()->addPermanentWidget(&statusBar_);

    // Setup the UI
    editorCompNames_ = new EditorCompNames((*ui->tabCompNames));
    editorCompRules_ = new EditorCompRules((*ui->tabCompRules));
    editorCompStructs_ = new EditorCompStructs((*ui->tabCompStructs));
    editorFolderPaths_ = new EditorFolderPaths((*ui->tabFolderPaths));
    initEditor(false);
}

Editor::~Editor()
{
    initEditor(false);
    delete ui;
}


/* ================================== */
/*      Initialisation Functions      */
/* ================================== */

// Initialise the editor
bool Editor::initEditor(bool enabled)
{
   initData(enabled);
   initUI(enabled);

   return enabled;
}

// Initialise the data
void Editor::initData(bool enabled)
{
    // If disabled, clear all data
    if(!enabled) {
        data_.clear();        
        return;
    }

    // Else initialise the data
    CompRules::init(data_);
    CompStructs::init(data_);
    Text::init(data_);
    editorCompNames_->init();
    editorCompRules_->init();
    editorCompStructs_->init();
    editorFolderPaths_->init();
}

// Initialise the UI
void Editor::initUI(bool enabled)
{
    // Menu items
    ui->actionSave->setEnabled(enabled);
    ui->actionSave_As->setEnabled(enabled);

    // Tab widget
    ui->tabWidget->setCurrentIndex(0);
/*    for(unsigned char i = 1; i <= ui->tabWidget->count(); ++i)
        ui->tabWidget->setTabEnabled(i, enabled);
*/
    // Disable the UI
    if(!enabled) {
        // Status bar
        statusBar_.setText(tr("No file loaded."));

        return;
    }

    // Else enable the UI
    ui->actionOpen->setEnabled(false);
    updateStatusBar();
}


/* ======================= */
/*      I/O Functions      */
/* ======================= */

// Open exe file and read the data
bool Editor::openFile()
{
    data_.clear();

    QFile file(filePath_ + fileName_);

    if(!file.open(QIODevice::ReadOnly) || file.size() == 0) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to open file."));
        return false;
    }

    data_ = file.readAll();

    file.close();
    return initEditor(verifyFile()); // Verify the file, initialise the data and return whether or not it is valid
}

// Save exe file to disk
bool Editor::saveFile()
{
    QFile file(filePath_ + fileName_);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to save file."));
        return false;
    }

    file.write(data_);
    file.close();

    return true;
}

// Verify file
bool Editor::verifyFile()
{
    if(data_.size() != 9531392) {
        QMessageBox::critical(this, tr("Error"), tr("Unexpected file size."));
        data_.clear();
        return false;
    }

    return true;
}


/* ==================== */
/*      Menu Items      */
/* ==================== */

// File -> Open
void Editor::on_actionOpen_triggered()
{

    fileName_ = QFileDialog::getOpenFileName(this, tr("Open EHM 2007 Executable (v3.0.4)"),
                                                filePath_,
                                                tr("EHM 2007 Executable (*.exe)"));

    if(!fileName_.isEmpty()) {
        QFileInfo file(fileName_);
        filePath_ = file.path() + "/";
        fileName_ = file.fileName();

        openFile();    // Open the file
    }
}

// File -> Save
void Editor::on_actionSave_triggered()
{
    saveFile();
}

// File -> Save As
void Editor::on_actionSave_As_triggered()
{
    QString fileSaveAs = QFileDialog::getSaveFileName(this, tr("Save EHM 2007 Executable (v3.0.4)"),
                                                        (filePath_ + fileName_),
                                                        tr("EHM 2007 Executable (*.exe)"));

    if(!fileSaveAs.isEmpty()) {
        QFileInfo file(fileSaveAs);
        filePath_ = file.path();
        filePath_ += "/";
        fileName_ = file.fileName();

        saveFile();
    }

    updateStatusBar();
}


/* ================== */
/*      Set Data      */
/* ================== */

// Update the status bar
void Editor::updateStatusBar()
{
    QLocale locale;
    QString fileSize = locale.toString(data_.size());
    statusBar_.setText(filePath_ + fileName_ + " (" + fileSize + " bytes)");
}


/* =============================== */
/*      About the Application      */
/* =============================== */

// --- About the EHM Updater --- //
void Editor::on_actionAbout_triggered()
{
    QMessageBox *about = new QMessageBox;

    about->setIconPixmap(QPixmap(":/images/logo_64.png"));
    about->setWindowTitle("About EHM 2007 Hardcode Editor");
    about->setText("<font size='4'><b>" + qApp->applicationName() + "</b></font>");
    about->setInformativeText("Version " + qApp->applicationVersion() + " (" + QString::fromLocal8Bit(BUILDDATE) + " " + QString::fromLocal8Bit(BUILDTIME) + ")<br /><br />By Archibalduk<br /><br /><a href='mailto:archibalduk@gmail.com'>archibalduk@gmail.com</a><br /><a href='http://www.ehmtheblueline.com'>http://www.ehmtheblueline.com</a>");
    about->setStandardButtons(QMessageBox::Ok);
    about->setDefaultButton(QMessageBox::Ok);
    about->show();
    about->exec();
}

// --- About Qt --- //
void Editor::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this,tr("About Qt"));
}

// --- Visit the forum --- //
void Editor::on_actionVisit_EHM_Hardcode_Editor_Forum_triggered()
{
    QUrl urlForum("http://www.ehmtheblueline.com/ehmhardcode");
    QDesktopServices::openUrl(urlForum);
}

/* ============================== */
/*      Exit the Application      */
/* ============================== */

// --- Exit application --- //
void Editor::on_actionExit_triggered()
{
    this->close();
}

// --- Detect any attempt to close the application and prompt the user to confirm he wishes to exit (only if the there is data loaded) --- //
void Editor::closeEvent(QCloseEvent *event)
{
    // Accept the close event if no data has been loaded
    if(data_.size() < 1)
        event->accept();
    // Else ask the user if he wants to close
    else if(QMessageBox::Yes == QMessageBox::question(this, tr("Exit"), tr("Are you sure you wish to exit the Hardcode Editor?"), QMessageBox::Yes|QMessageBox::No, QMessageBox::No))
        event->accept();
    else
        event->ignore();

}
