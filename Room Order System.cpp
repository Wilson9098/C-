#define _CRT_SECURE_NO_WARNINGS 1
#include "Room Order System.hpp"




void showMenu()
{
	cout << "================ Welcome to Room Order System ===============" << endl;
	cout << endl;

	cout << "\t\t ----------------------------\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|       1. Student Login     |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|       2. Teacher Login     |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|       3. Manager Login     |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t|       0.     Exit          |\n";
	cout << "\t\t|                            |\n";
	cout << "\t\t ----------------------------\n";
}

void Login(string file, int type)
{
	ifstream ifs;
	ifs.open(file, ios::in);
	if (!ifs.is_open())
	{
		cout << "Can't open file" << endl;
		ifs.close();
		system("pause");
		system("cls");
		return;
	}

	int id_input = 0;
	string name_input;
	string psw_input;
	if (type != 3)
	{
		cout << "Please input your ID: " << endl;
		cin >> id_input;
	}

	cout << "Please input your username: " << endl;
	cin >> name_input;
	cout << "Please input your password: " << endl;
	cin >> psw_input;

	bool info = false;
	if (type == 1)//student
	{
		int id;
		string name;
		string psw;
		while (ifs >> id && ifs >> name && ifs >> psw)
		{
			if (id == id_input && name == name_input && psw == psw_input)
			{
				info = true;
				Student student(name, psw, id);
				system("cls");
				cout << "Welcome to student system" << endl;
				studentMenu(student);
			}
		}
	}
	else if (type == 2)//teacher
	{
		int id;
		string name;
		string psw;
		while (ifs >> id && ifs >> name && ifs >> psw)
		{
			if (id == id_input && name == name_input && psw == psw_input)
			{
				info = true;
				/*Teacher teacher(name, psw, id);*/
				system("cls");
				cout << "Welcome to teacher system" << endl;

			}
		}
	}
	else if (type == 3)//manager
	{
		string name;
		string psw;
		while (ifs >> name && ifs >> psw)
		{
			if (name == name_input && psw == psw_input)
			{
				info = true;
				Manager manager(name, psw);
				system("cls");
				cout << "Welcome to manager system" << endl;
				managerMenu(manager);
			}
		}
	}

	if (!info)
		cout << "Your ID, Username or Password is incorrect" << endl;

	ifs.close();
	system("pause");
	system("cls");
}

void managerMenu(Manager& manager)
{
	int input;
	manager.initVector();

	do
	{
		cout << "Student Number: " << manager.m_Vs.size() << endl;
		cout << "Teacher Number: " << manager.m_Vt.size() << endl;
		cout << "Room Number: " << manager.m_Vr.size() << endl;
		manager.operMenu();

		cout << "Please Select: ";
		cin >> input;

		switch (input)
		{
		case 1:
			manager.addUser();
			break;
		case 2:
			manager.showAllUsers();
			break;
		case 3:
			manager.showAllRooms();
			break;
		case 4:
			manager.clearAllRecords();
			break; 
		case 0:
			cout << "Logged out" << endl;
			return;
			break;
		default:
			cout << "Try Again" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (input);


}

void studentMenu(Student& student)
{
	int input = -1;
	student.initVector();

	do
	{
		student.operMenu();
		cout << "Please Select: ";
		cin >> input;

		switch (input)
		{
		case 1:
			student.applyorder();
			break;
		case 2:
			student.showMyOrder();
			break;
		case 3:
			break;
		case 4:
			break;
		case 0:
			break;
		default:
			cout << "Try Again" << endl;
			system("pause");
			system("cls");
			break;
		}
	} while (input);
}