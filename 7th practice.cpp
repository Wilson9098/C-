#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <list>



class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;

};

bool Compare(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Name < p2.m_Name;
	}

	return p1.m_Age > p2.m_Age;
}

void test()
{
	Person p1("A", 28, 180);
	Person p2("B", 30, 190);
	Person p3("C", 30, 178);
	Person p4("D", 30, 166);
	Person p5("E", 25, 188);

	list<Person> L;
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);

	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "Name: " << it->m_Name << " " << "Age: " << it->m_Age << " " << "Height: " << it->m_Height << endl;
	}

	cout << "Sorted: " << endl;

	L.sort(Compare);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "Name: " << it->m_Name << " " << "Age: " << it->m_Age << " " << "Height: " << it->m_Height << endl;
	}
}

int main()
{
	test();

	return 0;
}