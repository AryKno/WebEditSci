<<<<<<< HEAD
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << "MainWindow created";

   // setAttribute(Qt::WA_DeleteOnClose);


    initWindow();
    initActions();

    mainWidget = new QWidget(this);
    mainWidget->setContentsMargins(0,0,0,0);

    mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->setContentsMargins(0,0,0,0);

    m_tabWidget = new TabWidget(this);
    m_tabWidget->setContentsMargins(0,0,0,0);
    noTab(true);

    for(int i=0;i<0;i++) {
        newTab();
    }

    mainLayout->addWidget(m_tabWidget);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    readSettings();

    initMenus();
    initToolBars();
    initConnections();
    (void)statusBar();

    openFilesToSettings();




}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow deleted";

}

void MainWindow::initWindow()
{
    m_windowBaseTitle = "WebEdit";
    setWindowIcon(QIcon(":/icons/soft"));
    setWindowTitle(m_windowBaseTitle);
    setMinimumSize(350,150);

}

void MainWindow::initMenus()
{
    m_menuBar = new QMenuBar;

    m_menuFichier = m_menuBar->addMenu("&Fichier");
    m_menuEdition = m_menuBar->addMenu("&Edition");
    m_menuOutils = m_menuBar->addMenu("&Outils");
    m_menuAide = m_menuBar->addMenu("&?");

    m_menuFichier->addAction(m_actionNewTab);
    m_menuFichier->addSeparator();
    m_menuFichier->addAction(m_actionEnregistrer);
    m_menuFichier->addAction(m_actionEnregistrerSous);
    m_menuFichier->addAction(m_actionEnregistrerTous);
    m_menuFichier->addAction(m_actionOuvrirFichier);
    m_menuFichier->addSeparator();
    m_menuFichier->addAction(m_actionQuitter);

    m_menuEdition->addAction(m_actionDelTab);
    m_menuEdition->addSeparator();
    m_menuEdition->addAction(m_actionUndo);
    m_menuEdition->addAction(m_actionRedo);
    m_menuEdition->addSeparator();
    m_menuEdition->addAction(m_actionCopier);
    m_menuEdition->addAction(m_actionCouper);
    m_menuEdition->addAction(m_actionColler);

    m_menuOutils->addAction(m_actionFileInfoDialog);

    m_menuAide->addAction(m_actionAproposQt);


    setMenuBar(m_menuBar);

}

void MainWindow::initActions()
{
    m_actionNewTab = new QAction(QIcon(":/icons/newFile"),"Nouveau fichier",this);
    m_actionNewTab->setShortcut(QKeySequence::AddTab);

    m_actionDelTab = new QAction(style()->standardIcon(QStyle::SP_LineEditClearButton),"Fermer onglet courant",this);
    //m_actionDelTab->setShortcut(Qt::CTRL + Qt::Key_W);


    m_actionEnregistrer = new QAction(QIcon(":/icons/save"),"Enregistrer",this);
    m_actionEnregistrer->setShortcut(QKeySequence::Save);

    m_actionEnregistrerSous = new QAction(QIcon(":/icons/saveAs"),"Enregistrer sous...",this);
    m_actionEnregistrerSous->setShortcut(QKeySequence::SaveAs);

    m_actionEnregistrerTous = new QAction(QIcon(":/"),"Enregistrer tous les documents",this);
    m_actionEnregistrerTous->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_S);

    m_actionOuvrirFichier = new QAction(QIcon(":/icons/openFile"),"Ouvrir un fichier",this);
    m_actionOuvrirFichier->setShortcut(QKeySequence::Open);

    m_actionQuitter = new QAction(QIcon(":/icons/leave"),"Quitter",this);
    m_actionQuitter->setShortcut(QKeySequence::Close);

    m_actionCopier = new QAction(QIcon(":/icons/copy"),"Copier",this);
    m_actionCopier->setShortcut(QKeySequence::Copy);

    m_actionCouper = new QAction(QIcon(":/icons/cut"),"Couper",this);
    m_actionCouper->setShortcut(QKeySequence::Cut);

    m_actionColler = new QAction(QIcon(":/icons/paste"),"Coller",this);
    m_actionColler->setShortcut(QKeySequence::Paste);

    m_actionUndo = new QAction(QIcon(":/icons/undo"),"Annuler",this);
    m_actionUndo->setShortcut(QKeySequence::Undo);
    m_actionRedo = new QAction(QIcon(":/icons/redo"),"Rétablir",this);
    m_actionRedo->setShortcut(QKeySequence::Redo);

    m_actionFileInfoDialog = new QAction("Information sur le fichier",this);

    m_actionAproposQt = new QAction(style()->standardIcon(QStyle::SP_TitleBarMenuButton),"A propos de Qt",this);


}

