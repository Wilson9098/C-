#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <iostream>
using namespace std;
#include <string>

template<class T1,class T2>
class Person
{
public:
	Person() {};
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	T1 m_Name;
	T2 m_Age;
};

//template <class T>
//class myArr;

//template<class T>
//void Print(myArr<T>* p)
//{
//	for (int i = 0; i < p->m_Size; i++)
//	{
//		cout << (*p)[i] << endl;
//	}
//}




template<class T>
class myArr
{
	/*friend void Print<>(myArr<T>* p); */
	friend void Print(myArr<T>* p)
	{
		for (int i = 0; i < p->m_Size; i++)
		{
			cout << (*p)[i] << endl;
		}
	}


	friend void Print(myArr<T>& p)
	{
		for (int i = 0; i < p.m_Size; i++)
		{
			cout << "Name: " << p[i].m_Name << "\nAge: " << p[i].m_Age << endl;
		}
	}

public:
	myArr() {};
	myArr(int capacity)
	{
		if (capacity <= 0)
		{
			return;
		}
		this->m_Arr = new T[capacity];
		this->m_Capacity = capacity;
		this->m_Size = 0;
	}

	myArr(const myArr* p)
	{
		this->m_Capacity = p->m_Capacity;
		this->m_Size = p->m_Size;

		this->m_Arr = new T[p->m_Capacity];
		for (int i = 0; i < p->m_Size; i++)
		{
			m_Arr[i] = p->m_Arr[i];
		}
	}

	myArr& operator=(const myArr& p)
	{
		if (!this->m_Arr)
		{
			delete[] this->m_Arr;
			this->m_Arr = NULL;
			this->m_Arr = new T[p.m_Capacity];
		}
	}

	void Push_Back(T data)
	{
		if (this->m_Size >= this->m_Capacity)
		{
			cout << "Full" << endl;
			return;
		}

		this->m_Arr[this->m_Size] = data;
		this->m_Size++;
	}

	void Pop_Back()
	{
		if (!this->m_Size)
			return;

		this->m_Size--;
	}

	T& operator[](int index)
	{
		return this->m_Arr[index];
	}


	~myArr()
	{
		if (!this->m_Arr)
		{
			delete[] this->m_Arr;
			this->m_Arr = NULL;
		}
	}

private:
	T* m_Arr;
	int m_Capacity;
	int m_Size;
};