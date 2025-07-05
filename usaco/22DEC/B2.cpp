#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string line, ans;
		int n, k, cnt = 0;
		cin >> n >> k;
		cin >> line;
		for (int i = 0; i < n; ++i)
			ans += '.';

		for (int i = 0; i < n; ++i) {
			if(line[i] == 'G')
			{
				if(i + k < n)
					ans[i+k] = 'G';
				else
					ans[n-1] = 'G';
				i = i + 2*k;
			}
		}

		for (int i = 0; i < n; ++i) {
			if(line[i] == 'H')
			{
				if(i + k < n-1)
					ans[i+k] = 'H';
				else
				{
					for(int j = n-1; j >= 0; j--)
						if(ans[j] == '.')
						{
							ans[j] = 'H';
							break;
						}
				}
				i = i + 2*k;
			}
			
		}

		for(auto i : ans)
			if(i != '.')
				cnt++;

		cout << cnt << '\n' << ans << '\n';
	}

	return 0;
}
