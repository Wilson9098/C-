#define _CRT_SECURE_NO_WARNINGS 1

#include "Contest System.hpp"


void Menu()
{
	cout << "**********************************" << endl;
	cout << "******** 1. Speech Start *********" << endl;
	cout << "******** 2. Review History *******" << endl;
	cout << "******** 3. Empty History ********" << endl;
	cout << "******** 0. Exit System   ********" << endl;
	cout << "**********************************" << endl;

}

void printNO(const Person& p)
{
	cout << p.m_NO << " ";
}

void printPerson(const Person& p)
{
	cout << "Name: " << p.m_Name << "   NO: " << p.m_NO << "   Score: " << p.m_Score << endl;
}

void Speech()
{
	Person p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12;
	vector<Person>person;
	person.push_back(p1);
	person.push_back(p2);
	person.push_back(p3);
	person.push_back(p4);
	person.push_back(p5);
	person.push_back(p6);
	person.push_back(p7);
	person.push_back(p8);
	person.push_back(p9);
	person.push_back(p10);
	person.push_back(p11);
	person.push_back(p12);

	srand((unsigned)time(NULL));

	string NameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < person.size(); i++)
	{
		person[i].m_Name = NameSeed[i];
		person[i].m_NO = 10000 + i;
		person[i].m_Score = 60 + (rand() % 41);
	}

	random_shuffle(person.begin(), person.end());
	cout << "First trun started: ";
	for_each(person.begin(), person.end(), printNO);
	cout << endl;
	system("pause");

	set<Person, myCompare> First;
	set<Person, myCompare> Second;

	for (int i = 0; i < person.size() / 2; i++)
	{
		First.insert(person[i]);
	}
	for (int i = person.size() / 2; i < person.size(); i++)
	{
		Second.insert(person[i]);
	}

	cout << "First group scores: " << endl;
	for_each(First.begin(), First.end(), printPerson);
	cout << "Second group scores: " << endl;
	for_each(Second.begin(), Second.end(), printPerson);
	


	system("pause");
	system("cls");
}