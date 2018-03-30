<<<<<<< HEAD
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QTextDocument>
#include <QApplication>
#include <QMessageBox>
#include <QTextStream>
#include <QPlainTextDocumentLayout>
#include <Qsci/qscidocument.h>

//essayer QSaveFile

class TextFile : public QObject
{
    Q_OBJECT
public:
    explicit TextFile(QObject *parent = 0);
    explicit TextFile(const QString &filePath, QObject *parent = 0);
    explicit TextFile(const QString &content, const QString &filePath,QObject *parent = 0);
    ~TextFile();

    QFile *getFile();
    QFileInfo *getFileInfo();
    QsciDocument *getDocument();

    void setFile(const QString &filePath);
    void setFile(QFile *file);

    void setContent(QString content);
    QString getContent();

    bool loadFile();
    bool saveFile();


signals:
    void fileExist(bool);

public slots:


private:
   QFile *m_file;
   QFileInfo *m_fileInfo;
   QString m_content;
   QPlainTextDocumentLayout *m_documentLayout;
};

#endif // TEXTFILE_H
=======
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QTextDocument>
#include <QApplication>
#include <QMessageBox>
#include <QTextStream>
#include <QPlainTextDocumentLayout>
#include <Qsci/qscidocument.h>

//essayer QSaveFile

class TextFile : public QObject
{
    Q_OBJECT
public:
    explicit TextFile(QObject *parent = 0);
    explicit TextFile(const QString &filePath, QObject *parent = 0);
    explicit TextFile(const QString &content, const QString &filePath,QObject *parent = 0);
    ~TextFile();

    QFile *getFile();
    QFileInfo *getFileInfo();
    QsciDocument *getDocument();

    void setFile(const QString &filePath);
    void setFile(QFile *file);

    void setContent(QString content);
    QString getContent();

    bool loadFile();
    bool saveFile();


signals:
    void fileExist(bool);

public slots:


private:
   QFile *m_file;
   QFileInfo *m_fileInfo;
   QString m_content;
   QPlainTextDocumentLayout *m_documentLayout;
};

#endif // TEXTFILE_H
>>>>>>> refs/remotes/origin/master
