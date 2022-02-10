#define _CRT_SECURE_NO_WARNINGS 1
#include "Room Order System.hpp"


void Manager::operMenu()
{
	cout << "********************************" << endl;
	cout << "******** 1. Add User **********" << endl;
	cout << "******** 2. Show All Users ****" << endl;
	cout << "******** 3. Show All Rooms ****" << endl;
	cout << "******** 4. Clear Records *****" << endl;
	cout << "******** 0. Logout   **********" << endl;
	cout << "********************************" << endl;
}

void Manager::initVector()
{
	this->m_Vs.clear();
	this->m_Vt.clear();
	this->m_Vr.clear();

	ifstream ifs;

	Student s;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Can't Load Data" << endl;
		ifs.close();
		return;
	}

	while (ifs >> s.m_StudentID && ifs >> s.m_Username && ifs >> s.m_Password)
	{
		this->m_Vs.push_back(s);
	}

	/*cout << "Student Number: " << this->m_Vs.size() << endl;*/
	ifs.close();//student


	Teacher t;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Can't Load Data" << endl;
		return;
	}

	while (ifs >> t.m_TeacherID && ifs >> t.m_Username && ifs >> t.m_Password)
	{
		this->m_Vt.push_back(t);
	}

	/*cout << "Teacher Number: " << this->m_Vt.size() << endl;*/
	ifs.close();//teacher


	ifs.open(ROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Can't Load Data" << endl;
		return;
	}

	Room r;
	while (ifs >> r.m_Num && ifs >> r.m_Size)
	{
		this->m_Vr.push_back(r);
	}
	ifs.close();
}

void Manager::addUser()
{
	int input;
	string filename;
	ofstream ofs;

	while(1)
	{
		cout << "1.Add a student" << endl;
		cout << "2.Add a teacher" << endl;
		cout << "Please Select: ";
		cin >> input;

		if (input == 1)//student
		{
			filename = STUDENT_FILE;
			break;
		}
		else if (input == 2)//teacher
		{
			filename = TEACHER_FILE;
			break;
		}
		else 
		{
			cout << "Try again" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string psw;


	cout << "Please input your ID" << endl;
	cin >> id;
	if (isRepeat(input, id))
	{
		cout << "This ID has existed" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "Please input username" << endl;
	cin >> name;
	cout << "Please input password" << endl;
	cin >> psw;

	ofs << id << " " << name << " " << psw << endl;
	if (input == 1)
	{
		Student s(name, psw, id);
		this->m_Vs.push_back(s);
	}
	else if (input == 2)
	{
		Teacher t(name, psw, id);
		this->m_Vt.push_back(t);
	}

	cout << "Added" << endl;
	system("pause");
	system("cls");
	ofs.close();

	/*this->initVector();*/
}

ostream& operator<<(ostream& os, const Student& s)
{
	os << s.m_StudentID << " " << s.m_Username << " " << s.m_Password;
	return os;
}

ostream& operator<<(ostream& os, const Teacher& t)
{
	os << t.m_TeacherID << " " << t.m_Username << " " << t.m_Password;
	return os;
}

void Manager::showAllUsers()
{
	if (!(this->m_Vs.size() + this->m_Vt.size()))
	{
		cout << "No user" << endl;
	}

	if (this->m_Vs.size())
	{
		cout << "Student: " << endl;
		for (vector<Student>::iterator it = this->m_Vs.begin(); it != this->m_Vs.end(); it++)
		{
			cout << *it << endl;
		}
	}

	if (this->m_Vt.size())
	{
		cout << "\nTeacher: " << endl;
		for (vector<Teacher>::iterator it = this->m_Vt.begin(); it != this->m_Vt.end(); it++)
		{
			cout << *it << endl;
		}
	}

	system("pause");
	system("cls");
}

bool Manager::isRepeat(int type, int id)
{
	if (type == 1)
	{
		if (this->m_Vs.size())
		{
			for (vector<Student>::iterator it = this->m_Vs.begin(); it != this->m_Vs.end(); it++)
			{
				if (it->m_StudentID == id)
					return true;
			}
			return false;
		}
		else
			return false;
	}

	if (type == 2)
	{
		if (this->m_Vt.size())
		{
			for (vector<Teacher>::iterator it = this->m_Vt.begin(); it != this->m_Vt.end(); it++)
			{
				if (it->m_TeacherID == id)
					return true;
			}
			return false;
		}
		else
			return false;
	}
}

void printRoom(const Room& r)
{
	cout << "Room NO: " << r.m_Num << "  Room Size: " << r.m_Size << endl;
}

void Manager::showAllRooms()
{
	if (this->m_Vr.empty())
	{
		cout << "No Room" << endl;
	}
	else
	{
		for_each(this->m_Vr.begin(), this->m_Vr.end(), printRoom);
	}

	system("pause");
	system("cls");
}

void Manager::clearAllRecords()
{
	int input = -1;

	while (1)
	{
		cout << "Emptying all orders: " << endl;
		cout << "1.Continue" << endl;
		cout << "0.Cancel" << endl;
		cout << "Please Select: ";
		cin >> input;

		if (input == 1)
		{
			ofstream ofs;
			ofs.open(ORDER_FILE, ios::trunc);
			ofs.close();
			cout << "Emptied" << endl;
			break;
		}
		else if (input == 0)
		{
			cout << "Canceled" << endl;
			break;
		}

		cout << "Try Again" << endl;
		system("pause");
	}

	system("pause");
	system("cls");
	return;
}

