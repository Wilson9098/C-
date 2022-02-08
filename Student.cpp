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
	
	system("pause");
	system("cls");
}