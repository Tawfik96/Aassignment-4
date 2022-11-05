#pragma once
#include"Employee.h"
#include <iostream>
using namespace std;
class Linear_Hashing
{
private:
	int s = 10;
	Employee* arr = new Employee[s];
public:
	
	Linear_Hashing()
	{
		for (int i = 0; i < s; i++)
		{
			arr[i].age = -1;
		}
	}

	bool IsFull()
	{
		for (int i = 0; i < s; i++)
		{
			if (arr[i].age == -1)
				return false;
		}
		return true;
	}

	int hash(Employee emp)
	{
		int place;

		place = (emp.age + emp.name[1]) % s;
		return place;
	}
	void insert(Employee e)
	{
		if (!IsFull())
		{
			int index = hash(e);
			while (true)
			{
				if (arr[index].age == -1)
				{
					arr[index] = e;
					return;
				}
				if (hash(arr[index]) == hash(e))
				index = (index + 1) % s;
			}
		}
		else
			cout << "No Place!\n";
	}

	int coll_rate()
	{
		int rate = 0;
		for (int i = 0; i < s; i++)
		{
			for (int j = i+1; j < s; j++)
			{
				if (hash(arr[i]) == hash(arr[j]) && arr[i].age != -1)
				{
					rate++;
					break;
				}
			}
		}
		return rate;
	}

	void remove(Employee e)
	{
		int index = hash(e);
		int start = index;
		while (true)
		{
			if (arr[index].name == e.name)
			{
				arr[index].age = -1;
				return;
			}
			if (index == start)
				return;
			index = (index + 1) % 10;
		}

	}
	void print()
	{
		cout << " Printing the hash:( Name - Age - Experience - Salary )\n\n";
		for (int i = 0; i < s; i++)
		{
			cout << i << ":	";
			if (arr[i].age == -1)

				cout << " \n";
			else
				cout << "[ "<<arr[i].name << "  " << arr[i].age << "  " << arr[i].experience << "  " << arr[i].salary<<" ]" << endl;
		}
	}

	~Linear_Hashing()
	{
		delete[]arr;
	}
};