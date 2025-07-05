#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int cnt = 0, len = str.length();
	for(int i=0; i<len; i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
			cnt++;
	}

	cout << cnt ;
}
