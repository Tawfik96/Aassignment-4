#pragma once
#include <iostream>
using namespace std;

class Employee
{
public:
	string name;
	int age, experience, salary;
	Employee(string n=" ", int a=0, int s = 0,int e=0)
	{
		name = n; age = a; experience = e; salary = s;
	}
	bool operator ==(Employee a)
	{
		return (this->age == a.age && this->experience == a.experience && this->name == a.name && this->salary == a.salary);
	}
};

