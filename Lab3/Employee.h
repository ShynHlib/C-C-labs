#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QTextStream>

class Employee {
public:
    Employee();

    void hire();
    void fire();
    void promote(int raiseAmount);
    void demote(int decreaseAmount);
    void display() const;
    void displayToFile(QTextStream& out) const;

    void setEmployeeNumber(int inEmployeeNumber);
    int getEmployeeNumber() const;

    void setName(const QString& inName);
    QString getName() const;

    void setAge(int inAge);
    int getAge() const;

    void setGender(const QString& inGender);
    QString getGender() const;

    void setAddress(const QString& inAddress);
    QString getAddress() const;

    void setPassportCode(int inPassportCode);
    int getPassportCode() const;

    void setSalary();
    int getSalary() const;

    void setPositionCode(int inPositionCode);
    int getPositionCode() const;

    bool getIsHired() const;

private:
    int mEmployeeNumber;
    QString mName;
    int mAge;
    QString mGender;
    QString mAddress;
    int mPassportCode;
    int mPositionCode;
    bool mIsHired;
    int mSalary;
};

#endif // EMPLOYEE_H
