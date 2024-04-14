#include<iostream>
#include<string>
using namespace std;



// Base class representing a
//  person

const int Max_Size = 50; // Maximum size of whwhwhhwhhwhwhwhwhwwh   
//Base class representing a person

class Person
{
private:
	string Name, CNIC, Contact_Number;
	int Age;

public:

	// Constructor initializing member  variable
	
	
	Person() : Name(""), CNIC(""), Contact_Number(""), Age(0) {}

	// Destructor
	~Person() {}

	// Setter methods
	void setName(const string nam)
	{
		Name = nam;
	}

	void setCNIC(const string cnic)
	{
		CNIC = cnic;
	}

	void setContact_Number(const string num)
	{
		Contact_Number = num;
	}

	void setAge(const int age)
	{
		Age = age;
	}

	// Getter methods
	string getName() const
	{
		return Name;
	}

	string getCNIC() const
	{
		return CNIC;
	}

	string getContact_Number() const
	{
		return Contact_Number;
	}

	int getAge() const
	{
		return Age;
	}
};

// Derived class representing a teacher, inheriting from Person class
class Teacher : public Person
{
private:

	string Emp_id, Course;
	long double Salary;

public:

	// Constructor initializing member 
	// variables
	Teacher() : Emp_id(""), Course(""), Salary(0) {}

	// Destructor
	~Teacher() {}

	// Setter methods
	void setEmp_id(const string id)
	{
		Emp_id = id;
	}

	void setcourse(const string course)
	{
		Course = course;
	}

	void setSalary(const long double sal)
	{
		Salary = sal;
	}

	// Getter methods
	string getEmp_id() const
	{
		return Emp_id;
	}

	string getcourse() const
	{
		return Course;
	}

	long double getSalary() const
	{
		return Salary;
	}

	// Method to display teacher details
	void display() const
	{
		cout << "Name: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "CNIC: " << getCNIC() << endl;
		cout << "Contact Number: " << getContact_Number() << endl;
		cout << "Employee ID: " << Emp_id << endl;
		cout << "Course: " << Course << endl;
		cout << "Salary: " << Salary << endl;
	}
};

// Derived class representing a student, inheriting from Person class
class Student : public Person
{
private:

	double CGPA;
	string Degree;

public:

	// Constructor initializing member variables
	Student() : CGPA(0), Degree("") {}

	// Destructor
	~Student() {}

	// Setter methods
	void setCGPA(const double gpa)
	{
		CGPA = gpa;
	}

	void setDegree(const string deg)
	{
		Degree = deg;
	}

	// Getter methods
	double getCGPA() const
	{
		return CGPA;
	}

	string getDegree() const
	{
		return Degree;
	}

	// Method to display student details
	void display() const
	{
		cout << "Name: " << getName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "CNIC: " << getCNIC() << endl;
		cout << "Contact Number: " << getContact_Number() << endl;
		cout << "CGPA: " << CGPA << endl;
		cout << "Degree: " << Degree << endl;
	}
};

// Struct representing login credentials
struct Login
{
	string id = "Admin";
	string password = "12345";

} login;

// Function to create a new teacher object
void createTeacher(Teacher* OBJ[], int& size)
{
	OBJ[size] = new Teacher(); // Allocate memory for new teacher object

	// Check if database is full
	if (size == Max_Size)
	{
		cout << "Sorry you cannot add Teacher, Database is full!" << endl;
		return;
	}

	string str;
	int age;

	cin.ignore();
	cout << "Enter Details of Teacher!" << endl;
	cout << "Enter Name:" << endl;
	getline(cin, str);
	OBJ[size]->setName(str);

	cout << "Enter Age:" << endl;
	cin >> age;
	OBJ[size]->setAge(age);
	cin.ignore();

	cout << "Enter CNIC:" << endl;
	getline(cin, str);
	OBJ[size]->setCNIC(str);

	cout << "Enter contact number:" << endl;
	getline(cin, str);
	OBJ[size]->setContact_Number(str);

	cout << "Enter Employee ID:" << endl;
	getline(cin, str);
	OBJ[size]->setEmp_id(str);

	cout << "Enter Course:" << endl;
	getline(cin, str);
	OBJ[size]->setcourse(str);

	cout << "Teacher Added successfully!" << endl;
	size++;
}

