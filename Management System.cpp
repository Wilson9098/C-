#define _CRT_SECURE_NO_WARNINGS 1

#include "Management System.h"





System::System()
{
	arr = new Person * [2];
	Arrsize = 0;
	Maxsize = 2;

	ifstream file;
	file.open("System.txt", ios::in);
	if (!file.is_open())
		return;

	int i = 0;
	string name;
	int id = 0;
	int dept = 0;
	while (file >> name && file >> id && file >> dept)
	{
		Arrsize++;
		checkCapacity();

		Person* p = NULL;
		if (dept == 1)
		{
			p = new Staff(name, id, dept);
		}
		if (dept == 2)
		{
			p = new Manager(name, id, dept);
		}
		if (dept == 3)
		{
			p = new Boss(name, id, dept);
		}

		arr[i++] = p;
	}

	file.close();
}

System::~System()
{
	int i = 0;
	for (i = 0; i < Arrsize; i++)
	{
		delete arr[i];
	}
	delete[] arr;
	arr = NULL;
}


void System::showMenu()
{
	cout << "*************************************" << endl;
	cout << "******** Welcome  to  System!   *****" << endl;
	cout << "********* 1.Add Information *********" << endl;
	cout << "********* 2.Display Information *****" << endl;
	cout << "********* 3.Delete Information ******" << endl;
	cout << "********* 4.Modify Information ******" << endl;
	cout << "********* 5.Search Information ******" << endl;
	cout << "********* 6.Sort Information ********" << endl;
	cout << "********* 7.Empty Information *******" << endl;
	cout << "********* 0.    Exit     ************" << endl;
	cout << "*************************************" << endl;
}


void System::checkCapacity()
{
	if (Arrsize < Maxsize)
		return;

	while (Arrsize >= Maxsize)
	{
		Person** tmp = (Person**)realloc(arr, 2 * Maxsize * sizeof(Person*));
		if (!tmp)
		{
			cout << "Expanding Failed" << endl;
			return;
		}
		arr = tmp;
		Maxsize *= 2;
	}

	cout << "Expanded" << endl;
}

void System::Add()
{
	int addNum = 0;

	cout << "How many person need to add" << endl;
	cin >> addNum;

	if (addNum > 0)
	{
		string name;
		int id = 0;
		int dept = 0;

		int i = 0;
		for (i = 1; i <= addNum; i++)
		{
			checkCapacity();

			cout << "Please Input Name of Person" << i << endl;
			cin >> name;
			cout << "Please Input ID of Person" << i << endl;
			cin >> id;
			do
			{
				cout << "Please Select Department of Person" << i << endl;
				cout << "1. Staff" << endl;
				cout << "2. Manager" << endl;
				cout << "3. Boss" << endl;
				cin >> dept;
			} while (dept < 1 || dept>3);

			Person* p = NULL;
			switch (dept)
			{
			case 1:
				p = new Staff(name, id, dept);
				break;
			case 2:
				p = new Manager(name, id, dept);
				break;
			case 3:
				p = new Boss(name, id, dept);
				break;
			default:
				break;
			}

			arr[Arrsize] = p;
			Arrsize++;
		}

		/*Arrsize = Arrsize + addNum;*/
	}
	else
	{
		cout << "Try Again" << endl;
	}
	
	system("cls");


}

void System::Save()
{
	ofstream file;
	file.open("System.txt", ios::out);

	for (int i = 0; i < Arrsize; i++)
	{
		file << arr[i]->m_Name << " " << arr[i]->m_ID << " " << arr[i]->m_DeptNO << endl;
	}
	file.close();
}


void System::Display()
{
	for (int i = 0; i < Arrsize; i++)
	{
		arr[i]->showInfo();
		cout << endl;
	}

	system("pause");
	system("cls");
}