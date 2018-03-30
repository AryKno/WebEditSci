/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#include "fileinfodialog.h"

FileInfoDialog::FileInfoDialog(QFileInfo *fileInfo, QWidget *parent) : QDialog(parent,Qt::WindowCloseButtonHint)
{
    m_fileInfo = new QFileInfo;
    m_layout = new QGridLayout(this);
    m_fileName = new QLabel(this);
    m_fileSuffix = new QLabel(this);
    m_filePath = new QLabel(this);
    m_fileDateCreated = new QLabel(this);
    m_fileDateModified = new QLabel(this);
    m_fileSize = new QLabel(this);
    m_fileDontExits = new QLabel("This file doens't exists yet");

    if(fileInfo->exists())
    {
        m_layout->addWidget(m_fileName,0,0);
        m_layout->addWidget(m_fileSuffix,1,0);
        m_layout->addWidget(m_filePath,2,0);
        m_layout->addWidget(m_fileDateCreated,3,0);
        m_layout->addWidget(m_fileDateModified,4,0);
        m_layout->addWidget(m_fileSize,5,0);
        setFile(fileInfo);

        setWindowTitle(fileInfo->fileName());
    }else{
        m_layout->addWidget(m_fileDontExits);
    }
        qDebug()<<"File info dialog created";
}

FileInfoDialog::~FileInfoDialog()
{
    //delete m_fileInfo;
    qDebug()<<"File info dialog destroyed";
}

void FileInfoDialog::setFile(QFileInfo *fileInfo)
{
    m_fileInfo = fileInfo;
    m_fileName->setText("Nom du fichier : "+m_fileInfo->fileName());
    m_fileSuffix->setText("Type de fichier : "+m_fileInfo->completeSuffix());
    m_filePath->setText("Chemin : "+m_fileInfo->filePath());
    m_fileDateCreated->setText("Crée le : "+m_fileInfo->created().toString(Qt::DefaultLocaleLongDate));
    m_fileDateModified->setText("Dernière modification le : "+m_fileInfo->lastModified().toString(Qt::DefaultLocaleLongDate));
    m_fileSize->setText("Taille : "+QString::number(m_fileInfo->size(),10)+" octets");
}

