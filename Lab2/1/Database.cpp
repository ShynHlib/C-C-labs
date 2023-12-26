#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
using namespace std;
namespace Records {
	Database::Database() {
		mNextSlot = 0;
		mNextEmployeeNumber = kFirstEmployeeNumber;
	}
	Database::~Database() {}
	Employee& Database::addEmployee(std::string inFullName, int inAge, std::string inGender,
		std::string inAddress, int inPassportCode, int inPositionCode) {
		if (mNextSlot >= kMaxEmployees) {
			cerr << "There is no more room to add the new employee!" << endl;
			throw exception();
		}
		if (inPositionCode < 1 || inPositionCode > 5) {
			cerr << "There is no position available under this code! Code must be from 1 to 5!" << endl;
			throw exception();
		}
		if (inAge < 16 || inAge > 200) {
			cerr << "Invalid age! Age must be from 16 to 200!" << endl;
			throw exception();
		}
		if (inGender != "M" && inGender != "F") {
			cerr << "Invalid gender! Type 'M' or 'F'!" << endl;
			throw exception();
		}
		Employee& theEmployee = mEmployees[mNextSlot++];
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
		theEmployee.setName(inFullName);
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
		cerr << "No employee with employee number " << inEmployeeNumber << endl;
		throw exception();
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
	void Database::displayCodes() {
		cout << "-------------------------" << endl;
		cout << "1 - Director;  Salary: 500$" << endl;
		cout << "2 - Librarian; Salary: 300$" << endl;
		cout << "3 - Assistant; Salary: 200$" << endl;
		cout << "4 - Archivist; Salary: 300$" << endl;
		cout << "5 - Janitor;   Salary: 200$" << endl;
		cout << "-------------------------" << endl;
	}
}