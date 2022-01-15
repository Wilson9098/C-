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
	
	cout << "Added " << addNum << " Person" << endl;

	system("pause");
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


bool System::Search(int id)
{
	/*if (!Arrsize)
	{
		cout << "No Data" << endl;
		return;
	}*/

	/*int id;
	cout << "Please Input an ID" << endl;
	cin >> id;*/

	/*int count = 0;*/
	bool ret = false;
	for (int i = 0; i < Arrsize; i++)
	{
		if (arr[i]->m_ID == id)
		{
			/*cout << "Name: " << arr[i]->m_Name << endl;
			cout << "ID: " << arr[i]->m_ID << endl;
			cout <<"Department: " << arr[i]->m_DeptNO << endl;*/
			arr[i]->showInfo();
			cout << endl;
			/*count++;*/
			ret = true;
		}
	}

	if (!ret)
		cout << "Can't Find It" << endl;

	system("pause");
	system("cls");
	return ret;
}

bool System::Search(string name)
{
	/*if (!Arrsize)
	{
		cout << "No Data" << endl;
		return;
	}*/

	/*string name;
	cout << "Please Input a Name" << endl;
	cin >> name;*/

	/*int count = 0;*/
	bool ret = false;
	for (int i = 0; i < Arrsize; i++)
	{
		if (arr[i]->m_Name == name)
		{
			/*cout << "Name: " << arr[i]->m_Name << endl;
			cout << "ID: " << arr[i]->m_ID << endl;
			cout << "Department: " << arr[i]->m_DeptNO << endl;*/
			arr[i]->showInfo();
			cout << endl;
			/*count++;*/
			ret = true;
		}
	}

	if (!ret)
		cout << "Can't Find It" << endl;

	system("pause");
	system("cls");
	return ret;
}

bool System::Search()
{
	if (!Arrsize)
	{
		cout << "No Data" << endl;
		return false;
	}

	cout << "Search by:" << endl;
	cout << "1. ID" << endl;
	cout << "2. Name" << endl;
	int select = 0;
	do
	{
		cin >> select;
	} while (select < 1 || select > 2);

	if (select == 1)
	{
		int id;
		cout << "Please Input an ID" << endl;
		cin >> id;
		return Search(id);
	}

	if (select == 2)
	{
		string name;
		cout << "Please Input a Name" << endl;
		cin >> name;
		return Search(name);
	}

}


int System::Exit(int id)
{
	for (int i = 0; i < Arrsize; i++)
	{
		if (arr[i]->m_ID == id)
		{
			arr[i]->showInfo();
			cout << endl;
			return i;
		}
	}

	return -1;
}

void System::Delete()
{
	if (!Arrsize)
	{
		cout << "No Data" << endl;
		return;
	}

	int id;
	cout << "Please Input an ID" << endl;
	cin >> id;

	int i = Exit(id);
	if (i >= 0)
	{
		int select = 0;
		do 
		{
			cout << "Do You Want To Delete It?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			cin >> select;
		} while (select < 1 || select > 2);

		if (select == 1)
		{
			i++;
			for (; i < Arrsize; i++)
			{
				arr[i - 1] = arr[i];
			}

			Arrsize--;
			cout << "Deleted" << endl;
		}
	}
	else
	{
		cout << "Can't Find It" << endl;
	}

	system("pause");
	system("cls");
}


void System::Modify()
{
	if (!Arrsize)
	{
		cout << "No Data" << endl;
		return;
	}

	int id;
	cout << "Please Input an ID" << endl;
	cin >> id;

	int i = Exit(id);
	if (i >= 0)
	{
		cout << "Please Input a Name" << endl;
		cin >> arr[i]->m_Name;
		cout << "Please Input an ID" << endl;
		cin >> arr[i]->m_ID;

		int dept;
		do
		{
			cout << "Please Select a Department" << endl;
			cout << "1. Staff" << endl;
			cout << "2. Manager" << endl;
			cout << "3. Boss" << endl;
			cin >> dept;
		} while (dept < 1 || dept > 3);
		
		arr[i]->m_DeptNO = dept;
		cout << "Modified" << endl;
	}
	else
	{
		cout << "Can't Find It" << endl;
	}

	system("pause");
	system("cls");
}


