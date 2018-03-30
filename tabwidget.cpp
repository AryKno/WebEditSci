/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#include "tabwidget.h"

TabWidget::TabWidget(QWidget *parent) : QTabWidget(parent)
{
    m_lastTabIndex = 0;
    qDebug() << "TabWidget created";

    setTabBarAutoHide(false);
    setTabsClosable(true);
    setMovable(true);

    emit noTab(true);

}

TabWidget::~TabWidget()
{
    qDebug() << "TabWidget deleted";

}

int TabWidget::newTab(const QString &tabName,const QString &content)
{

    TextFile *file = new TextFile(content,"",this);
    Editor *editor = new Editor(file,this);
    m_tab.append(editor);
    m_file.append(file);



    emit noTab(false);

    return addTab(editor,tabName);

}

int TabWidget::newTab(const QString &filePath)
{
    TextFile *file = new TextFile(filePath,this);
    Editor *editor = new Editor(file,this);
    m_tab.append(editor);
    m_file.append(file);


    emit noTab(false);



    return addTab(editor,file->getFileInfo()->fileName());

}

Editor *TabWidget::getTab(const int &tabIndex) const
{
    return m_tab[tabIndex];

}

TextFile *TabWidget::getFile(const int &tabIndex) const
{
    return m_file[tabIndex];
}

void TabWidget::deleteTab(int tabIndex) {

    if(tabIndex == -1) {
        tabIndex = currentIndex();
    }
    if(count() == 0) {
        QMessageBox::warning(this,"Fin des onglets","Il n'y a plus d'onglets à fermer",QMessageBox::Ok);
    }else{
        if(count()-1 == 0)
            emit noTab(true);

        m_tab.remove(tabIndex);
        m_file.remove(tabIndex);
        removeTab(tabIndex);


    }



}

bool TabWidget::isTabClosable() const {
        return m_tab.size() != 1;
}

bool TabWidget::isThereZeroTab() const {
    return m_tab.size() == 0;
}