void MainWindow::initToolBars()
{
    m_barreOutil1 = addToolBar("Barre d'outils 1");
    m_barreOutil1->setObjectName("barreOutil1");

    m_barreOutil1->addAction(m_actionNewTab);
    m_barreOutil1->addSeparator();

    m_barreOutil1->addAction(m_actionUndo);
    m_barreOutil1->addAction(m_actionRedo);

    m_menuEdition->addSeparator();

    m_barreOutil1->addAction(m_actionEnregistrer);
    m_barreOutil1->addAction(m_actionEnregistrerSous);
    m_barreOutil1->addAction(m_actionOuvrirFichier);
    m_barreOutil1->addSeparator();
    m_barreOutil1->addAction(m_actionQuitter);

}

void MainWindow::initConnections() {

    connect(m_actionNewTab,SIGNAL(triggered()),this,SLOT(newTab()));

    connect(m_actionOuvrirFichier,SIGNAL(triggered(bool)),this,SLOT(openFile()));



    connect(m_tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(wantToCloseTab(int)));
    connect(m_actionDelTab,SIGNAL(triggered()),this,SLOT(wantToCloseTab()));

    connect(m_actionAproposQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connect(m_actionUndo,SIGNAL(triggered()),this,SLOT(undo()));
    connect(m_actionRedo,SIGNAL(triggered()),this,SLOT(redo()));
    connect(m_actionCopier,SIGNAL(triggered()),this,SLOT(copy()));
    connect(m_actionCouper,SIGNAL(triggered()),this,SLOT(cut()));
    connect(m_actionColler,SIGNAL(triggered()),this,SLOT(paste()));

    connect(m_actionQuitter,SIGNAL(triggered()),qApp,SLOT(closeAllWindows()));

    connect(m_actionEnregistrer,SIGNAL(triggered()),this,SLOT(saveFile()));
    connect(m_actionEnregistrerSous,SIGNAL(triggered()),this,SLOT(saveFileAs()));
    connect(m_actionEnregistrerTous,SIGNAL(triggered()),this,SLOT(saveAllFile()));

    connect(m_actionFileInfoDialog,SIGNAL(triggered()),this,SLOT(showFileInfoDialog()));

    connect(m_tabWidget,SIGNAL(noTab(bool)),this,SLOT(noTab(bool)));
    connect(m_tabWidget,SIGNAL(currentChanged(int)),this,SLOT(updateWindow(int)));



}

void MainWindow::updateWindow(int tab) {

   /* if(m_tabWidget->count() != 0)
    {*/
        setWindowTitle(m_windowBaseTitle+" - "+m_tabWidget->tabText(tab)+"[*]");

        m_actionUndo->setEnabled(m_tabWidget->getTab(tab)->isUndoAvailable());
        m_actionRedo->setEnabled(m_tabWidget->getTab(tab)->isRedoAvailable());
        m_actionCopier->setEnabled(m_tabWidget->getTab(tab)->isCopyAvailable());
        m_actionCouper->setEnabled(m_tabWidget->getTab(tab)->isCopyAvailable());
        setWindowModified(m_tabWidget->getTab(tab)->isModified());
        m_actionEnregistrer->setEnabled(m_tabWidget->getFile(tab)->getFileInfo()->exists());
        qDebug()<<"On rentre dans updateWindow"<<tab;
   // }

}


void MainWindow::copy(){
    if(currentEditor())
            currentEditor()->copy();
}
void MainWindow::cut(){
    if(currentEditor())
            currentEditor()->cut();
}
void MainWindow::paste(){
    if(currentEditor())
            currentEditor()->paste();
}
void MainWindow::undo(){
    if(currentEditor())
            currentEditor()->undo();
}
void MainWindow::redo(){
    if(currentEditor())
            currentEditor()->redo();
}

void MainWindow::newTab() {

    int newTabIndex = m_tabWidget->newTab("Nouvel onglet.txt","");

    connect(m_tabWidget->getTab(newTabIndex),SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));
    connect(m_tabWidget->getTab(newTabIndex),SIGNAL(undoAvailable(bool)),m_actionUndo,SLOT(setEnabled(bool)));
    connect(m_tabWidget->getTab(newTabIndex),SIGNAL(redoAvailable(bool)),m_actionRedo,SLOT(setEnabled(bool)));
    connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCopier,SLOT(setEnabled(bool)));
    connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCouper,SLOT(setEnabled(bool)));
    connect(m_tabWidget->getFile(newTabIndex),SIGNAL(fileExist(bool)),m_actionEnregistrer,SLOT(setEnabled(bool)));

    m_tabWidget->setCurrentIndex(newTabIndex);
    updateWindow(newTabIndex);

    //m_tabWidget->setCurrentIndex(newTabIndex);


}

