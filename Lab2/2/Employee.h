#include <iostream>
namespace Records {
	class Employee {
	public:
		Employee();
		void hire();
		void fire();
		void promote(int raiseAmount);
		void demote(int decreaseAmount);
		void display();

		void setEmployeeNumber(int inEmployeeNumber);
		int getEmployeeNumber();

		void setName(std::string inName);
		std::string getName();

		void setAge(int inAge);
		int getAge();

		void setGender(std::string inGender);
		std::string getGender();

		void setAddress(std::string inAdress);
		std::string getAddress();

		void setPassportCode(int inPassportCode);
		int getPassportCode();

		void setSalary();
		int getSalary();

		void setPositionCode(int inPositionCode);
		int getPositionCode();
		bool getIsHired();
	private:
		int mEmployeeNumber;
		std::string mName;
		int mAge;
		std::string mGender;
		std::string mAddress;
		int mPassportCode;
		int mPositionCode;
		bool fHired;
		int mSalary;
	};
}