// Function to create a new student object
void createStudent(Student* OBJ[], int& size)
{
	OBJ[size] = new Student(); // Allocate memory for new student object

	// Check if database is full
	if (size == Max_Size)
	{
		cout << "Sorry you cannot add Student, Database is full!" << endl;
		return;
	}

	string str;
	int age;
	double gpa;

	cin.ignore();
	cout << "Enter Details of Students!" << endl;
	cout << "Enter Name:" << endl;
	getline(cin, str);
	OBJ[size]->setName(str);

	cout << "Enter Age:" << endl;
	cin >> age;
	OBJ[size]->setAge(age);
	cin.ignore();

	cout << "Enter CNIC:" << endl;
	getline(cin, str);
	OBJ[size]->setCNIC(str);

	cout << "Enter contact number:" << endl;
	getline(cin, str);
	OBJ[size]->setContact_Number(str);

	cout << "Enter CGPA:" << endl;
	cin >> gpa;
	OBJ[size]->setCGPA(gpa);
	cin.ignore();

	cout << "Enter Degree:" << endl;
	getline(cin, str);
	OBJ[size]->setDegree(str);

	cout << "Student added successfully!" << endl;
	size++;
}

// Function to modify details of a teacher
void ModifyTeacher(Teacher* OBJ[], int& size)
{
	string str;
	int age;

	// Check if there are teachers in the database
	if ((size) == 0)
	{
		cout << "No teacher in database! Please add teacher to modify." << endl;
		return;
	}

	cout << "Enter the Employee ID of the teacher to modify:" << endl;
	cin.ignore();
	getline(cin, str);

	int foundindex = -1;


	for (int i = 0; i < size; i++)
	{

		if ((OBJ[i]->getEmp_id()) == (str))
		{
			foundindex = i;
			break;
		}

	}

	if (foundindex == -1)
	{
		cout << "No Teacher found with this Employee ID." << endl;
		return;
	}


	cout << "Enter Modified Details of Teacher!" << endl;
	cout << "Enter Name:" << endl;
	getline(cin, str);
	OBJ[foundindex]->setName(str);

	cout << "Enter Age:" << endl;
	cin >> age;
	OBJ[foundindex]->setAge(age);
	cin.ignore();

	cout << "Enter CNIC:" << endl;
	getline(cin, str);
	OBJ[foundindex]->setCNIC(str);

	cout << "Enter contact number:" << endl;
	getline(cin, str);
	OBJ[foundindex]->setContact_Number(str);

	cout << "Enter Employee ID:" << endl;
	getline(cin, str);
	OBJ[foundindex]->setEmp_id(str);

	cout << "Enter Course:" << endl;
	getline(cin, str);
	OBJ[foundindex]->setcourse(str);

	cout << "Teacher data modified successfully!" << endl;
}

// Function to modify details of a student
void ModifyStudent(Student* OBJ[], int& size)
{
	string str;


	if ((size) == 0)
	{
		cout << "No Student in database! Please add student to modify." << endl;
		return;
	}

	cout << "Enter the CNIC of the student to modify:" << endl;
	cin.ignore();
	getline(cin, str);

	int foundindex = -1;


	for (int i = 0; i < size; i++)
	{

		if ((OBJ[i]->getCNIC()) == (str))
		{
			foundindex = i;
			break;
		}

	}

	if (foundindex == -1)
	{
		cout << "No Student found with this CNIC." << endl;
		return;
	}

	int age;
	double gpa;

	cout << "Enter Modified Details of Students!" << endl;
	cout << "Enter Name:" << endl;
	getline(cin, str);
	OBJ[foundindex]->setName(str);

	cout << "Enter Age:" << endl;
	cin >> age;
	OBJ[foundindex]->setAge(age);
	cin.ignore();

	cout << "Enter CNIC:" << endl;
	getline(cin, str);
	OBJ[foundindex]->setCNIC(str);

	cout << "Enter contact number:" << endl;
	getline(cin, str);
	OBJ[foundindex]->setContact_Number(str);

	cout << "Enter CGPA:" << endl;
	cin >> gpa;
	OBJ[foundindex]->setCGPA(gpa);
	cin.ignore();

	cout << "Enter Degree:" << endl;
	getline(cin, str);
	OBJ[foundindex]->setDegree(str);

	cout << "Student data modified successfully!" << endl;
}

// Function to search for a student by name
void searchStudentByName(Student* OBJ[], int& size, string name)
{
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if ((OBJ[i]->getName()) == (name))
		{
			OBJ[i]->display();
			found = true;
		}
	}

	if (!found)
		cout << "No student found with the given name." << endl;
}

