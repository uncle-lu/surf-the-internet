#include<iostream>
using namespace std;

int main()
{
	int n, temp, j = 0, o = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		if(temp%2)
			j++;
		else
			o++;
	}
	int ans;
	if(j < o)
	{
		ans = j*2;
		if(o-j > 0)ans++;
	}
	else
	{
		ans = o*2;
		j -= o;
		ans += j/3*2;
		if(j%3==1)ans--;
		if(j%3==2)ans++;
	}
	cout << ans;
	return 0;
}
