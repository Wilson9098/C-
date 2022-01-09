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

class Add
{
public:
	int operator()(int a, int b);
	
};

int Add :: operator()(int a, int b)
{
	return a + b;
}


void test2()
{
	cout << Add()(1, 2) << endl;
}

int main()
{
	/*test1();*/
	test2();

	/*S s1;
	s1.a = 10;
	s1.b = 0;

	S tmp = s1;
	s1.a = 20;

	cout << tmp.a;*/

	

	return 0;
}