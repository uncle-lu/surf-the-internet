#include<iostream>
#include<string>
using namespace std;

int tong[30];

int main()
{
	string str;
	cin >> str;
	int len = str.length();
	for(int i=0; i<len; i++)
		tong[str[i] - 'a']++;
	int mx = 0;
	char ans;
	for(int i=0; i<26; i++)
	{
		if(tong[i] > mx)
		{
			mx = tong[i];
			ans = i + 'a';
		}
	}
	cout << ans << ' ' << mx;
	return 0;
}
