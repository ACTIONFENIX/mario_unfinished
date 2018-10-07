#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int a;
	cin >> a;
	if (a = 1)
	{
		cout << "enter number 1 , 2 or 3" << endl;
		int b;
		cin >> b;
		if (b = 1)
		{
			cout << "адын" << endl;
		}
		if (b = 2)
		{
			cout << "два" << endl;
		}
		if (b = 3)
		{
			cout << "тры" << endl;
		}
	}
	if (a = 2)
	{
		cout << "2= 1" << endl;
		cout << "enter number 1 , 2 or 3" << endl;
		int c;
		cin >> c;
		if (c = 1)
		{
			cout << "ку" << endl;
		}
		if (c = 2)
		{
			cout << " не ку " << endl;
		}
		if (c = 3)
		{
			cout << "куку" << endl;
		}
	}
	if (a = 3)
	{
		cout << " 3 = 2" << endl;
		cout << "enter number 1 , 2 or 3" << endl;
		int d;
		cin >> d;
		if (d = 1)
		{
			cout << "восемь" << endl;
		}
		if (d = 2)
		{
			cout << "семь" << endl;
		}
		if (d = 3)
		{
			cout << "шесть" << endl;
		}
	}
}