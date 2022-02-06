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

void Login(int type)
{

	int id = 0;
	string name;
	string psw;
	if (type != 3)
	{
		cout << "Please input your ID: " << endl;
		cin >> id;
	}

	cout << "Please input your username: " << endl;
	cin >> name;
	cout << "Please input your password: " << endl;
	cin >> psw;

	if (type == 1)
	{
		//check
	}
	else if (type == 2)
	{
		//check
	}
	else if (type == 3)
	{
		//check
	}

	cout << "Your ID, Username or Password is incorrect" << endl;
	system("pause");
	system("cls");
}