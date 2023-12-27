// Database.cpp
#include "Database.h"
#include <QDebug>
#include <QMessageBox>
#include <stdexcept>
#include <QFile>
#include <QTextStream>

Database::Database() {
    mNextSlot = 0;
    mNextEmployeeNumber = kFirstEmployeeNumber;
}

Database::~Database() {}

Employee& Database::addEmployee(const QString& inName, int inAge, const QString& inGender, const QString& inAddress, int inPassportCode, int inPositionCode) {
    if (mNextSlot >= kMaxEmployees) {
        QMessageBox::critical(nullptr, "Error", "There is no more room to add the new employee!");
        throw std::out_of_range("Employee array is full");
    }

    if (inPositionCode < 1 || inPositionCode > 6) {
        QMessageBox::critical(nullptr, "Error", "There is no position available under this code! Code must be from 1 to 5!");
        throw std::invalid_argument("Invalid position code");
    }

    if (inAge < 17 || inAge > 65) {
        QMessageBox::critical(nullptr, "Error", "Invalid age! Age must be from 16 to 200!");
        throw std::out_of_range("Invalid age");
    }

    if (inGender != "M" && inGender != "F") {
        QMessageBox::critical(nullptr, "Error", "Invalid gender! Type 'M' or 'F'!");
        throw std::invalid_argument("Invalid gender");
    }

    Employee& theEmployee = mEmployees[mNextSlot++];
    theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
    theEmployee.setName(inName);
    theEmployee.setAge(inAge);
    theEmployee.setGender(inGender);
    theEmployee.setPassportCode(inPassportCode);
    theEmployee.setAddress(inAddress);
    theEmployee.setPositionCode(inPositionCode);
    theEmployee.setSalary();
    theEmployee.hire();
    return theEmployee;
}

Employee& Database::getEmployee(int inEmployeeNumber) {
    for (int i = 0; i < mNextSlot; i++) {
        if (mEmployees[i].getEmployeeNumber() == inEmployeeNumber) {
            return mEmployees[i];
        }
    }

    qCritical() << "No employee with employee number " << inEmployeeNumber;
    throw std::out_of_range("Employee not found");
}

void Database::displayAll() {
    for (int i = 0; i < mNextSlot; i++) {
        mEmployees[i].display();
    }
}

void Database::displayCurrent() {
    for (int i = 0; i < mNextSlot; i++) {
        if (mEmployees[i].getIsHired()) {
            mEmployees[i].display();
        }
    }
}

void Database::displayFormer() {
    for (int i = 0; i < mNextSlot; i++) {
        if (!mEmployees[i].getIsHired()) {
            mEmployees[i].display();
        }
    }
}

void Database::saveToFile(const QString& filename) {
    QFile file(filename);

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << "-------------------------" << endl;
        out << "List of All Employees:" << endl;
        displayAllToFile(out);
        out << "-------------------------" << endl;

        file.close();
    } else {
        qDebug() << "Error opening file for writing.";
    }
}

void Database::displayAllToFile(QTextStream& out)  {
    for (int i = 0; i < mNextSlot; ++i) {
        mEmployees[i].displayToFile(out);
    }
}
