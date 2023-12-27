#ifndef LISTEMPLOYEE_H
#define LISTEMPLOYEE_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QFileDialog>

class ListEmployee : public QDialog {
    Q_OBJECT

public:
    ListEmployee(QWidget *parent = nullptr);

private slots:
    void loadData();

private:
    QTextEdit *textEdit;
    QPushButton *loadButton;
};


#endif // LISTEMPLOYEE_H
