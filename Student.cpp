#define _CRT_SECURE_NO_WARNINGS 1
#include "Room Order System.hpp"

void Student::operMenu()
{
	cout << "****************************" << endl;
	cout << "******* 1.Order Apply ******" << endl;
	cout << "******* 2.Show My Orders **" << endl;
	cout << "******* 3.Show All Orders **" << endl;
	cout << "******* 4.Order Cancel *****" << endl;
	cout << "******* 0.Logout ***********" << endl;
	cout << "****************************" << endl;

}

void Student::initVector()
{
	this->m_Vr.clear();

	ifstream ifs;
	ifs.open(ROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Can't Load Data" << endl;
		ifs.close();
		return;
	}

	Room r;
	while (ifs >> r.m_Num && ifs >> r.m_Size)
	{
		this->m_Vr.push_back(r);
	}

	ifs.close();
}


void Student::applyorder()
{
	cout << "Please Select a date: " << endl;
	cout << "1. Monday" << endl;
	cout << "2. Tuesday" << endl;
	cout << "3. Wednesday" << endl;
	cout << "4. Thursday" << endl;
	cout << "5. Friday" << endl;

	int date = -1;
	while (1)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}

		cout << "Try Again" << endl;
	}

	cout << "Please Select a time: " << endl;
	cout << "1. Morning" << endl;
	cout << "2. Afternoon" << endl;

	int time = -1;
	while (1)
	{
		cin >> time;
		if (time >= 1 && time <= 2)
		{
			break;
		}

		cout << "Try Again" << endl;
	}

	cout << "Please Select a Room: " << endl;
	for (int i = 0; i < this->m_Vr.size(); i++)
	{
		cout << i+1 << ". RoomNO:" << this->m_Vr[i].m_Num << "  RoomSize:" << this->m_Vr[i].m_Size << endl;
	}

	int Room;
	while (1)
	{
		cin >> Room;
		if (Room >= 1 && Room <= this->m_Vr.size())
		{
			break;
		}

		cout << "Try Again" << endl;
	}

	int status = 1;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "Date:" << date << " " << "Time:" << time << " " << "Name:" << this->m_Username << " " << "ID:" << this->m_StudentID << " "
		<< "RoomNO:" << Room << " " << "Status:" << status << endl;

	ofs.close();
	cout << "Applied. Waiting for pending" << endl;
	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	Order o;
	if (!o.m_OrderData.size())
	{
		cout << "No Order" << endl;
		system("pause");
		system("cls");
		return;
	}

	int count = 0;
	for (int i = 0; i < o.m_OrderData.size(); i++)
	{
		if (atoi(o.m_OrderData[i + 1]["ID"].c_str()) == this->m_StudentID)
		{
			count++;

			cout << "Date:";
			if (o.m_OrderData[i + 1]["Date"] == "1")
			{
				cout  << "Monday" << "   ";
			}
			if (o.m_OrderData[i + 1]["Date"] == "2")
			{
				cout << "Tuesday" << "   ";
			}
			if (o.m_OrderData[i + 1]["Date"] == "3")
			{
				cout << "Wednesday" << "   ";
			}
			if (o.m_OrderData[i + 1]["Date"] == "4")
			{
				cout << "Thursday" << "   ";
			}
			if (o.m_OrderData[i + 1]["Date"] == "5")
			{
				cout << "Friday" << "   ";
			}

			cout << "Time:" << (o.m_OrderData[i + 1]["Time"] == "1" ? "Morning" : "Afternoon") << "   "
				<< "RoomNO:" << o.m_OrderData[i + 1]["RoomNO"] << "   ";
				
			if (o.m_OrderData[i + 1]["Status"] == "1")
			{
				cout << "Status:" << "Pending" << endl;
			}
			else if (o.m_OrderData[i + 1]["Status"] == "2")
			{
				cout << "Status:" << "succeeded" << endl;
			}
			else if (o.m_OrderData[i + 1]["Status"] == "0")
			{
				cout << "Status:" << "Canceled" << endl;
			}
			else if (o.m_OrderData[i + 1]["Status"] == "-1")
			{
				cout << "Status:" << "Failed" << endl;
			}
		}

	}
	if (!count)
	{
		cout << "Your don't have any order yet" << endl;
	}
	
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	Order o;
	if (!o.m_OrderData.size())
	{
		cout << "No Order" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < o.m_OrderData.size(); i++)
	{
			cout << "Date:";
			if (o.m_OrderData[i + 1]["Date"] == "1")
			{
				cout << "Monday" << "   ";
			}
			if (o.m_OrderData[i + 1]["Date"] == "2")
			{
				cout << "Tuesday" << "   ";
			}
			if (o.m_OrderData[i + 1]["Date"] == "3")
			{
				cout << "Wednesday" << "   ";
			}
			if (o.m_OrderData[i + 1]["Date"] == "4")
			{
				cout << "Thursday" << "   ";
			}
			if (o.m_OrderData[i + 1]["Date"] == "5")
			{
				cout << "Friday" << "   ";
			}

			cout << "Time:" << (o.m_OrderData[i + 1]["Time"] == "1" ? "Morning" : "Afternoon") << "   "
				<< "Name:" << o.m_OrderData[i + 1]["Name"] << "   "
				<< "ID:" << o.m_OrderData[i + 1]["ID"] << "   "
				<< "RoomNO:" << o.m_OrderData[i + 1]["RoomNO"] << "   ";

			if (o.m_OrderData[i + 1]["Status"] == "1")
			{
				cout << "Status:" << "Pending" << endl;
			}
			else if (o.m_OrderData[i + 1]["Status"] == "2")
			{
				cout << "Status:" << "succeeded" << endl;
			}
			else if (o.m_OrderData[i + 1]["Status"] == "0")
			{
				cout << "Status:" << "Canceled" << endl;
			}
			else if (o.m_OrderData[i + 1]["Status"] == "-1")
			{
				cout << "Status:" << "Failed" << endl;
			}

	}

	system("pause");
	system("cls");
}