void MainWindow::wantToCloseTab(int tabIndex) {
   if(m_tabWidget->count() != 0)
   {
       if(tabIndex == -1)
           tabIndex = m_tabWidget->currentIndex();

       if(tabNeedToBeSaved(tabIndex)) {
            saveFile();
       }

        disconnect(m_tabWidget->getTab(tabIndex),SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));
        disconnect(m_tabWidget->getTab(tabIndex),SIGNAL(undoAvailable(bool)),m_actionUndo,SLOT(setEnabled(bool)));
        disconnect(m_tabWidget->getTab(tabIndex),SIGNAL(redoAvailable(bool)),m_actionRedo,SLOT(setEnabled(bool)));
        disconnect(m_tabWidget->getTab(tabIndex),SIGNAL(copyAvailable(bool)),m_actionCopier,SLOT(setEnabled(bool)));
        disconnect(m_tabWidget->getTab(tabIndex),SIGNAL(copyAvailable(bool)),m_actionCouper,SLOT(setEnabled(bool)));
        disconnect(m_tabWidget->getFile(tabIndex),SIGNAL(fileExist(bool)),m_actionEnregistrer,SLOT(setEnabled(bool)));

        if(m_tabWidget->count() == 1)
            disconnect(m_tabWidget,SIGNAL(currentChanged(int)),this,SLOT(updateWindow(int)));

        m_tabWidget->deleteTab(tabIndex);

    }


}


void MainWindow::closeEvent(QCloseEvent *event)
{
        //saveFilesToSettings();
        //writeSettings();
        event->accept();
}

void MainWindow::openFile()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,"Ouvrir un fichier", "","Fichier HTML (*.html *.htm);;Fichier PHP (*.php *.phtml);;Fichier Javascript (*.js);;Fichier CSS(*.css);;Fichier ASP (*.aspx)");
    if(!fileName.isEmpty())
    {
        int newTabIndex = m_tabWidget->newTab(fileName);
        connect(m_tabWidget->getTab(newTabIndex),SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));
        connect(m_tabWidget->getTab(newTabIndex),SIGNAL(undoAvailable(bool)),m_actionUndo,SLOT(setEnabled(bool)));
        connect(m_tabWidget->getTab(newTabIndex),SIGNAL(redoAvailable(bool)),m_actionRedo,SLOT(setEnabled(bool)));
        connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCopier,SLOT(setEnabled(bool)));
        connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCouper,SLOT(setEnabled(bool)));
        connect(m_tabWidget->getFile(newTabIndex),SIGNAL(fileExist(bool)),m_actionEnregistrer,SLOT(setEnabled(bool)));

        m_tabWidget->setCurrentIndex(newTabIndex);
        updateWindow(newTabIndex);
    }
}

void MainWindow::saveFile()
{

    int tabIndex = m_tabWidget->currentIndex();

    if(m_tabWidget->getFile(tabIndex)->getFileInfo()->filePath().isEmpty())
        saveFileAs();
    else
        m_tabWidget->getFile(tabIndex)->saveFile();
}

void MainWindow::saveFileAs()
{
    int tabIndex = m_tabWidget->currentIndex();

    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,"Sauver un fichier", "","Fichier HTML (*.html *.htm);;Fichier PHP (*.php *.phtml);;Fichier Javascript (*.js);;Fichier CSS(*.css);;Fichier ASP (*.aspx)");
    m_tabWidget->getFile(tabIndex)->setFile(fileName);
    m_tabWidget->getFile(tabIndex)->saveFile();
    m_tabWidget->setTabText(tabIndex,m_tabWidget->getFile(tabIndex)->getFileInfo()->fileName());
    updateWindow(tabIndex);
}

