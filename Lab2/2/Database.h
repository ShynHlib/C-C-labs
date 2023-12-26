#include <iostream>
#include "Employee.h"
namespace Records {
	const int kMaxEmployees = 11;
	const int kFirstEmployeeNumber = 1000;
	class Database {
	public:
		Database();
		~Database();
		Employee& addEmployee(std::string inFullName, int inAge, std::string inGender,
			std::string inAddress, int inPassportCode, int inPositionCode);
		Employee& getEmployee(int inEmployeeNumber);
		void displayAll();
		void displayCurrent();
		void displayFormer();
		void displayCodes();
	protected:
		Employee mEmployees[kMaxEmployees];
		int mNextSlot;
		int mNextEmployeeNumber;
	};
}