void Student::cancelOrder()
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
	vector<int> v;
	int count = 0;
	for (int i = 0; i < o.m_OrderData.size(); i++)
	{
		if (atoi(o.m_OrderData[i + 1]["ID"].c_str()) == this->m_StudentID)
		{
			if (o.m_OrderData[i + 1]["Status"] == "1" || o.m_OrderData[i + 1]["Status"] == "2")
			{
				count++;
				v.push_back(i+1);

				cout << ++n << ": ";
				cout << "Date:";
				if (o.m_OrderData[i + 1]["Date"] == "1")
				{
					cout << "Monday" << "   ";
				}
				if (o.m_OrderData[i + 1]["Date"] == "2")
				{
					cout << "Tuesday" << "   ";
				}
				if (o.m_OrderData[i + 1]["Date"] == "3")
				{
					cout << "Wednesday" << "   ";
				}
				if (o.m_OrderData[i + 1]["Date"] == "4")
				{
					cout << "Thursday" << "   ";
				}
				if (o.m_OrderData[i + 1]["Date"] == "5")
				{
					cout << "Friday" << "   ";
				}

				cout << "Time:" << (o.m_OrderData[i + 1]["Time"] == "1" ? "Morning" : "Afternoon") << "   "
					<< "RoomNO:" << o.m_OrderData[i + 1]["RoomNO"] << "   ";

				if (o.m_OrderData[i + 1]["Status"] == "1")
				{
					cout << "Status:" << "Pending" << endl;
				}
				else if (o.m_OrderData[i + 1]["Status"] == "2")
				{
					cout << "Status:" << "succeeded" << endl;
				}
			}
		}

	}
	if (!count)
	{
		cout << "Your don't have any order can be canceled yet" << endl;
	}
	else
	{
		int input = -1;
		cout << "0. Return" << endl;
	
		while(1)
		{
			cout << "Please Select: ";
			cin >> input;

			if (!input)
			{
				break;
			}
			if (input >= 1 && input <= n)
			{
				int i = v[input - 1];
				o.m_OrderData[i]["Status"] = "0";
				o.updateOrder();
				cout << "Canceled" << endl;
				break;
			}

			cout << "Try Again" << endl;
		}
	}

	system("pause");
	system("cls");
}