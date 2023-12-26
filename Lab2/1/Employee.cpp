#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;
namespace Records {
	Employee::Employee() {
		mEmployeeNumber = -1;
		mName = "";
		mAge = 0;
		mGender = "";
		mAddress = "";
		mPassportCode = 0;
		mPositionCode = 0;
		fHired = false;
		mSalary = 0;
	}
	void Employee::hire() {
		fHired = true;
	}
	void Employee::fire() {
		fHired = false;
	}
	void Employee::promote(int raiseAmount) {
		if (fHired) {
			mSalary += raiseAmount;
		}
		else {
			cout << "Unable to promote employee " << getEmployeeNumber() << "! Employee is not hired!" << endl;
		}
	}
	void Employee::demote(int decreaseAmount) {
		if (fHired) {
			mSalary -= decreaseAmount;
		}
		else {
			cout << "Unable to demote employee " << getEmployeeNumber() << "! Employee is not hired!" << endl;
		}
	}
	void Employee::display() {
		cout << "-------------------------" << endl;
		cout << "Employee Number: " << getEmployeeNumber() << endl;
		cout << "Employee: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "Gender: " << getGender() << endl;
		cout << "Adress: " << getAddress() << endl;
		cout << "Passport code: " << getPassportCode() << endl;
		cout << "Position code: " << getPositionCode() << endl;
		cout << "Salary: $" << getSalary() << endl;
		cout << (fHired ? "Current Employee" : "Former Employee") << endl;
		cout << "-------------------------" << endl;
	}
	// Accessors and setters
	void Employee::setEmployeeNumber(int inEmployeeNumber) {
		mEmployeeNumber = inEmployeeNumber;
	}
	int Employee::getEmployeeNumber() {
		return mEmployeeNumber;
	}
	void Employee::setName(string inFullName) {
		mName = inFullName;
	}
	string Employee::getName() {
		return mName;
	}
	void Employee::setAge(int inAge) {
		mAge = inAge;
	}
	int Employee::getAge() {
		return mAge;
	}
	void Employee::setGender(std::string inGender) {
		mGender = inGender;
	}
	std::string Employee::getGender() {
		return mGender;
	}
	void Employee::setAddress(std::string inAddress) {
		mAddress = inAddress;
	}
	std::string Employee::getAddress() {
		return mAddress;
	}
	void Employee::setPassportCode(int inPassportCode) {
		mPassportCode = inPassportCode;
	}
	int Employee::getPassportCode() {
		return mPassportCode;
	}
	void Employee::setPositionCode(int inPositionCode) {
		mPositionCode = inPositionCode;
	}
	int Employee::getPositionCode() {
		return mPositionCode;
	}
	void Employee::setSalary() {
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
			cerr << "Unknown position code!" << endl;
			break;
		}
	}
	int Employee::getSalary() {
		return mSalary;
	}
	bool Employee::getIsHired() {
		return fHired;
	}
}