void MainWindow::showFileInfoDialog() {
    if(m_tabWidget->count() > 0)
    {
        FileInfoDialog fileInfoDialog(currentFile()->getFileInfo(),this);
        fileInfoDialog.exec();

    }
}

void MainWindow::readSettings() {
    QSettings settings("settings.ini",QSettings::IniFormat,this);
    settings.beginGroup("MainWindow");
    //resize(settings.value("size", QSize(400, 400)).toSize());
    //move(settings.value("pos", QPoint(200, 200)).toPoint());
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    settings.endGroup();
}

void MainWindow::writeSettings() {
    QSettings settings("settings.ini",QSettings::IniFormat,this);
    settings.beginGroup("MainWindow");
    //settings.setValue("size", size());
    //settings.setValue("pos", pos());
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.endGroup();
}

void MainWindow::saveAllFile() {
    int numberOfTab = m_tabWidget->count();
    int i;
    for(i=0;i<numberOfTab;i++)
    {
        m_tabWidget->setCurrentIndex(i);
        saveFile();

    }
}

void MainWindow::noTab(bool noTab) {
    noTab = !noTab;
    m_actionUndo->setEnabled(noTab);
    m_actionRedo->setEnabled(noTab);
    m_actionCopier->setEnabled(noTab);
    m_actionCouper->setEnabled(noTab);
    m_actionColler->setEnabled(noTab);
    m_actionDelTab->setEnabled(noTab);
    m_actionEnregistrer->setEnabled(noTab);
    m_actionEnregistrerSous->setEnabled(noTab);
    m_actionEnregistrerTous->setEnabled(noTab);
    m_actionFileInfoDialog->setEnabled(noTab);
    setWindowTitle(m_windowBaseTitle);

}

bool MainWindow::tabNeedToBeSaved(const int &tabIndex)
{
    return m_tabWidget->getTab(tabIndex)->isModified();
}

Editor *MainWindow::currentEditor()
{
    return m_tabWidget->getTab(m_tabWidget->currentIndex());
}

TextFile *MainWindow::currentFile()
{
    return m_tabWidget->getFile(m_tabWidget->currentIndex());
}

void MainWindow::saveFilesToSettings()
{
    QStringList tabList;
    int tabCount = m_tabWidget->count();
    if(tabCount >= 1)
    {
        int i;
        for(i = 0;i<tabCount;i++)
        {
            if(m_tabWidget->getFile(i)->getFileInfo()->fileName().isEmpty())
            {
                tabList<<"untitled.txt";
            }else{
                tabList<<m_tabWidget->getFile(i)->getFileInfo()->absoluteFilePath();
            }
        }
    }

    if(tabList.isEmpty())
        tabList<<"none";

    QSettings settings("settings.ini",QSettings::IniFormat,this);
    settings.beginGroup("MainWindow");
    settings.beginGroup("OpenedTab");
    settings.setValue("FilePaths",tabList);
    settings.endGroup();
    settings.endGroup();

}

void MainWindow::openFilesToSettings() {

    QSettings settings("settings.ini",QSettings::IniFormat,this);
    QStringList tabList;

    settings.beginGroup("MainWindow");
    settings.beginGroup("OpenedTab");
    tabList = settings.value("FilePaths").toStringList();
    settings.endGroup();
    settings.endGroup();

    if(tabList.count() >= 1 && tabList[0]!= "none")
    {
        int tabCount = tabList.count();
        int i;
        int newTabIndex;

        for(i=0;i<tabCount;i++)
        {
            if(tabList[i] == "untitled.txt") {
                newTabIndex = m_tabWidget->newTab("Nouvel Onglet.txt","");
            }else{
                newTabIndex = m_tabWidget->newTab(tabList[i]);
            }
            connect(m_tabWidget->getTab(newTabIndex),SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));
            connect(m_tabWidget->getTab(newTabIndex),SIGNAL(undoAvailable(bool)),m_actionUndo,SLOT(setEnabled(bool)));
            connect(m_tabWidget->getTab(newTabIndex),SIGNAL(redoAvailable(bool)),m_actionRedo,SLOT(setEnabled(bool)));
            connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCopier,SLOT(setEnabled(bool)));
            connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCouper,SLOT(setEnabled(bool)));
            connect(m_tabWidget->getFile(newTabIndex),SIGNAL(fileExist(bool)),m_actionEnregistrer,SLOT(setEnabled(bool)));

            updateWindow(newTabIndex);
        }
    }
}
=======
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << "MainWindow created";

   // setAttribute(Qt::WA_DeleteOnClose);


    initWindow();
    initActions();

    mainWidget = new QWidget(this);
    mainWidget->setContentsMargins(0,0,0,0);

    mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->setContentsMargins(0,0,0,0);

    m_tabWidget = new TabWidget(this);
    m_tabWidget->setContentsMargins(0,0,0,0);
    noTab(true);

    for(int i=0;i<0;i++) {
        newTab();
    }

    mainLayout->addWidget(m_tabWidget);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    readSettings();

    initMenus();
    initToolBars();
    initConnections();
    (void)statusBar();

    openFilesToSettings();




}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow deleted";

}

