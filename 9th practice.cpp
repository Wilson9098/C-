#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>



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

	bool operator<(const Person& p)
	{
		if (this->m_Name.compare(p.m_Name) > 0)
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
	cout << "----------------------" << endl;

	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), PrintPerson());
	cout << "----------------------" << endl;

	/*srand((unsigned)time(NULL));
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), PrintPerson());
	cout << "----------------------" << endl;*/

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), PrintPerson());
	cout << "----------------------" << endl;

	Person p("X", 100);
	replace_if(v.begin(), v.end(), Age_greater30(),p);
	for_each(v.begin(), v.end(), PrintPerson());
	cout << "----------------------" << endl;

	swap(v, v1);
	for_each(v.begin(), v.end(), PrintPerson());
	cout << "----------------------" << endl;



}

void myPrint(int val)
{
	cout << val << " ";
}

void test01()
{
	vector<int> v;
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}

	v.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;

	int sum = accumulate(v.begin(), v.end(), 0);
	cout << sum << endl;

	fill(v.begin(), v.end(), 0); 
	for_each(v.begin(), v.end(), myPrint);

}

void test02()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> v3;
	v3.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, myPrint);
	cout << endl;

	v3.resize(v1.size() + v2.size());
	itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, myPrint); 
	cout << endl;

	v3.resize(max(v1.size(), v2.size()));
	itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, myPrint);
	cout << endl;
}

int main()
{
	/*test();*/
	/*test01();*/
	test02();

	return 0;
}
