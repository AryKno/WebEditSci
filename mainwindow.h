<<<<<<< HEAD
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QToolBar>
#include <QStyle>
#include <QStatusBar>
#include <QSettings>
#include <QFileDialog>
#include <QStringList>
#include "tabwidget.h"
#include "fileinfodialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool tabNeedToBeSaved(const int &tabIndex);
    Editor *currentEditor();
    TextFile *currentFile();
    void saveFilesToSettings();
    void openFilesToSettings();



private:
    QVBoxLayout *mainLayout;
    QWidget *mainWidget;

    QMenuBar *m_menuBar;

    QMenu *m_menuFichier;
    QMenu *m_menuEdition;
    QMenu *m_menuOutils;
    QMenu *m_menuAide;

    QAction *m_actionNewTab;
    QAction *m_actionDelTab;



    QAction *m_actionEnregistrer;
    QAction *m_actionEnregistrerSous;
    QAction *m_actionEnregistrerTous;
    QAction *m_actionOuvrirFichier;
    QAction *m_actionQuitter;

    QAction *m_actionCopier;
    QAction *m_actionCouper;
    QAction *m_actionColler;

    QAction *m_actionUndo;
    QAction *m_actionRedo;

    QAction *m_actionFileInfoDialog;

    QAction *m_actionAproposQt;

    QToolBar *m_barreOutil1;

    TabWidget *m_tabWidget;

    QString m_windowBaseTitle;

    void initWindow();
    void initMenus();
    void initActions();
    void initToolBars();
    void initConnections();

    void readSettings();
    void writeSettings();

public slots:
    void updateWindow(int tab);
    void copy();
    void cut();
    void paste();
    void undo();
    void redo();
    void newTab();
    void wantToCloseTab(int tabIndex = -1);
    void openFile();
    void saveAllFile();
    void saveFile();
    void saveFileAs();
    void showFileInfoDialog();
    void noTab(bool noTab);

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
=======
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QIcon>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QToolBar>
#include <QStyle>
#include <QStatusBar>
#include <QSettings>
#include <QFileDialog>
#include <QStringList>
#include "tabwidget.h"
#include "fileinfodialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool tabNeedToBeSaved(const int &tabIndex);
    Editor *currentEditor();
    TextFile *currentFile();
    void saveFilesToSettings();
    void openFilesToSettings();



private:
    QVBoxLayout *mainLayout;
    QWidget *mainWidget;

    QMenuBar *m_menuBar;

    QMenu *m_menuFichier;
    QMenu *m_menuEdition;
    QMenu *m_menuOutils;
    QMenu *m_menuAide;

    QAction *m_actionNewTab;
    QAction *m_actionDelTab;



    QAction *m_actionEnregistrer;
    QAction *m_actionEnregistrerSous;
    QAction *m_actionEnregistrerTous;
    QAction *m_actionOuvrirFichier;
    QAction *m_actionQuitter;

    QAction *m_actionCopier;
    QAction *m_actionCouper;
    QAction *m_actionColler;

    QAction *m_actionUndo;
    QAction *m_actionRedo;

    QAction *m_actionFileInfoDialog;

    QAction *m_actionAproposQt;

    QToolBar *m_barreOutil1;

    TabWidget *m_tabWidget;

    QString m_windowBaseTitle;

    void initWindow();
    void initMenus();
    void initActions();
    void initToolBars();
    void initConnections();

    void readSettings();
    void writeSettings();

public slots:
    void updateWindow(int tab);
    void copy();
    void cut();
    void paste();
    void undo();
    void redo();
    void newTab();
    void wantToCloseTab(int tabIndex = -1);
    void openFile();
    void saveAllFile();
    void saveFile();
    void saveFileAs();
    void showFileInfoDialog();
    void noTab(bool noTab);

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
>>>>>>> refs/remotes/origin/master