void MainWindow::initWindow()
{
    m_windowBaseTitle = "WebEdit";
    setWindowIcon(QIcon(":/icons/soft"));
    setWindowTitle(m_windowBaseTitle);
    setMinimumSize(350,150);

}

void MainWindow::initMenus()
{
    m_menuBar = new QMenuBar;

    m_menuFichier = m_menuBar->addMenu("&Fichier");
    m_menuEdition = m_menuBar->addMenu("&Edition");
    m_menuOutils = m_menuBar->addMenu("&Outils");
    m_menuAide = m_menuBar->addMenu("&?");

    m_menuFichier->addAction(m_actionNewTab);
    m_menuFichier->addSeparator();
    m_menuFichier->addAction(m_actionEnregistrer);
    m_menuFichier->addAction(m_actionEnregistrerSous);
    m_menuFichier->addAction(m_actionEnregistrerTous);
    m_menuFichier->addAction(m_actionOuvrirFichier);
    m_menuFichier->addSeparator();
    m_menuFichier->addAction(m_actionQuitter);

    m_menuEdition->addAction(m_actionDelTab);
    m_menuEdition->addSeparator();
    m_menuEdition->addAction(m_actionUndo);
    m_menuEdition->addAction(m_actionRedo);
    m_menuEdition->addSeparator();
    m_menuEdition->addAction(m_actionCopier);
    m_menuEdition->addAction(m_actionCouper);
    m_menuEdition->addAction(m_actionColler);

    m_menuOutils->addAction(m_actionFileInfoDialog);

    m_menuAide->addAction(m_actionAproposQt);


    setMenuBar(m_menuBar);

}

void MainWindow::initActions()
{
    m_actionNewTab = new QAction(QIcon(":/icons/newFile"),"Nouveau fichier",this);
    m_actionNewTab->setShortcut(QKeySequence::AddTab);

    m_actionDelTab = new QAction(style()->standardIcon(QStyle::SP_LineEditClearButton),"Fermer onglet courant",this);
    //m_actionDelTab->setShortcut(Qt::CTRL + Qt::Key_W);


    m_actionEnregistrer = new QAction(QIcon(":/icons/save"),"Enregistrer",this);
    m_actionEnregistrer->setShortcut(QKeySequence::Save);

    m_actionEnregistrerSous = new QAction(QIcon(":/icons/saveAs"),"Enregistrer sous...",this);
    m_actionEnregistrerSous->setShortcut(QKeySequence::SaveAs);

    m_actionEnregistrerTous = new QAction(QIcon(":/"),"Enregistrer tous les documents",this);
    m_actionEnregistrerTous->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_S);

    m_actionOuvrirFichier = new QAction(QIcon(":/icons/openFile"),"Ouvrir un fichier",this);
    m_actionOuvrirFichier->setShortcut(QKeySequence::Open);

    m_actionQuitter = new QAction(QIcon(":/icons/leave"),"Quitter",this);
    m_actionQuitter->setShortcut(QKeySequence::Close);

    m_actionCopier = new QAction(QIcon(":/icons/copy"),"Copier",this);
    m_actionCopier->setShortcut(QKeySequence::Copy);

    m_actionCouper = new QAction(QIcon(":/icons/cut"),"Couper",this);
    m_actionCouper->setShortcut(QKeySequence::Cut);

    m_actionColler = new QAction(QIcon(":/icons/paste"),"Coller",this);
    m_actionColler->setShortcut(QKeySequence::Paste);

    m_actionUndo = new QAction(QIcon(":/icons/undo"),"Annuler",this);
    m_actionUndo->setShortcut(QKeySequence::Undo);
    m_actionRedo = new QAction(QIcon(":/icons/redo"),"Rétablir",this);
    m_actionRedo->setShortcut(QKeySequence::Redo);

    m_actionFileInfoDialog = new QAction("Information sur le fichier",this);

    m_actionAproposQt = new QAction(style()->standardIcon(QStyle::SP_TitleBarMenuButton),"A propos de Qt",this);


}

