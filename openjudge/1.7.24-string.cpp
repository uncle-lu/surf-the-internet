#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	int flag = 0;
	while(cin >> str)
	{
		if(flag == 0)
		{
			cout << str.length();
			flag = 1;
		}
		else
			cout << ',' << str.length();
	}

	return 0;
}
