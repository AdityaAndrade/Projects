#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Employee {
public:
  Employee();
  Employee(const string& theName, const string& theSsn);
  string getName() const {return name;}
  string getSsn() const {return ssn;}
  double getNetPay() const {return netPay;}
  void setName(const string& newName) {name = newName;}
  void setSsn(const string& newSsn) {ssn = newSsn;}
  void setPay(double newNetPay) {netPay = newNetPay;}
  void printCheck();
private:
  string name;
  string ssn;
  double netPay;

};

Employee::Employee() : name("No name yet"), ssn("No number yet"), netPay(0.0) {}

Employee::Employee(const string& theName, const string& theSsn) : name(theName), ssn(theSsn), netPay(0.0) {}

void Employee::printCheck() {
  cout << "\nErrorr: printCheck FUNCTION CALLED FOR AN \n"
  << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
  << "Check with the author of the program about this bug \n";
  exit(1);
}









class SalariedEmployee : public Employee {
public:
  SalariedEmployee();
  SalariedEmployee(const string& theName, const string& theSsn, double theWeeklySalary);
  double getSalary() const {return salary;}
  void setSalary(double newSalary) {salary = newSalary;}
  void printCheck();
protected:
  double salary; //weekly
};

SalariedEmployee::SalariedEmployee() : Employee(), salary(0) {}
SalariedEmployee::SalariedEmployee(const string& theName, const string& theSsn, double theWeeklySalary) {}
void SalariedEmployee::printCheck() {
  cout << "\n----------------------------------------\n";
  cout << "Pay to the order of " << getName() << endl;
  cout << "The sum of " << getNetPay() << "Dollars\n";
  cout << "----------------------------------------\n";
  cout << "Check Stub NOT NEGOTIABLE\n";
  cout << "Employee Number: " << getSsn() << endl;
  cout << "Salaried Employee. Regular Pay: " << salary << endl;
  cout << "----------------------------------------\n";
}









class Administrator : SalariedEmployee {
private:
  string title_;
  string responsibility_;
  string immediateSupervisor_;
  double annualSalary_;
public:
  Administrator();
  Administrator(const string& theName, const string& theSsn, double theWeeklySalary, string title, string responsibility, string immediateSupervisor);
  void setSupervisor(const string& newSupervisor) {immediateSupervisor_ = newSupervisor;}
  void readIn();
  void printCheck();
};

Administrator::Administrator() {
  SalariedEmployee{};
  annualSalary_ = 0;
}

Administrator::Administrator(const string& theName, const string& theSsn, double theWeeklySalary, string title, string responsibility, string immediateSupervisor) {
  SalariedEmployee{theName, theSsn, theWeeklySalary};
  annualSalary_ = theWeeklySalary * 52;
  title_ = title;
  responsibility_ = responsibility;
  immediateSupervisor_ = immediateSupervisor;
}

void Administrator::readIn() {
  double d;
  string s;
  cout << "Please enter the name" << endl;
  cin >> s;
  setName(s);

  cout << "Please enter the SSN" << endl;
  cin >> s;
  setSsn(s);

  cout << "Please enter the netPay" << endl;
  cin >> d;
  setPay(d);

  cout << "Please enter the annual Salary" << endl;
  cin >> annualSalary_;
  setSalary(annualSalary_/12);

  cout << "Please enter the title" << endl;
  cin >> title_;

  cout << "Please enter the responsibility" << endl;
  cin >> responsibility_;

  cout << "Please enter the name of the immediate supervisor" << endl;
  cin >> immediateSupervisor_;


}



void Administrator::printCheck() {
  cout << "\n----------------------------------------\n";
  cout << "Pay to the order of " << getName() << endl;
  cout << "The sum of " << getNetPay() << "Dollars\n";
  cout << "----------------------------------------\n";
  cout << "Check Stub NOT NEGOTIABLE\n";
  cout << "Employee Number: " << getSsn() << endl;
  cout << "Administrator. Regular Pay: " << annualSalary_ << endl;
  cout << "----------------------------------------\n";
}


//member func for reading in data
//member func print
//overload printcheck

int main() {
    return 0;
}
