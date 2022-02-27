#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void Prime(int n)
{
	int i = 0;
	bool* prime = new bool[n + 1];

	for (i = 2; i < n; i++)
	{
		prime[i] = true;
	}

	for (i = 2; i <= n; i++)
	{
		if (prime[i])
		{
			cout << i << " ";
			for (int j = 2 * i; j <= n; j += i)
			{
				prime[j] = false;
			}
		}
	}

	delete[] prime;
	prime = NULL;
	cout << endl;
}

int main()
{
	Prime(100);

	return 0;
}