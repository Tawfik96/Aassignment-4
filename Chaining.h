#pragma once
#include <iostream>
#include<list>
#include<algorithm>
#include"Employee.h"
using namespace std;
class Chain_Hashing {
private:
	int size = 10;
	list<Employee>* arr = new list<Employee>[size];

public:
	Chain_Hashing()
	{

	}
	int hash(Employee e)
	{
		return (e.age+e.name[1]) % size;
	}
	void insert(Employee v)
	{
		int place = hash(v);
		arr[place].push_back(v);
	}
	void remove(Employee e)
	{
		int place = hash(e);
		for (int i = 0; i < size; i++)
		{
			auto it = find(arr[i].begin(), arr[i].end(), e);
			if (it != arr[i].end())
			{
				arr[i].erase(it);
				return;
			}
		}
		cout << "Not found";
	}
	void print()
	{
		cout << " Printing the hash:( Name - Age - Experience - Salary )\n\n";

		for (int i = 0; i < size; i++)
		{
			cout << i << ":-> ";
			for (auto it = arr[i].begin(); it != arr[i].end(); it++)
			{
				cout << "["<<(*it).name << "-"<<(*it).age << "-" << (*it).experience << "-" << (*it).salary<<"]   ";
			}
			cout << endl;
		}
	}
	int collision_rate()
	{
		int total = 0;
		for (int i = 0; i < size; i++)
		{
			if (!arr[i].empty())
			{
				total += arr[i].size() - 1;
			}

		}
		return total;
	}
	~Chain_Hashing()
	{
		delete[]arr;
	}
};
