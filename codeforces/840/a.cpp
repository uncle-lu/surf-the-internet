#include<iostream>
#include<cstring>
using namespace std;

int line[530];
int tong[15];

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		memset(tong, 0, sizeof(tong));
		int n;
		cin >> n;
		for(int i=1; i<=n; ++i)
			cin >> line[i];
		for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=10 && line[i]; ++j, line[i]>>=1)
				if(line[i]&1)
					tong[j]++;
		}

		int ans = 0, temp = 1;
		for(int i=1; i<=10; ++i)
		{
			if(tong[i] != n && tong[i] != 0)
				ans += temp;
			temp <<= 1;
		}
		cout << ans << endl;
	}
	return 0;
}
