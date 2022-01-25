#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <set>



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

class compareName
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.m_Name > p2.m_Name;
	}
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

void test1()
{
	set<Person, compareName> s1;

	Person p1("A", 28, 180);
	Person p2("B", 30, 190);
	Person p3("C", 30, 178);
	Person p4("D", 30, 166);
	Person p5("E", 25, 188);

	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);
	s1.insert(p5);

	for (set<Person, compareName>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << "Name: " << it->m_Name << " " << "Age: " << it->m_Age << " " << "Height: " << it->m_Height << endl;
	}

}

int main()
{
	/*test();*/

	test1();

	return 0;
}