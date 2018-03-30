<<<<<<< HEAD
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#include "textfile.h"

TextFile::TextFile(QObject *parent) : QObject(parent)
{
    m_file = new QFile(this);
    m_fileInfo = new QFileInfo(*m_file);
    m_fileInfo->setCaching(false);

}

TextFile::TextFile(const QString &filePath, QObject *parent) : QObject(parent)
{
    m_file = new QFile(filePath,this);
    m_fileInfo = new QFileInfo(filePath);
    loadFile();
    m_fileInfo->setCaching(false);
}

TextFile::TextFile(const QString &content, const QString &filePath, QObject *parent) : QObject(parent)
{
    m_file = new QFile(filePath,this);
    m_fileInfo = new QFileInfo(filePath);
    loadFile();
    m_fileInfo->setCaching(false);
    setContent(content);

}

TextFile::~TextFile() {
    delete m_fileInfo;
}

void TextFile::setFile(const QString &filePath) {
    m_file->setFileName(filePath);
    m_fileInfo->setFile(filePath);
}

void TextFile::setFile(QFile *file) {
    m_file = file;
    m_fileInfo->setFile(*file);
}

void TextFile::setContent(QString content) {
    m_content = content;
}

QFile *TextFile::getFile() {
    return m_file;
}

QFileInfo *TextFile::getFileInfo() {
    return m_fileInfo;
}



QString TextFile::getContent() {
    return m_content;
}

bool TextFile::loadFile() {

    if(!m_fileInfo->filePath().isEmpty())
    {
        if (!m_file->open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(qApp->activeWindow(), tr("Recent Files"),
                                 tr("Cannot read file %1:\n%2.")
                                 .arg(m_fileInfo->filePath())
                                 .arg(m_file->errorString()));
            return false;
        }

        QTextStream in(m_file);
        qApp->setOverrideCursor(Qt::WaitCursor);
        setContent(in.readAll());
        qApp->restoreOverrideCursor();
        m_file->close();
        emit fileExist(true);
        return true;
    }else{
        return false;
    }

}

bool TextFile::saveFile() {
    if(!m_fileInfo->filePath().isEmpty())
    {
        if (!m_file->open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(qApp->activeWindow(), tr("Recent Files"),
                                 tr("Cannot write file %1:\n%2.")
                                 .arg(m_fileInfo->filePath())
                                 .arg(m_file->errorString()));
            return false;
        }

        QTextStream out(m_file);
        QApplication::setOverrideCursor(Qt::WaitCursor);
        out << getContent();
        QApplication::restoreOverrideCursor();
        m_file->close();
        emit fileExist(true);
        return true;
    }else{
        return false;
    }
}
=======
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#include "textfile.h"

TextFile::TextFile(QObject *parent) : QObject(parent)
{
    m_file = new QFile(this);
    m_fileInfo = new QFileInfo(*m_file);
    m_fileInfo->setCaching(false);

}

TextFile::TextFile(const QString &filePath, QObject *parent) : QObject(parent)
{
    m_file = new QFile(filePath,this);
    m_fileInfo = new QFileInfo(filePath);
    loadFile();
    m_fileInfo->setCaching(false);
}

TextFile::TextFile(const QString &content, const QString &filePath, QObject *parent) : QObject(parent)
{
    m_file = new QFile(filePath,this);
    m_fileInfo = new QFileInfo(filePath);
    loadFile();
    m_fileInfo->setCaching(false);
    setContent(content);

}

TextFile::~TextFile() {
    delete m_fileInfo;
}

void TextFile::setFile(const QString &filePath) {
    m_file->setFileName(filePath);
    m_fileInfo->setFile(filePath);
}

void TextFile::setFile(QFile *file) {
    m_file = file;
    m_fileInfo->setFile(*file);
}

void TextFile::setContent(QString content) {
    m_content = content;
}

QFile *TextFile::getFile() {
    return m_file;
}

QFileInfo *TextFile::getFileInfo() {
    return m_fileInfo;
}



QString TextFile::getContent() {
    return m_content;
}

bool TextFile::loadFile() {

    if(!m_fileInfo->filePath().isEmpty())
    {
        if (!m_file->open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(qApp->activeWindow(), tr("Recent Files"),
                                 tr("Cannot read file %1:\n%2.")
                                 .arg(m_fileInfo->filePath())
                                 .arg(m_file->errorString()));
            return false;
        }

        QTextStream in(m_file);
        qApp->setOverrideCursor(Qt::WaitCursor);
        setContent(in.readAll());
        qApp->restoreOverrideCursor();
        m_file->close();
        emit fileExist(true);
        return true;
    }else{
        return false;
    }

}

bool TextFile::saveFile() {
    if(!m_fileInfo->filePath().isEmpty())
    {
        if (!m_file->open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(qApp->activeWindow(), tr("Recent Files"),
                                 tr("Cannot write file %1:\n%2.")
                                 .arg(m_fileInfo->filePath())
                                 .arg(m_file->errorString()));
            return false;
        }

        QTextStream out(m_file);
        QApplication::setOverrideCursor(Qt::WaitCursor);
        out << getContent();
        QApplication::restoreOverrideCursor();
        m_file->close();
        emit fileExist(true);
        return true;
    }else{
        return false;
    }
}
>>>>>>> refs/remotes/origin/master
