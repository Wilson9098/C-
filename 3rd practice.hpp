#pragma once

#include <iostream>
#include <string>
using namespace std;



template<class T>
class Person
{
public:
	string m_Name;
	T m_ID;

	Person(string name, T id);

	void Show();

};

template<class T>
Person<T>::Person(string name, T id)
{
	this->m_Name = name;
	this->m_ID = id;
}

template<class T>
void Person<T>::Show()
{
	cout << "Name: " << this->m_Name << "\nID: " << this->m_ID << endl;

}