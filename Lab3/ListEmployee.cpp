#include "ListEmployee.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTextStream>

ListEmployee::ListEmployee(QWidget *parent)
    : QDialog(parent) {
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);

    loadButton = new QPushButton("Load Data", this);
    connect(loadButton, &QPushButton::clicked, this, &ListEmployee::loadData);
    layout->addWidget(loadButton);
}

void ListEmployee::loadData() {
    QString defaultFileName = QDir::currentPath() + "/data.txt";
    QString fileName = QFileDialog::getOpenFileName(this, "Load Data", defaultFileName, "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString data = in.readAll();
        textEdit->setPlainText(data);
        file.close();
    } else {
        QMessageBox::critical(this, "Error", "Failed to open the file for reading.");
    }
}
