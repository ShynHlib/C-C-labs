#include "mainwindow.h"
#include "database.h"
#include "HireEmployee.h"
#include "FireEmployee.h"
#include "PromoteEmployee.h"
#include "DemoteEmployee.h"
#include "ListEmployee.h"
#include <QVBoxLayout>
#include <QFile>
#include <QDataStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createButtons();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(hireButton);
    layout->addWidget(fireButton);
    layout->addWidget(promoteButton);
    layout->addWidget(demoteButton);
    layout->addWidget(listAllButton);
    layout->addWidget(saveButton);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    setWindowTitle("Employee Database");
}

MainWindow::~MainWindow() {}

void MainWindow::createButtons()
{
    hireButton = new QPushButton("Hire new employee", this);
    connect(hireButton, SIGNAL(clicked()), this, SLOT(hireEmployee()));

    fireButton = new QPushButton("Fire employee", this);
    connect(fireButton, SIGNAL(clicked()), this, SLOT(fireEmployee()));

    promoteButton = new QPushButton("Promote employee", this);
    connect(promoteButton, SIGNAL(clicked()), this, SLOT(promoteEmployee()));

    demoteButton = new QPushButton("Demote employee", this);
    connect(demoteButton, SIGNAL(clicked()), this, SLOT(demoteEmployee()));

    listAllButton = new QPushButton("List all employees", this);
    connect(listAllButton, SIGNAL(clicked()), this, SLOT(listAllEmployees()));

    saveButton = new QPushButton("Save", this);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveData()));
}

void MainWindow::hireEmployee()
{
    HireEmployee hireDialog(this);

    if (hireDialog.exec() == QDialog::Accepted) {
        QString name = hireDialog.getName();
        int age = hireDialog.getAge();
        QString gender = hireDialog.getGender();
        QString address = hireDialog.getAddress();
        int passportCode = hireDialog.getPassportCode().toInt();
        int positionCode = hireDialog.getPositionCode().toInt();

        try {
            mDatabase.addEmployee(name, age, gender, address, passportCode, positionCode);
            QMessageBox::information(nullptr, "Success", "Employee added");

        } catch (const std::exception &e) {
            QMessageBox::critical(nullptr, "Error", QString("Unable to add new employee! %1").arg(e.what()));
        }
    }
}

void MainWindow::fireEmployee()
{
    FireEmployee dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        int employeeNumber = dialog.getEmployeeNumber();
        try {
            Employee& employee = mDatabase.getEmployee(employeeNumber);
            if (employee.getIsHired()) {
                employee.fire();
                QMessageBox::information(nullptr, "Success", "Employee has been terminated!");
            } else {
                QMessageBox::critical(nullptr, "Error", "Employee is already fired!");
            }
        } catch (const std::exception& e) {
            QMessageBox::critical(nullptr, "Error", QString("Unable to terminate employee! %1").arg(e.what()));
        }
    }
}

void MainWindow::promoteEmployee()
{
    PromoteEmployee promoteDialog(this);

    if (promoteDialog.exec() == QDialog::Accepted) {
        int employeeNumber = promoteDialog.getEmployeeNumber();
        int promotionAmount = promoteDialog.getPromotionAmount();

        try {
            Employee& employee = mDatabase.getEmployee(employeeNumber);
            if(employee.getIsHired()){
                employee.promote(promotionAmount);
                QMessageBox::information(nullptr, "Success", "Employee promoted");
            } else{
                QMessageBox::critical(nullptr, "Error", "Employee is fired! Unable to promote!");
            }
        } catch (const std::exception &e) {
            QMessageBox::critical(nullptr, "Error", QString("Unable to promote employee! %1").arg(e.what()));
        }
    }
}

void MainWindow::demoteEmployee()
{
    DemoteEmployee demoteDialog(this);

    if (demoteDialog.exec() == QDialog::Accepted) {
        int employeeNumber = demoteDialog.getEmployeeNumber();
        int demotionAmount = demoteDialog.getDecreaseAmount();

        try {
            Employee& employee = mDatabase.getEmployee(employeeNumber);
            if(employee.getIsHired()){
                employee.demote(demotionAmount);
                QMessageBox::information(nullptr, "Success", "Employee demoted");
            } else {
                QMessageBox::critical(nullptr, "Error", "Employee is fired! Unable to demote!");
            }
        } catch (const std::exception &e) {
            QMessageBox::critical(nullptr, "Error", QString("Unable to demote employee! %1").arg(e.what()));
        }
    }
}

void MainWindow::listAllEmployees() {
    ListEmployee *listDialog = new ListEmployee(this);
    listDialog->setAttribute(Qt::WA_DeleteOnClose, true);
    listDialog->show();
}


void MainWindow::saveData() {
    QString defaultFileName = QDir::currentPath() + "/data.txt";

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Save Data",
                                                    defaultFileName,
                                                    "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        mDatabase.displayAllToFile(out);

        file.close();
        QMessageBox::information(this, "Save Successful", "Data has been saved!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to open the file for writing.");
    }
}
