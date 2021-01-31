#ifndef EDITOR_COMP_NAMES_H
#define EDITOR_COMP_NAMES_H

#include <QFormLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QStackedLayout>
#include <QVector>
#include <QWidget>

#include "common.h"
#include "text.h"

class EditorCompNames : public QObject
{
    Q_OBJECT

private:
    // Parent
    QWidget *parent_;

    // Layout
    QHBoxLayout *layoutMain_;

    // Left column
    QListWidget *listNations_;
    QVector<QString> itemNations_;
    QVector<QFormLayout*> formNations_;
    QVector<QWidget*> pageNations_;

    // Right column
    QStackedLayout *layoutStack_;

    // Competitions
    QVector<QVector<Text*>> names_;

public:
    EditorCompNames(QWidget &parent);
    EditorCompNames() {}
    ~EditorCompNames() {}

    void init();
    void initData();
    void initUI();
};

#endif // EDITOR_COMP_NAMES_H
