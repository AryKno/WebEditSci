/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#ifndef FILEINFODIALOG_H
#define FILEINFODIALOG_H

#include <QDialog>
#include <QFileInfo>
#include <QLabel>
#include <QGridLayout>
#include <QDebug>
#include <QDateTime>

class FileInfoDialog : public QDialog
{
public:
    FileInfoDialog(QFileInfo *fileInfo,QWidget *parent=0);
    ~FileInfoDialog();
    void setFile(QFileInfo *fileInfo);

private:
    QFileInfo *m_fileInfo;
    QGridLayout *m_layout;

    QLabel *m_fileDontExits;

    QLabel *m_fileName;
    QLabel *m_fileSuffix;
    QLabel *m_filePath;
    QLabel *m_fileDateCreated;
    QLabel *m_fileDateModified;
    QLabel *m_fileSize;



};

#endif // FILEINFODIALOG_H
