#include<iostream>
using namespace std;

long long int DFS(long long int x, long long int y)
{
	if(x > y)
		return 1e12;
	if(2 * x > y)
		return y-x;
	if(y & 1)
		return DFS(x, y-1) + 1;
	return DFS(x, y/2) + 1;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long int a, b;
		cin >> a >> b;
		
		long long int cnt = 0, ans = 1e12;
		do
		{
			long long int res = DFS(a, b);
			ans = min(ans, cnt + res);
			if(a & 1)
				a++;
			else
				a>>=1;
			cnt++;
		} while(a > 1);

		cout << ans << endl;
	}
	
	return 0;
}
