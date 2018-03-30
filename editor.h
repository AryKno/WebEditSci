/****************************************************************************/
/****************************************************************************/
/************************AUTHOR : AMAURY KNOCKAERT***************************/
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#ifndef EDITOR_H
#define EDITOR_H

#include <QDebug>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QTextBlock>
#include <QPainter>
#include <textfile.h>
#include "Qsci/qsciscintilla.h"
#include "Qsci/qscilexerhtml.h"
#include "textfile.h"

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
QT_END_NAMESPACE

class textFile;
class QsciScintilla;
class Editor : public QsciScintilla
{
    Q_OBJECT
public:
    Editor(TextFile *textFile = 0, QWidget *parent = 0);
    ~Editor();

    QMenu *getMenu();

    bool isCopyAvailable();



protected:
    void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;

public slots:
    void undoRedoAvailable();
    void updateFile();

signals:
    void redoAvailable(bool available);
    void undoAvailable(bool available);




private:

    QsciLexerHTML *m_lexerHtml;
    QAction *m_actionCopier;
    QAction *m_actionCouper;
    QAction *m_actionColler;

    QAction *m_actionUndo;
    QAction *m_actionRedo;

    QAction *m_actionSelectAll;

    QMenu *m_editContextMenu;
    TextFile *m_textFile;
    QWidget *lineNumberArea;
    void initContextMenu();
};

#endif // EDITOR_H
