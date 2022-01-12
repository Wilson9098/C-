#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <fstream>
#include <string>


class Person
{
public:
	/*Person(char* name, int age, char* gender)
	{
		m_Name = name;
		m_Age = age;
	}*/

	char m_Name[32];
	int m_Age;
	char m_Gender[10];
};

void test1()
{
	ofstream file;

	file.open("Test.txt", ios::out);

	file << "Name:Wilson" << endl; 
	file << "Age:27" << endl;
	file << "Gender:Male" << endl;

	file.close();
}

void test2()
{
	ifstream file;

	file.open("Test.txt", ios::in);
	if (!file.is_open())
	{
		cout << "file opening failed" << endl;
	}

	/*char buf[1024] = { 0 };*/
	/*while (file >> buf)
	{
		cout << buf << endl;
	}*/

	/*while (file.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}*/

	/*string buf;
	while (getline(file, buf))
	{
		cout << buf << endl;
	}*/

	char c;
	while ((c= file.get()) != EOF)
	{
		cout << c;
	}

	file.close();
}

//void test3()
//{
//	ofstream file;
//
//	file.open("Person.txt", ios::binary | ios::out);
//
//	Person person = { "Wilson", 27,"Male" };
//	file.write((const char*)&person, sizeof(Person));
//
//	file.close();
//	
//
//
//}

void test4()
{
	ifstream file;

	file.open("Person.txt", ios::binary | ios::in);
	if (!file.is_open())
	{
		cout << "file opening failed" << endl;
	}

	Person p;
	file.read((char*)&p, sizeof(Person));
	cout << "Name: " << p.m_Name << endl;
	cout << "Age: " << p.m_Age << endl;
	cout << "Gender: " << p.m_Gender << endl;

	file.close();
}

int main()
{
	/*test1();*/
	/*test2();*/
	/*test3();*/
	test4();

	return 0;
}