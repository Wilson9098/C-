#define _CRT_SECURE_NO_WARNINGS 1
#include "Order.h"
#include "Room Order System.hpp"

void Separate(string s,map<string,string>& m)
{
	int p = s.find(":");
	if (p == -1)
	{
		cout << "No Data" << endl;
		return;
	}
	string first = s.substr(0, p);
	string second = s.substr(p + 1, s.size() - p);

	m.insert(make_pair(first, second));
}

Order::Order()
{
	this->m_OrderData.clear();

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Can't Load Data" << endl;
		ifs.close();
		return;
	}
	string date;
	string time;
	string name;
	string id;
	string room;
	string status;
	int i = 1;
	
	while (ifs >> date && ifs >> time && ifs >> name && ifs >> id && ifs >> room && ifs >> status)
	{
		map<string, string> m;

		Separate(date, m);
		Separate(time, m);
		Separate(name, m);
		Separate(id, m);
		Separate(room, m);
		Separate(status, m);

		this->m_OrderData.insert(make_pair(i++, m));
	}

	//test
	//for (map<int, map<string, string>>::iterator itf = this->m_OrderData.begin(); itf != this->m_OrderData.end(); itf++)
	//{
	//	cout << itf->first << ": ";
	//	for (map<string, string>::iterator its = itf->second.begin(); its != itf->second.end(); its++)
	//	{
	//		cout << its->first << ":" << its->second << " ";
	//	}
	//	cout << endl;
	//}

	ifs.close();
}