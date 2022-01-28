#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

#define SALES 0
#define MARKETING 1
#define MANAGER 2

class Staff
{
public:
	Staff(string name, int salary)
	{
		this->m_Name = name;
		this->m_Salary = salary;
	}

	string m_Name;
	int m_Salary;

};

void create_staff(vector<Staff>& staff)
{
	string nameseed = "ABCDEFGHIJ";
	
	for (int i = 0; i < 10; i++)
	{
		string name = "Staff ";
		name += nameseed[i];

		int salary = rand() % 10000 + 10000;

		staff.push_back(Staff(name, salary));
	}
}

void PrintStaff(vector<Staff>& staff)
{
	for (vector<Staff>::iterator it = staff.begin(); it != staff.end(); it++)
	{
		cout << "Name: " << it->m_Name << "   Salary: " << it->m_Salary << endl;
	}
}

void Build(vector<Staff>& staff, multimap<int, Staff>& m)
{
	for (vector<Staff>::iterator it = staff.begin(); it != staff.end(); it++)
	{
		m.insert(make_pair(rand() % 3, *it));
	}
	
}

void showbyDept(int dept, multimap<int, Staff>& m)
{
	multimap<int, Staff>::iterator it = m.find(dept);
	int count = m.count(dept);
	int i = 0;

	while (i++ < count && it != m.end())
	{
		if (dept == 0)
			cout << "Department: Sales" << endl;
		else if(dept == 1)
			cout << "Department: Marketing" << endl;
		else if(dept == 2)
			cout << "Department: Manager" << endl;

		cout << "Name: " << it->second.m_Name << "   Salary: " << it->second.m_Salary << endl;

		it++;
	}
}

void test()
{
	vector<Staff> staff;

	create_staff(staff);
	/*PrintStaff(staff);*/

	multimap<int, Staff> m;
	Build(staff, m);

	showbyDept(SALES, m);
	cout << endl;
	showbyDept(MARKETING, m);
	cout << endl;
	showbyDept(MANAGER, m);
}

void test1()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<bool> v1;
	v1.resize(4);

	transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());

	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(NULL));
	/*test();*/
	test1();

	return 0;
}