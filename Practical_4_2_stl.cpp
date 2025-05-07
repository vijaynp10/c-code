#include <iostream>
#include <string>
#include <map>
using namespace std;

class Employee
{
protected:
    string name;
    int age;

public:
    Employee(string Name, int Age)
    {
        name = Name;
        age = Age;
    }
    void Get_Detail()
    {
        cout << "Name of the Employee is: " << name << endl;
        cout << "Age of the Employee is: " << age << endl;
    }
};

class Emp_Id : public Employee
{
protected:
    int Emp_id;

public:
    Emp_Id(string Name, int Age, int id) : Employee(Name, Age)
    {
        Emp_id = id;
    }

    void GetEmpId()
    {
        cout << "Employee ID is: " << Emp_id << endl;
    }
};

class Manager : public Emp_Id
{
    string Department;

public:
    Manager(string Name, int Age, int ID, string dept) : Emp_Id(Name, Age, ID)
    {
        Department = dept;
    }

    void GetDepartment()
    {
        cout << "Department of the employee is: " << Department << endl;
    }
};

int main()
{
    Manager M("Mahavir",18,1,"IT");
    M.GetDepartment();
    M.GetEmpId();
    M.Get_Detail();
    return 0;
}