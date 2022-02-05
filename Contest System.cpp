#define _CRT_SECURE_NO_WARNINGS 1

#include "Contest System.hpp"
#include <fstream>
#include <map>


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

void getScore(Person& p)
{
	p.m_Score = 60 + (rand() % 41);
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
	cout << "First turn started: ";
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
	cout << endl; 
	system("pause");

	set<Person, myCompare>::iterator it1 = First.begin();
	set<Person, myCompare>::iterator it2 = Second.begin();
	vector<Person> winners;

	winners.push_back(*it1);
	winners.push_back(*(++it1));
	winners.push_back(*(++(++it1)));

	winners.push_back(*it2);
	winners.push_back(*(++it2));
	winners.push_back(*(++(++it2)));

	sort(winners.begin(), winners.end(), myCompare());

	cout << "winners: " << endl;
	for_each(winners.begin(), winners.end(), printPerson);
	cout << endl;
	system("pause");

	cout << "Second turn started: ";
	random_shuffle(winners.begin(), winners.end());
	for_each(winners.begin(), winners.end(), printNO);
	cout << endl;
	system("pause");

	for_each(winners.begin(), winners.end(), getScore);
	for_each(winners.begin(), winners.end(), printPerson);
	cout << endl;
	system("pause");

	cout << "winners: " << endl;
	sort(winners.begin(), winners.end(), myCompare());
	int i = 0;
	ofstream Winner;
	Winner.open("Winner Records.csv", ios::out | ios::app);

	while (i < 3)
	{
		Winner << winners[i].m_Name << "," << winners[i].m_NO << "," << winners[i].m_Score << ",";
		printPerson(winners[i++]);
	}
	Winner << endl;
	Winner.close();

	system("pause");
	system("cls");

}

void clearRecord()
{
	ofstream file;
	file.open("Winner Records.csv", ios::trunc);
	if (!file.is_open())
	{
		cout << "No Records" << endl;
	}
	else
	{
		cout << "Cleared" << endl;
	}

	file.close();
	system("pause");
	system("cls");
}

void loadRecords()
{
	ifstream file;
	file.open("Winner Records.csv", ios::in);
	if (!file.is_open())
	{
		cout << "No Records" << endl;
		file.close();
		return;
	}

	char ch;
	file >> ch;
	if (file.eof())
	{
		cout << "No Records" << endl;
		file.close();
		return;
	}

	file.putback(ch);
	int i = 0;
	map<int, vector<string>> history;
	string data;

	while (file >> data)
	{
		vector<string> v;
		int p = -1;
		int start = 0;

		while (1)
		{
			p = data.find(",", start);
			if (p == -1)
			{
				break;
			}
			else
			{
				string tmp = data.substr(start, p - start);
				v.push_back(tmp);
				start = p + 1;
			}

			
		}

		history.insert(make_pair(++i, v));
		data = "";
	}

	file.close();

	for (map<int, vector<string>>::iterator it = history.begin(); it != history.end(); it++)
	{
		cout << it->first << "   " << "Winner: " << it->second[0] << "   NO: " << it->second[1] << "   Score: " << it->second[2] << endl;
	}
	system("pause");
	system("cls");
}