/******************************************************************************

 Author: Mario Alonso Núñez Zavala
 Date: 08/06/2017
 Description:
                This program is to explore the benefits of use 
                a copy constructor when our purpose is to have
                a quick way to duplicate objects and keep them in
                a array structure. Besides, in this example, we'll using
                polymorphism (virtual keyword).
                As an exaple the context it'll be the employees record

*******************************************************************************/
#include <iostream>

using namespace std;

// Let's begin declaring out constants
enum EMPS { INTERN, SENIOR, JUNIOR };
const int types_of_employees = 3;

// Our employee print
class Employee {
  public: 
    Employee(): age(18) {
        cout << "\nI'm Employee Contructor by Default!\n";
    }
    virtual ~Employee() {
        cout << "\nI'm a polymorphic destructor!\nI can destroy anything! Muajaja\n";
    }
    // Here comes the hard one: Our copy constructor
    Employee(const Employee &copy); // Let's define later (reference because will captcha by a pointer)
    // Thanks to this function, we can copy invoking the copy contructor
    virtual Employee* clone() { 
        return new Employee(*this); // parameter is the object that invokes this method (we get our copy!)
    }
    virtual void toProgram() const { 
	     cout << "\nWe create the tomorrow... Today\n"; 
	}
	int getAge() const { 
	    return this -> age; 
	}
	
	private:
	 int age;
};

// Through our argument, we assigned age to our copy
Employee::Employee(const Employee &copy)
 :age(copy.getAge()) {
    cout << "\nMy moment finally has come!\nLet's begin the copy...\n";    
}

// Our Employee "Children"
class Senior: public Employee
{
 public:
	 Senior() { 
	     cout << "\nSenior or not senior, that's the dilemma\n"; 
	}
	 ~Senior() { 
	     cout << "\nA senior never's destroyed, just made one with code\n"; 
	 }
	 Senior(const Senior &);
	 void toProgram() const { 
	     cout << "int main() {\n\tcout<<'Hello World!;'\n}\n"; 
	 }
	 virtual Employee* clone() { 
	     return new Senior(*this); 
	 }
};

// Call to Employee copy constructor
Senior::Senior(const Senior &copy)
 :Employee(copy) {
	 cout << "Let's produce a new Senior with the same skills, WOW (that easy, eh)!\n";
}

class Junior:public Employee 
{
 public:
	 Junior() { 
	    cout << "\nWell, time to grow as a developer\n"; 
	     
	 }
	 ~Junior() { 
	    cout << "\nHere it goes another Junior...\n"; 
	 }
	 Junior(const Junior &);
	 void toProgram()const { 
	    cout << "\nError in the line...\n"; 
	 }
	 virtual Employee* clone() { 
	    return new Junior(*this); 
	 }
};
 
Junior::Junior(const Junior &copy)
  :Employee(copy) {
	 cout << "\nTraining another Junior, immediately!\n";
}

int main()
{
     Employee* employees[types_of_employees];
	 Employee* to_copy;
	 int choose, index;
	 
	 for (index = 0; index <= types_of_employees - 1; index ++)
	 {
		 cout << "\n(1)Promote a new Senior\n(2)Train a new Junior\n(3)Receive a new Intern\n\tChoose: ";
		 cin >> choose;
		 
		 switch(choose) 
		 {
			 case SENIOR: 
				 to_copy = new Senior;
				 break;
			 case JUNIOR: 
				 to_copy = new Junior;
				 break;
			 default: 
				 to_copy = new Employee;
				 break;
		 }
		 
		 employees[index] = to_copy;
	 }
	 
	 // Time to verify if our copies are there!
	 Employee* new_employees[types_of_employees];
	 for(index = 0; index <= types_of_employees - 1; index ++) {
	     // verify what our programmers do ;)
		 employees[index] -> toProgram();
		 // Now we clone 'em
		 new_employees[index] = employees[index] -> clone();
	 }
	 
	 cout << "\n\nTime to see what our programmers do:\n";
	 // Now is time to verify what our copies do
	 for(index = 0; index <= types_of_employees - 1; index++)
		 new_employees[index] -> toProgram();

    return 0;
}