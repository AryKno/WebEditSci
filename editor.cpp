<<<<<<< HEAD
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#include "editor.h"

Editor::Editor(TextFile *textFile,QWidget *parent) : QsciScintilla(parent)
{
    qDebug() << "Editor created";
    setFrameShape(QFrame::NoFrame);

    initContextMenu();

    setWrapMode(QsciScintilla::WrapNone);


    m_textFile = textFile;
    setText(m_textFile->getContent());

    connect(this,SIGNAL(textChanged()),this,SLOT(undoRedoAvailable()));
    connect(this,SIGNAL(textChanged()),this,SLOT(updateFile()));





    m_lexerHtml = new QsciLexerHTML;
    setLexer(m_lexerHtml);

    m_lexerHtml->setFont(QFont("Consolas",10),-1);
    setMarginLineNumbers(1,true);
    setMarginWidth(1,32);


}

Editor::~Editor()
{
    delete m_lexerHtml;
    qDebug() << "m_lexerHtml deleted";
    qDebug() << "Editor deleted";

}

void Editor::undoRedoAvailable() {
    undoAvailable(isUndoAvailable());
    redoAvailable(isRedoAvailable());


}

void Editor::updateFile() {
    m_textFile->setContent(text());
}

void Editor::initContextMenu() {
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

    m_actionSelectAll = new QAction("Tout sélectionner",this);
    m_actionSelectAll->setShortcut(QKeySequence::SelectAll);

    addAction(m_actionUndo);
    addAction(m_actionRedo);

    m_actionUndo->setEnabled(false);
    m_actionRedo->setEnabled(false);
    m_actionCopier->setEnabled(false);
    m_actionCouper->setEnabled(false);

    addAction(m_actionCopier);
    addAction(m_actionCouper);
    addAction(m_actionColler);

    addAction(m_actionSelectAll);

    connect(m_actionCopier,SIGNAL(triggered()),this,SLOT(copy()));
    connect(m_actionColler,SIGNAL(triggered()),this,SLOT(paste()));
    connect(m_actionCouper,SIGNAL(triggered()),this,SLOT(cut()));

    connect(m_actionUndo,SIGNAL(triggered()),this,SLOT(undo()));
    connect(m_actionRedo,SIGNAL(triggered()),this,SLOT(redo()));
    connect(m_actionSelectAll,SIGNAL(triggered()),this,SLOT(selectAll()));

    connect(this,SIGNAL(modificationChanged(bool)),m_actionUndo,SLOT(setEnabled(bool)));
    connect(this,SIGNAL(modificationChanged(bool)),m_actionRedo,SLOT(setEnabled(bool)));
    connect(this,SIGNAL(copyAvailable(bool)),m_actionCopier,SLOT(setEnabled(bool)));
    connect(this,SIGNAL(copyAvailable(bool)),m_actionCouper,SLOT(setEnabled(bool)));


    m_editContextMenu = new QMenu(this);

    m_editContextMenu->addAction(m_actionUndo);
    m_editContextMenu->addAction(m_actionRedo);
    m_editContextMenu->addSeparator();
    m_editContextMenu->addAction(m_actionCopier);
    m_editContextMenu->addAction(m_actionCouper);
    m_editContextMenu->addAction(m_actionColler);
    m_editContextMenu->addSeparator();
    m_editContextMenu->addAction(m_actionSelectAll);
}


void Editor::contextMenuEvent(QContextMenuEvent *event)
{
    m_editContextMenu->exec(event->globalPos());
}

QMenu *Editor::getMenu() {
    return m_editContextMenu;
}



bool Editor::isCopyAvailable() {
    return m_actionCopier->isEnabled();
}




=======
/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#include "editor.h"

Editor::Editor(TextFile *textFile,QWidget *parent) : QsciScintilla(parent)
{
    qDebug() << "Editor created";
    setFrameShape(QFrame::NoFrame);

    initContextMenu();

    setWrapMode(QsciScintilla::WrapNone);


    m_textFile = textFile;
    setText(m_textFile->getContent());

    connect(this,SIGNAL(textChanged()),this,SLOT(undoRedoAvailable()));
    connect(this,SIGNAL(textChanged()),this,SLOT(updateFile()));





    m_lexerHtml = new QsciLexerHTML;
    setLexer(m_lexerHtml);

    m_lexerHtml->setFont(QFont("Consolas",10),-1);
    setMarginLineNumbers(1,true);
    setMarginWidth(1,32);


}

Editor::~Editor()
{
    delete m_lexerHtml;
    qDebug() << "m_lexerHtml deleted";
    qDebug() << "Editor deleted";

}

void Editor::undoRedoAvailable() {
    undoAvailable(isUndoAvailable());
    redoAvailable(isRedoAvailable());


}

void Editor::updateFile() {
    m_textFile->setContent(text());
}

void Editor::initContextMenu() {
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

    m_actionSelectAll = new QAction("Tout sélectionner",this);
    m_actionSelectAll->setShortcut(QKeySequence::SelectAll);

    addAction(m_actionUndo);
    addAction(m_actionRedo);

    m_actionUndo->setEnabled(false);
    m_actionRedo->setEnabled(false);
    m_actionCopier->setEnabled(false);
    m_actionCouper->setEnabled(false);

    addAction(m_actionCopier);
    addAction(m_actionCouper);
    addAction(m_actionColler);

    addAction(m_actionSelectAll);

    connect(m_actionCopier,SIGNAL(triggered()),this,SLOT(copy()));
    connect(m_actionColler,SIGNAL(triggered()),this,SLOT(paste()));
    connect(m_actionCouper,SIGNAL(triggered()),this,SLOT(cut()));

    connect(m_actionUndo,SIGNAL(triggered()),this,SLOT(undo()));
    connect(m_actionRedo,SIGNAL(triggered()),this,SLOT(redo()));
    connect(m_actionSelectAll,SIGNAL(triggered()),this,SLOT(selectAll()));

    connect(this,SIGNAL(modificationChanged(bool)),m_actionUndo,SLOT(setEnabled(bool)));
    connect(this,SIGNAL(modificationChanged(bool)),m_actionRedo,SLOT(setEnabled(bool)));
    connect(this,SIGNAL(copyAvailable(bool)),m_actionCopier,SLOT(setEnabled(bool)));
    connect(this,SIGNAL(copyAvailable(bool)),m_actionCouper,SLOT(setEnabled(bool)));


    m_editContextMenu = new QMenu(this);

    m_editContextMenu->addAction(m_actionUndo);
    m_editContextMenu->addAction(m_actionRedo);
    m_editContextMenu->addSeparator();
    m_editContextMenu->addAction(m_actionCopier);
    m_editContextMenu->addAction(m_actionCouper);
    m_editContextMenu->addAction(m_actionColler);
    m_editContextMenu->addSeparator();
    m_editContextMenu->addAction(m_actionSelectAll);
}


void Editor::contextMenuEvent(QContextMenuEvent *event)
{
    m_editContextMenu->exec(event->globalPos());
}

QMenu *Editor::getMenu() {
    return m_editContextMenu;
}



bool Editor::isCopyAvailable() {
    return m_actionCopier->isEnabled();
}




>>>>>>> refs/remotes/origin/master