// Function to search for a student by CNIC
void searchStudentByCNIC(Student* OBJ[], int& size, string cnic)
{
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if ((OBJ[i]->getCNIC()) == (cnic))
		{
			OBJ[i]->display();
			found = true;
		}
	}

	if (!found)
		cout << "No student found with the given CNIC." << endl;
}

// Function to search for students by age
void searchStudentByAge(Student* OBJ[], int& size, int age)
{
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if ((OBJ[i]->getAge()) == (age))
		{
			OBJ[i]->display();
			found = true;
		}
	}

	if (!found)
		cout << "No student found with the given age." << endl;
}

// Function to search for students with CGPA greater than a given value
void searchStudentByGPAMoreThan(Student* OBJ[], int& size, double GPA)
{
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if ((OBJ[i]->getCGPA()) > (GPA))
		{
			OBJ[i]->display();
			found = true;
		}
	}

	if (!found)
		cout << "No student found with a CGPA greater than the given value." << endl;
}

// Function to search for students with CGPA less than a given value
void searchStudentByGPALessThan(Student* OBJ[], int& size, double GPA)
{
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if ((OBJ[i]->getCGPA()) < (GPA))
		{
			OBJ[i]->display();
			found = true;
		}
	}

	if (!found)
		cout << "No student found with a CGPA less than the given value." << endl;
}

// Main function
int main()
{
	static int size = 0; // Initialize size variable to keep track of number of objects created
	Student* student[Max_Size]; // Array of student pointers
	Teacher* teacher[Max_Size]; // Array of teacher pointers

	int choice;
	bool isAdmin = false; // Flag to check if user is admin

	//Admin login loop
	do
	{

		cout << endl << "** Mini School Database System **" << endl;
		cout << "1. Login as Admin." << endl;
		cout << "2. Exit." << endl;

		cout << "Enter your choice: " << endl;
		cin >> choice;
		cin.ignore();

		if (choice == 1)
		{
			string username, password;

			cout << "Enter username: " << endl;
			getline(cin, username);

			cout << "Enter password: " << endl;
			getline(cin, password);

			if (username == login.id && password == login.password)
				isAdmin = true;

			if (isAdmin)
			{
				cout << "Login successful!" << endl;
			}
			else
			{
				cout << "Invalid credentials!Enter Again." << endl;
			}
		}

	} while (choice != 2 && !isAdmin);

	if (isAdmin)
	{
		// Main menu loop
		while (1)
		{

			cout << endl << " Admin Menu **" << endl;
			cout << "1. Create Teacher" << endl;
			cout << "2. Create Student" << endl;
			cout << "3. Modify Teacher" << endl;
			cout << "4. Modify Student" << endl;
			cout << "5. Search Student by Name" << endl;
			cout << "6. Search Student by CNIC" << endl;
			cout << "7. Search Students by Age" << endl;
			cout << "8. Search Students by CGPA (Greater Than)" << endl;
			cout << "9. Search Students by CGPA (Less Than)" << endl;
			cout << "10. Logout" << endl;

			cout << "Enter your choice: ";
			cin >> choice;

			{
				switch (choice)
				{
				case 1:

					createTeacher(teacher, size);
					break;

				case 2:

					createStudent(student, size);
					break;

				case 3:

					ModifyTeacher(teacher, size);
					break;

				case 4:

					ModifyStudent(student, size);
					break;

				case 5:
				{
					string name;
					cout << "Enter student name: ";
					cin.ignore();
					getline(cin, name);
					searchStudentByName(student, size, name);
					break;
				}
				case 6:
				{
					string cnic;
					cout << "Enter student CNIC: ";
					cin.ignore();
					getline(cin, cnic);


					searchStudentByCNIC(student, size, cnic);
					break;
				}
				case 7:
				{
					int age;
					cout << "Enter age: ";
					cin.ignore();
					cin >> age;


					searchStudentByAge(student, size, age);
					break;
				}
				case 8:
				{
					float cgpa;
					cout << "Enter CGPA (to find students with CGPA greater than): ";
					cin.ignore();
					cin >> cgpa;


					searchStudentByGPAMoreThan(student, size, cgpa);
					break;
				}
				case 9:
				{
					float cgpa;
					cout << "Enter CGPA (to find students with CGPA less than): ";
					cin.ignore();
					cin >> cgpa;


					searchStudentByGPALessThan(student, size, cgpa);
					break;
				}
				case 10:

					isAdmin = false;
					cout << "Logout successful!" << endl;


					cout << "Exiting Mini School Database System." << endl;
					exit(0);
					break;

				default:
					cout << "Invalid choice!Enter Again:" << endl;
				}
			}
		}






	}
}
