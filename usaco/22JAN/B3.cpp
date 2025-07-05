#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		vector<long long int>line(n);
		for (int i = 0; i < n; ++i)
			cin >> line[i];

		if(n == 1)
		{
			cout << 0 << endl;
			continue;
		}

		if((n == 2 && line[0] != line[1]) || line[0] > line[1] || line[n-1] > line[n-2])
		{
			cout << -1 << endl;
			continue;
		}

		long long int cnt = 0;
		for (int i = 1; i < n-1; ++i) {
			if(line[i] > line[i-1]) {
				long long int def = line[i] - line[i-1];
				cnt += 2 * def;
				line[i+1] -= def;
				line[i] -= def;
			}
		}

		for (int i = n-2; i > 0; --i) {
			if(line[i] > line[i+1]) {
				long long int def = line[i] - line[i+1];
				cnt += 2 * def;
				line[i-1] -= def;
				line[i] -= def;
			}
		}

		if(line[0] < 0 || line[n-1] < 0)
			cnt = -1;

		cout << cnt << endl;
	}

	return 0;
}
