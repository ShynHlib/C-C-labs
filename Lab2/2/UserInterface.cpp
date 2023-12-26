#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
using namespace std;
using namespace Records;
int displayMenu();
void doHire(Database& inDB);
void doFire(Database& inDB);
void doPromote(Database& inDB);
void doDemote(Database& inDB);
int main(int argc, char** argv) {
	Database employeeDB;
	bool done = false;
	while (!done) {
		int selection = displayMenu();
		switch (selection) {
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			doDemote(employeeDB);
			break;
		case 5:
			employeeDB.displayAll();
			break;
		case 6:
			employeeDB.displayCurrent();
			break;
		case 7:
			employeeDB.displayFormer();
			break;
		case 8:
			employeeDB.displayCodes();
			break;
		case 0:
			done = true;
			break;
		default:
			cerr << "Unknown command." << endl;
		}
	}
}
int displayMenu() {
	int selection;
	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) Demote an employee" << endl;
	cout << "5) List all employees" << endl;
	cout << "6) List all current employees" << endl;
	cout << "7) List all previous employees" << endl;
	cout << "8) Position codes" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "---> ";
	cin >> selection;
	return selection;
}
void doHire(Database& inDB) {
	string inName;
	int inAge;
	string inGender;
	string inAddress;
	int inPassportCode;
	int inPositionCode;
	cout << "Name? ";
	cin.ignore();
	getline(cin, inName);
	cout << "Age? ";
	cin >> inAge;
	cout << "Gender? ";
	cin >> inGender;
	cout << "Adress? ";
	cin.ignore();
	getline(cin, inAddress);
	cout << "Passport code? ";
	cin >> inPassportCode;
	cout << "Positon code? ";
	cin >> inPositionCode;
	try {
		inDB.addEmployee(inName, inAge, inGender, inAddress, inPassportCode, inPositionCode);
	}
	catch (std::exception ex) {
		cerr << "Unable to add new employee!" << endl;
	}
}
void doFire(Database& inDB) {
	int employeeNumber;
	cout << "Employee number? ";
	cin >> employeeNumber;
	try {
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee with number " << employeeNumber << " has been terminated." << endl;
	}
	catch (std::exception ex) {
		cerr << "Unable to terminate employee!" << endl;
	}
}
void doPromote(Database& inDB) {
	int employeeNumber;
	int raiseAmount;
	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a raise? ";
	cin >> raiseAmount;
	try {
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	catch (std::exception ex) {
		cerr << "Unable to promote employee!" << endl;
	}
}
void doDemote(Database& inDB) {
	int employeeNumber;
	int decreaseAmount;
	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a decrease? ";
	cin >> decreaseAmount;
	try {
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.demote(decreaseAmount);
	}
	catch (std::exception ex) {
		cerr << "Unable to demote employee!" << endl;
	}
}