void MainWindow::initToolBars()
{
    m_barreOutil1 = addToolBar("Barre d'outils 1");
    m_barreOutil1->setObjectName("barreOutil1");

    m_barreOutil1->addAction(m_actionNewTab);
    m_barreOutil1->addSeparator();

    m_barreOutil1->addAction(m_actionUndo);
    m_barreOutil1->addAction(m_actionRedo);

    m_menuEdition->addSeparator();

    m_barreOutil1->addAction(m_actionEnregistrer);
    m_barreOutil1->addAction(m_actionEnregistrerSous);
    m_barreOutil1->addAction(m_actionOuvrirFichier);
    m_barreOutil1->addSeparator();
    m_barreOutil1->addAction(m_actionQuitter);

}

void MainWindow::initConnections() {

    connect(m_actionNewTab,SIGNAL(triggered()),this,SLOT(newTab()));

    connect(m_actionOuvrirFichier,SIGNAL(triggered(bool)),this,SLOT(openFile()));



    connect(m_tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(wantToCloseTab(int)));
    connect(m_actionDelTab,SIGNAL(triggered()),this,SLOT(wantToCloseTab()));

    connect(m_actionAproposQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connect(m_actionUndo,SIGNAL(triggered()),this,SLOT(undo()));
    connect(m_actionRedo,SIGNAL(triggered()),this,SLOT(redo()));
    connect(m_actionCopier,SIGNAL(triggered()),this,SLOT(copy()));
    connect(m_actionCouper,SIGNAL(triggered()),this,SLOT(cut()));
    connect(m_actionColler,SIGNAL(triggered()),this,SLOT(paste()));

    connect(m_actionQuitter,SIGNAL(triggered()),qApp,SLOT(closeAllWindows()));

    connect(m_actionEnregistrer,SIGNAL(triggered()),this,SLOT(saveFile()));
    connect(m_actionEnregistrerSous,SIGNAL(triggered()),this,SLOT(saveFileAs()));
    connect(m_actionEnregistrerTous,SIGNAL(triggered()),this,SLOT(saveAllFile()));

    connect(m_actionFileInfoDialog,SIGNAL(triggered()),this,SLOT(showFileInfoDialog()));

    connect(m_tabWidget,SIGNAL(noTab(bool)),this,SLOT(noTab(bool)));
    connect(m_tabWidget,SIGNAL(currentChanged(int)),this,SLOT(updateWindow(int)));



}

void MainWindow::updateWindow(int tab) {

   /* if(m_tabWidget->count() != 0)
    {*/
        setWindowTitle(m_windowBaseTitle+" - "+m_tabWidget->tabText(tab)+"[*]");

        m_actionUndo->setEnabled(m_tabWidget->getTab(tab)->isUndoAvailable());
        m_actionRedo->setEnabled(m_tabWidget->getTab(tab)->isRedoAvailable());
        m_actionCopier->setEnabled(m_tabWidget->getTab(tab)->isCopyAvailable());
        m_actionCouper->setEnabled(m_tabWidget->getTab(tab)->isCopyAvailable());
        setWindowModified(m_tabWidget->getTab(tab)->isModified());
        m_actionEnregistrer->setEnabled(m_tabWidget->getFile(tab)->getFileInfo()->exists());
        qDebug()<<"On rentre dans updateWindow"<<tab;
   // }

}


void MainWindow::copy(){
    if(currentEditor())
            currentEditor()->copy();
}
void MainWindow::cut(){
    if(currentEditor())
            currentEditor()->cut();
}
void MainWindow::paste(){
    if(currentEditor())
            currentEditor()->paste();
}
void MainWindow::undo(){
    if(currentEditor())
            currentEditor()->undo();
}
void MainWindow::redo(){
    if(currentEditor())
            currentEditor()->redo();
}

void MainWindow::newTab() {

    int newTabIndex = m_tabWidget->newTab("Nouvel onglet.txt","");

    connect(m_tabWidget->getTab(newTabIndex),SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));
    connect(m_tabWidget->getTab(newTabIndex),SIGNAL(undoAvailable(bool)),m_actionUndo,SLOT(setEnabled(bool)));
    connect(m_tabWidget->getTab(newTabIndex),SIGNAL(redoAvailable(bool)),m_actionRedo,SLOT(setEnabled(bool)));
    connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCopier,SLOT(setEnabled(bool)));
    connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCouper,SLOT(setEnabled(bool)));
    connect(m_tabWidget->getFile(newTabIndex),SIGNAL(fileExist(bool)),m_actionEnregistrer,SLOT(setEnabled(bool)));

    m_tabWidget->setCurrentIndex(newTabIndex);
    updateWindow(newTabIndex);

    //m_tabWidget->setCurrentIndex(newTabIndex);


}

