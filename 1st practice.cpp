#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


struct S
{
	int a;
	int b;
};

typedef class mydata
{
	friend ostream& operator<<(ostream& cout, mydata a);
	friend void test1();
		

private:
	int* n;

	mydata(int x)
	{
		n = new int(x);
	}

public:

	mydata& operator++()
	{
		n++;
		return *this;
	}

	const mydata operator++(int)
	{
		mydata tmp = *this;
		n++;
		return tmp;	
	}

	mydata& operator=(mydata& a)
	{
		if (n)
		{
			delete n;
			n = NULL;
		}
		
		n = new int(*a.n);
		return *this;
	}

}md;

ostream& operator<<(ostream& cout, mydata a)
{
	cout << a.n;
	return cout;
}

void test1()
{
	/*md a;*/
	/*cout << ++(++a) << endl;
	cout << a << endl;*/

	/*cout << a++ << endl;
	cout << a << endl;*/

	md x(10), y(20), z(30);

	x = y = z;

	cout << *x.n << endl;
	cout << *y.n << endl;
	cout << *z.n << endl;
	
}

//class Add
//{
//public:
//	int operator()(int a, int b);
//	
//};
//
//int Add :: operator()(int a, int b)
//{
//	return a + b;
//}

class Calculator
{
public:
	virtual int calculator(int a, int b) = 0;
};

class Add :public Calculator
{
public:
	/*virtual */int calculator(int a, int b)
	{
		return a + b;
	}
};

class Sub :public Calculator
{
public:
	virtual int calculator(int a, int b)
	{
		return a - b;
	}
};

class Mul :public Calculator
{
public:
	virtual int calculator(int a, int b)
	{
		return a * b;
	}
};

class Div :public Calculator
{
public:
	virtual int calculator(int a, int b)
	{
		return a / b;
	}
};

void test2()
{
	Calculator* add = new Add;
	cout << add->calculator(10, 100) << endl;
	delete add;
	add = NULL;

	Calculator* sub = new Sub;
	cout << sub->calculator(100, 10) << endl;
	delete sub;
	sub = NULL;

	Calculator* mul = new Mul;
	cout << mul->calculator(100, 10) << endl;
	delete mul;
	mul = NULL;

	Calculator* div = new Div;
	cout << div->calculator(100, 10) << endl;
	delete div;
	div = NULL;

}

class Animal
{
public:
	virtual void Print()
	{
		cout << "Animal" << endl;
	}
};

class Cat :public Animal
{
public:
	void Print()
	{
		cout << "Cat" << endl;
	}

};

void print(Animal& x)
{
	x.Print();
}

void test3()
{
	Cat cat;
	print(cat);
}

int main()
{
	/*test1();*/
	/*test2();*/
	test3();

	/*S s1;
	s1.a = 10;
	s1.b = 0;

	S tmp = s1;
	s1.a = 20;

	cout << tmp.a;*/

	

	return 0;
}