<<<<<<< HEAD
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include <QList>
#include <editor.h>
#include <QAction>
#include <QStyle>
#include <QIcon>
#include <QAction>
#include <QMessageBox>
#include <textfile.h>



class TabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent = 0);
    ~TabWidget();
    Editor *getTab(const int &tabIndex) const;
    TextFile *getFile(const int &tabIndex) const;
    bool isTabClosable() const;
    bool isThereZeroTab() const;
    int newTab(const QString &tabName, const QString &content);
    int newTab(const QString &filePath);
private:
    QVector<Editor *> m_tab;
    QVector<TextFile *> m_file;


    int m_lastTabIndex;

public slots:
    void deleteTab(int tabIndex = -1);


signals:
       void noTab(bool noTab);


};

#endif // TABWIDGET_H
=======
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include <QList>
#include <editor.h>
#include <QAction>
#include <QStyle>
#include <QIcon>
#include <QAction>
#include <QMessageBox>
#include <textfile.h>



class TabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent = 0);
    ~TabWidget();
    Editor *getTab(const int &tabIndex) const;
    TextFile *getFile(const int &tabIndex) const;
    bool isTabClosable() const;
    bool isThereZeroTab() const;
    int newTab(const QString &tabName, const QString &content);
    int newTab(const QString &filePath);
private:
    QVector<Editor *> m_tab;
    QVector<TextFile *> m_file;


    int m_lastTabIndex;

public slots:
    void deleteTab(int tabIndex = -1);


signals:
       void noTab(bool noTab);


};

#endif // TABWIDGET_H
>>>>>>> refs/remotes/origin/master
