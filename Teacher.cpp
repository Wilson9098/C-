#define _CRT_SECURE_NO_WARNINGS 1
#include "Room Order System.hpp"

void Teacher::operMenu()
{
	cout << "*******************************" << endl;
	cout << "******** 1. Show All Order ****" << endl;
	cout << "******** 2. Valid Order    ****" << endl;
	cout << "******** 0. Logout   **********" << endl;
	cout << "*******************************" << endl;
}


void Teacher::showAllOrder()
{
	Student().showAllOrder();
}

void Teacher::validOrder()
{
	Order o;
	if (!o.m_OrderData.size())
	{
		cout << "No Order" << endl;
		system("pause");
		system("cls");
		return;
	}

	int n = 0;
	int count = 0;
	vector<int> v;
	for (int i = 0; i < o.m_OrderData.size(); i++)
	{
		if (o.m_OrderData[i + 1]["Status"] == "1")
		{
			v.push_back(i + 1);
			count++;

			cout << ++n << ". " << "Date:";

			if (o.m_OrderData[i + 1]["Date"] == "1")
			{
				cout << "Monday" << "   ";
			}
			else if (o.m_OrderData[i + 1]["Date"] == "2")
			{
				cout << "Tuesday" << "   ";
			}
			else if (o.m_OrderData[i + 1]["Date"] == "3")
			{
				cout << "Wednesday" << "   ";
			}
			else if (o.m_OrderData[i + 1]["Date"] == "4")
			{
				cout << "Thursday" << "   ";
			}
			else if (o.m_OrderData[i + 1]["Date"] == "5")
			{
				cout << "Friday" << "   ";
			}

			cout << "Time:" << (o.m_OrderData[i + 1]["Time"] == "1" ? "Morning" : "Afternoon") << "   ";

			cout << "Name:" << o.m_OrderData[i + 1]["Name"] << "   " << "ID:" << o.m_OrderData[i + 1]["ID"] << "   "
				<< "RoomID:" << o.m_OrderData[i + 1]["RoomID"] << "   ";

			cout << "Status:" << "Pending" << endl;
		}
	}
	if (!count)
	{
		cout << "No Pending Order" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "0. Return" << endl;
	int input = -1;
	while (1)
	{
		cout << "Please Select: ";
		cin >> input;
		if (input >= 1 && input <= n)
		{
			break;
		}
		else if (!input)
		{
			system("pause");
			system("cls");
			return;
		}

		cout << "Try Again" << endl;
	}

	int i = v[input - 1];
	input = -1;
	cout << "1. Pass" << endl;
	cout << "2. Fail" << endl;
	while (1)
	{
		cout << "Please Select: ";
		cin >> input;
	
		if (input == 1)
		{
			o.m_OrderData[i]["Status"] = "2";
			cout << "Finished" << endl;
			break;
		}
		else if (input == 2)
		{
			o.m_OrderData[i]["Status"] = "-1";
			cout << "Finished" << endl;
			break;
		}

		cout << "Try Again" << endl;
	}

	o.updateOrder();
	system("pause");
	system("cls");
}