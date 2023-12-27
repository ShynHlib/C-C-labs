// database.h
#ifndef DATABASE_H
#define DATABASE_H

#include "Employee.h"
#include <QTextStream>

const int kMaxEmployees = 10;
const int kFirstEmployeeNumber = 1;

class Database {
public:
    Database();
    ~Database();
    Employee& addEmployee(const QString& inName, int inAge, const QString& inGender, const QString& inAddress, int inPassportCode, int inPositionCode);
    Employee& getEmployee(int inEmployeeNumber);
    void displayAll();
    void displayCurrent();
    void displayFormer();
    void displayInfo();

    void saveToFile(const QString &filename);
    void displayAllToFile(QTextStream& out);
    void loadFromFile(const QString &filename);

protected:
    Employee mEmployees[kMaxEmployees];
    int mNextSlot;
    int mNextEmployeeNumber;
};

#endif // DATABASE_H