void MainWindow::wantToCloseTab(int tabIndex) {
   if(m_tabWidget->count() != 0)
   {
       if(tabIndex == -1)
           tabIndex = m_tabWidget->currentIndex();

       if(tabNeedToBeSaved(tabIndex)) {
            saveFile();
       }

        disconnect(m_tabWidget->getTab(tabIndex),SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));
        disconnect(m_tabWidget->getTab(tabIndex),SIGNAL(undoAvailable(bool)),m_actionUndo,SLOT(setEnabled(bool)));
        disconnect(m_tabWidget->getTab(tabIndex),SIGNAL(redoAvailable(bool)),m_actionRedo,SLOT(setEnabled(bool)));
        disconnect(m_tabWidget->getTab(tabIndex),SIGNAL(copyAvailable(bool)),m_actionCopier,SLOT(setEnabled(bool)));
        disconnect(m_tabWidget->getTab(tabIndex),SIGNAL(copyAvailable(bool)),m_actionCouper,SLOT(setEnabled(bool)));
        disconnect(m_tabWidget->getFile(tabIndex),SIGNAL(fileExist(bool)),m_actionEnregistrer,SLOT(setEnabled(bool)));

        if(m_tabWidget->count() == 1)
            disconnect(m_tabWidget,SIGNAL(currentChanged(int)),this,SLOT(updateWindow(int)));

        m_tabWidget->deleteTab(tabIndex);

    }


}


void MainWindow::closeEvent(QCloseEvent *event)
{
        //saveFilesToSettings();
        //writeSettings();
        event->accept();
}

void MainWindow::openFile()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,"Ouvrir un fichier", "","Fichier HTML (*.html *.htm);;Fichier PHP (*.php *.phtml);;Fichier Javascript (*.js);;Fichier CSS(*.css);;Fichier ASP (*.aspx)");
    if(!fileName.isEmpty())
    {
        int newTabIndex = m_tabWidget->newTab(fileName);
        connect(m_tabWidget->getTab(newTabIndex),SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));
        connect(m_tabWidget->getTab(newTabIndex),SIGNAL(undoAvailable(bool)),m_actionUndo,SLOT(setEnabled(bool)));
        connect(m_tabWidget->getTab(newTabIndex),SIGNAL(redoAvailable(bool)),m_actionRedo,SLOT(setEnabled(bool)));
        connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCopier,SLOT(setEnabled(bool)));
        connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCouper,SLOT(setEnabled(bool)));
        connect(m_tabWidget->getFile(newTabIndex),SIGNAL(fileExist(bool)),m_actionEnregistrer,SLOT(setEnabled(bool)));

        m_tabWidget->setCurrentIndex(newTabIndex);
        updateWindow(newTabIndex);
    }
}

void MainWindow::saveFile()
{

    int tabIndex = m_tabWidget->currentIndex();

    if(m_tabWidget->getFile(tabIndex)->getFileInfo()->filePath().isEmpty())
        saveFileAs();
    else
        m_tabWidget->getFile(tabIndex)->saveFile();
}

void MainWindow::saveFileAs()
{
    int tabIndex = m_tabWidget->currentIndex();

    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,"Sauver un fichier", "","Fichier HTML (*.html *.htm);;Fichier PHP (*.php *.phtml);;Fichier Javascript (*.js);;Fichier CSS(*.css);;Fichier ASP (*.aspx)");
    m_tabWidget->getFile(tabIndex)->setFile(fileName);
    m_tabWidget->getFile(tabIndex)->saveFile();
    m_tabWidget->setTabText(tabIndex,m_tabWidget->getFile(tabIndex)->getFileInfo()->fileName());
    updateWindow(tabIndex);
}

void MainWindow::showFileInfoDialog() {
    if(m_tabWidget->count() > 0)
    {
        FileInfoDialog fileInfoDialog(currentFile()->getFileInfo(),this);
        fileInfoDialog.exec();

    }
}

