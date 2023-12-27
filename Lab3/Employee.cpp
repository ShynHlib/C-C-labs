#include "Employee.h"
#include <QDebug>

Employee::Employee() {
    mEmployeeNumber = -1;
    mName = "";
    mAge = 0;
    mGender = "";
    mAddress = "";
    mPassportCode = 0;
    mPositionCode = 0;
    mIsHired = false;
    mSalary = 0;
}

void Employee::hire() {
    mIsHired = true;
}

void Employee::fire() {
    mIsHired = false;
}

void Employee::promote(int raiseAmount) {
    if (mIsHired) {
        mSalary += raiseAmount;
    } else {
        qDebug() << "Unable to promote employee " << getEmployeeNumber() << "! Employee is not hired!";
    }
}

void Employee::demote(int decreaseAmount) {
    if (mIsHired) {
        mSalary -= decreaseAmount;
    } else {
        qDebug() << "Unable to demote employee " << getEmployeeNumber() << "! Employee is not hired!";
    }
}

void Employee::display() const {
    qDebug() << "-------------------------";
    qDebug() << "Employee Number: " << getEmployeeNumber();
    qDebug() << "Employee: " << getName();
    qDebug() << "Age: " << getAge();
    qDebug() << "Gender: " << getGender();
    qDebug() << "Address: " << getAddress();
    qDebug() << "Passport code: " << getPassportCode();
    qDebug() << "Position code: " << getPositionCode();
    qDebug() << "Salary: $" << getSalary();
    qDebug() << (mIsHired ? "Current Employee" : "Former Employee");
    qDebug() << "-------------------------";
}

// В класі Employee
void Employee::displayToFile(QTextStream& out) const {
    out << "-------------------------" << endl;
    out << "Employee Number: " << getEmployeeNumber() << endl;
    out << "Employee: " << getName() << endl;
    out << "Age: " << getAge() << endl;
    out << "Gender: " << getGender() << endl;
    out << "Address: " << getAddress() << endl;
    out << "Passport code: " << getPassportCode() << endl;
    out << "Position code: " << getPositionCode() << endl;
    out << "Salary: $" << getSalary() << endl;
    out << (mIsHired ? "Current Employee" : "Former Employee") << endl;
    out << "-------------------------" << endl;
}



// Accessors and getters


// Employee Number
void Employee::setEmployeeNumber(int inEmployeeNumber) {
    mEmployeeNumber = inEmployeeNumber;
}

int Employee::getEmployeeNumber() const {
    return mEmployeeNumber;
}


// Name
void Employee::setName(const QString& inName) {
    mName = inName;
}
QString Employee::getName() const {
    return mName;
}

// Age
void Employee::setAge(int inAge) {
    mAge = inAge;
}

int Employee::getAge() const {
    return mAge;
}

// Gender
void Employee::setGender(const QString& inGender){
    mGender = inGender;
}

QString Employee::getGender() const {
    return mGender;
}

// Address
void Employee::setAddress(const QString& inAddress){
    mAddress = inAddress;
}

QString Employee::getAddress() const {
    return mAddress;
}

// Passport code
void Employee::setPassportCode(int inPassportCode) {
    mPassportCode = inPassportCode;
}

int Employee::getPassportCode() const {
    return mPassportCode;
}

// Position code
void Employee::setPositionCode(int inPositionCode) {
    mPositionCode = inPositionCode;
}

int Employee::getPositionCode() const {
    return mPositionCode;
}

// Salary
void Employee::setSalary(){
    switch (mPositionCode) {
    case 1:
        mSalary = 500;
        break;
    case 2:
        mSalary = 300;
        break;
    case 3:
        mSalary = 200;
        break;
    case 4:
        mSalary = 300;
        break;
    case 5:
        mSalary = 200;
        break;
    default:
        qDebug() << "Unknown Position code!";
        break;
    }
}

int Employee::getSalary() const {
    return mSalary;
}



// Hired
bool Employee::getIsHired() const {
    return mIsHired;
}
