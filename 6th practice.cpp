#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>



void test1()
{
	vector<int> v;

	int n = 0;
	int* p = NULL;
	v.reserve(100000);
	cout << v.capacity() << " " << v.size() << endl;

	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);

		if (p != &v[0])
		{
			p = &v[0];
			n++;
		}
	}
	cout << n << endl;

	cout << v.capacity() << " " << v.size() << endl;

	v.resize(3);

	cout << v.capacity() << " " << v.size() << endl;

	vector<int>(v).swap(v);

	cout << v.capacity() << " " << v.size() << endl;

}

void PrintVector(const vector<int>& v)
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
		
	}
	cout << endl;
}

void test2()
{
	class Person
	{
	public:
		Person(string name, vector<int>* score)
		{
			this->m_Name = name;
			this->m_Score = score;
		}

		string m_Name;
		vector<int>* m_Score;
	};

	vector<int> Ascore = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> Bscore = { 8,7,6,6,3,10,7,6,8,8 };
	vector<int> Cscore = { 6,6,6,6,6,6,6,6,6,6 };
	vector<int> Dscore = { 8,8,8,8,8,8,8,8,8,8 };
	vector<int> Escore = { 10,10,8,8,6,6,9,9,7,7 };

	Person A("A", &Ascore);
	Person B("B", &Bscore);
	Person C("C", &Cscore);
	Person D("D", &Dscore);
	Person E("E", &Escore);

	vector<Person*> p = { &A,&B,&C,&D,&E };

	for (vector<Person*>::iterator it = p.begin(); it != p.end(); it++)
	{
		deque<int> score((*it)->m_Score->begin(), (*it)->m_Score->end());
		sort(score.begin(), score.end());
		score.pop_back();
		score.pop_front();

		int sum = 0;
		for (deque<int>::iterator its = score.begin(); its != score.end(); its++)
		{
			sum += *its;
		}
		cout << sum / 8 << endl;
	}


}

int main()
{
	/*test1();*/
	test2();

	return 0;
}