void MainWindow::readSettings() {
    QSettings settings("settings.ini",QSettings::IniFormat,this);
    settings.beginGroup("MainWindow");
    //resize(settings.value("size", QSize(400, 400)).toSize());
    //move(settings.value("pos", QPoint(200, 200)).toPoint());
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    settings.endGroup();
}

void MainWindow::writeSettings() {
    QSettings settings("settings.ini",QSettings::IniFormat,this);
    settings.beginGroup("MainWindow");
    //settings.setValue("size", size());
    //settings.setValue("pos", pos());
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.endGroup();
}

void MainWindow::saveAllFile() {
    int numberOfTab = m_tabWidget->count();
    int i;
    for(i=0;i<numberOfTab;i++)
    {
        m_tabWidget->setCurrentIndex(i);
        saveFile();

    }
}

void MainWindow::noTab(bool noTab) {
    noTab = !noTab;
    m_actionUndo->setEnabled(noTab);
    m_actionRedo->setEnabled(noTab);
    m_actionCopier->setEnabled(noTab);
    m_actionCouper->setEnabled(noTab);
    m_actionColler->setEnabled(noTab);
    m_actionDelTab->setEnabled(noTab);
    m_actionEnregistrer->setEnabled(noTab);
    m_actionEnregistrerSous->setEnabled(noTab);
    m_actionEnregistrerTous->setEnabled(noTab);
    m_actionFileInfoDialog->setEnabled(noTab);
    setWindowTitle(m_windowBaseTitle);

}

bool MainWindow::tabNeedToBeSaved(const int &tabIndex)
{
    return m_tabWidget->getTab(tabIndex)->isModified();
}

Editor *MainWindow::currentEditor()
{
    return m_tabWidget->getTab(m_tabWidget->currentIndex());
}

TextFile *MainWindow::currentFile()
{
    return m_tabWidget->getFile(m_tabWidget->currentIndex());
}

void MainWindow::saveFilesToSettings()
{
    QStringList tabList;
    int tabCount = m_tabWidget->count();
    if(tabCount >= 1)
    {
        int i;
        for(i = 0;i<tabCount;i++)
        {
            if(m_tabWidget->getFile(i)->getFileInfo()->fileName().isEmpty())
            {
                tabList<<"untitled.txt";
            }else{
                tabList<<m_tabWidget->getFile(i)->getFileInfo()->absoluteFilePath();
            }
        }
    }

    if(tabList.isEmpty())
        tabList<<"none";

    QSettings settings("settings.ini",QSettings::IniFormat,this);
    settings.beginGroup("MainWindow");
    settings.beginGroup("OpenedTab");
    settings.setValue("FilePaths",tabList);
    settings.endGroup();
    settings.endGroup();

}

void MainWindow::openFilesToSettings() {

    QSettings settings("settings.ini",QSettings::IniFormat,this);
    QStringList tabList;

    settings.beginGroup("MainWindow");
    settings.beginGroup("OpenedTab");
    tabList = settings.value("FilePaths").toStringList();
    settings.endGroup();
    settings.endGroup();

    if(tabList.count() >= 1 && tabList[0]!= "none")
    {
        int tabCount = tabList.count();
        int i;
        int newTabIndex;

        for(i=0;i<tabCount;i++)
        {
            if(tabList[i] == "untitled.txt") {
                newTabIndex = m_tabWidget->newTab("Nouvel Onglet.txt","");
            }else{
                newTabIndex = m_tabWidget->newTab(tabList[i]);
            }
            connect(m_tabWidget->getTab(newTabIndex),SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));
            connect(m_tabWidget->getTab(newTabIndex),SIGNAL(undoAvailable(bool)),m_actionUndo,SLOT(setEnabled(bool)));
            connect(m_tabWidget->getTab(newTabIndex),SIGNAL(redoAvailable(bool)),m_actionRedo,SLOT(setEnabled(bool)));
            connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCopier,SLOT(setEnabled(bool)));
            connect(m_tabWidget->getTab(newTabIndex),SIGNAL(copyAvailable(bool)),m_actionCouper,SLOT(setEnabled(bool)));
            connect(m_tabWidget->getFile(newTabIndex),SIGNAL(fileExist(bool)),m_actionEnregistrer,SLOT(setEnabled(bool)));

            updateWindow(newTabIndex);
        }
    }
}
>>>>>>> refs/remotes/origin/master
