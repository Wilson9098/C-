#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>



class Person
{
public:
	Person()
	{
		this->m_Name = " ";
		this->m_Age = 0;
	}

	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==(const Person& p)
	{
		if (this->m_Age == p.m_Age/* && this->m_Name == p.m_Name*/)
		{
			return true;
		}
		else
			return false;
	}

	string m_Name;
	int m_Age;

};

void printperson(const Person& p)
{
	cout << "Name: " << p.m_Name << " Age: " << p.m_Age << endl;
}

class PrintPerson
{
public:
	void operator()(const Person& p)
	{
		cout << "Name: " << p.m_Name << " Age: " << p.m_Age << endl;
	}
};

class change
{
public:
	Person operator()(Person p)
	{
		p.m_Age += 1;
		return p;
	}
};

class Age_greater30
{
public:
	bool operator()(const Person& p)
	{
		if (p.m_Age > 30)
			return true;
		else
			return false;
	}
};

void test()
{
	Person p1("A", 30);
	Person p2("B", 30);
	Person p3("C", 30);
	Person p4("D", 25);
	Person p5("E", 45);

	vector<Person> v;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	/*for_each(v.begin(), v.end(), printperson);*/
	for_each(v.begin(), v.end(), PrintPerson());
	cout << "----------------------" << endl;

	vector<Person> v1;
	v1.resize(v.size());

	transform(v.begin(), v.end(), v1.begin(), change());
	for_each(v.begin(), v.end(), PrintPerson());
	cout << "----------------------" << endl;

	vector<Person>::iterator it = find_if(v1.begin(), v1.end(), Age_greater30());
	if (it == v1.end())
	{
		cout << "Can't Find It" << endl;
	}
	else
	{
		printperson(*it);
	}
	cout << "----------------------" << endl;

	vector<Person>::iterator it1 = adjacent_find(v.begin(), v.end());
	if (it1 == v.end())
	{
		cout << "Can't Find It" << endl;
	}
	else
	{
		printperson(*it1);
	}
	cout << "----------------------" << endl;

	cout << count_if(v1.begin(), v1.end(), Age_greater30()) << endl;
}

int main()
{
	test();

	return 0;
}
