#define _CRT_SECURE_NO_WARNINGS 1
#include "5th practice.hpp"

void Print(Person p)
{
	cout << "Name: " << p.m_Name << "\nAge: " << p.m_Age << endl;
}
	

void Func(vector<Person>* p)
{
	for_each(p->begin(), p->end(), Print);
}

void test1()
{
	Person p1("aaa", 1);
	Person p2("bbb", 2);
	Person p3("ccc", 3);
	Person p4("ddd", 4);
	Person p5("eee", 5);


	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for_each(v.begin(), v.end(), Print);
	/*Func(v);*/
}



void test2()
{

	Person p1("aaa", 1);
	Person p2("bbb", 1);

	Person p3("ccc", 2);
	Person p4("ddd", 2);

	Person p5("eee", 3);
	Person p6("fff", 3);


	vector<vector<Person>*> v;

	vector<Person> v1;
	vector<Person> v2;
	vector<Person> v3;


	v.push_back(&v1);
	v.push_back(&v2);
	v.push_back(&v3);


	v1.push_back(p1);
	v1.push_back(p2);

	v2.push_back(p3);
	v2.push_back(p4);

	v3.push_back(p5);
	v3.push_back(p6);


	for_each(v.begin(), v.end(), Func);
}

void test3()
{
	string s1("Hello World");
	cout << s1 << endl;

	string s2(s1,6);
	cout << s2 << endl;

	string s3("Hello World", 5);
	cout << s3 << endl;

	s3 += " " + s2;
	cout << s3 << endl;

}

int main()
{
	/*test1();*/
	/*test2();*/
	test3();

	return 0;
}