void System::Sort()
{
	if (!Arrsize)
	{
		cout << "No Data" << endl;
		return;
	}

	int select = 0;
	do
	{
		cout << "Sort by:" << endl;
		cout << "1. ID" << endl;
		cout << "2. Name" << endl;
		cin >> select;
	} while (select < 1 || select > 2);

	if (select == 1)
	{
		SortbyID(arr,0,Arrsize-1);
	}

	if (select == 2)
	{
		SortbyName(arr, 0, Arrsize - 1);
	}

	cout << "Sorted" << endl;
	system("pause");
	system("cls");
}

void System::Swap(Person** arr, int a, int b)
{
	assert(arr);

	Person* tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

int System::ComparebyID(Person* a, Person* b)
{
	assert(a && b);

	return a->m_ID - b->m_ID;
}

int System::ComparebyName(Person* a, Person* b)
{
	assert(a && b);

	return a->m_Name.compare(b->m_Name);
}


void System::PatitionbyID(Person** arr, const int L, const int R, int* ret)
{
	assert(arr && ret);
	if (L >= R)
		return;

	int pL = L - 1;
	int pR = R;
	int i = L;

	while (i < pR)
	{
		if (ComparebyID(arr[i], arr[R])<0)
		{
			Swap(arr, i++, ++pL);
		}
		else if (ComparebyID(arr[i], arr[R]) > 0)
		{
			Swap(arr, i, --pR);
		}
		else
		{
			i++;
		}
	}
	Swap(arr, R, pR++);
	ret[0] = pL;
	ret[1] = pR;
}

void System::PatitionbyName(Person** arr, const int L, const int R, int* ret)
{
	assert(arr && ret);
	if (L >= R)
		return;

	int pL = L - 1;
	int pR = R;
	int i = L;

	while (i < pR)
	{
		if (ComparebyName(arr[i], arr[R]) < 0)
		{
			Swap(arr, i++, ++pL);
		}
		else if (ComparebyName(arr[i], arr[R]) > 0)
		{
			Swap(arr, i, --pR);
		}
		else
		{
			i++;
		}
	}
	Swap(arr, R, pR++);
	ret[0] = pL;
	ret[1] = pR;
}

//void System::QuickSort(Person** arr, const int L, const int R)
//{
//	assert(arr);
//	if (L >= R)
//		return;
//
//	srand((unsigned)time(NULL));
//	Swap(arr, R, L + rand() % (R - L + 1));
//	int ret[2] = { 0 };
//
//	Patition(arr, L, R, ret);
//	QuickSort(arr, L, ret[0]);
//	QuickSort(arr, ret[1], R);
//}

void System::SortbyID(Person** arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	srand((unsigned)time(NULL));
	Swap(arr, R, L + rand() % (R - L + 1));
	int ret[2] = { 0 };

	PatitionbyID(arr, L, R, ret);
	SortbyID(arr, L, ret[0]);
	SortbyID(arr, ret[1], R);
}

void System::SortbyName(Person** arr, const int L, const int R)
{
	assert(arr);
	if (L >= R)
		return;

	srand((unsigned)time(NULL));
	Swap(arr, R, L + rand() % (R - L + 1));
	int ret[2] = { 0 };

	PatitionbyName(arr, L, R, ret);
	SortbyID(arr, L, ret[0]);
	SortbyID(arr, ret[1], R);
}

void System::Empty()
{
	if (!Arrsize)
	{
		cout << "No Data" << endl;
		return;
	}

	int select = 0;
	do
	{
		cout << "Empty the System?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> select;
	} while (select < 1 || select > 2);

	if (select == 1)
	{
		ofstream file;
		file.open("System.txt", ios::trunc);
		file.close();

		int i = 0;
		for (i = 0; i < Arrsize; i++)
		{
			delete arr[i];
		}
		delete[] arr;
		arr = new Person * [2];
		Arrsize = 0;
		Maxsize = 2;

		cout << "Emptied" << endl;
	}
	
	system("pause");
	system("cls");

}