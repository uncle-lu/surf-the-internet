#include<iostream>
#include<string>
using namespace std;

int main()
{
	string front, behind;
	cin >> front >> behind;
	int len = front.length(), ans = 1;
	for (int i = 0; i < len-1; ++i)
		for (int j = 0; j < len; ++j) 
			if(behind[j] == front[i] && behind[j-1] == front[i+1])
				ans *= 2;

	cout << ans;
	return 0;
}
