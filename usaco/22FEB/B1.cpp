#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n, sum = 0;
		cin >> n;
		vector<int>line(n);
		for (int i = 0; i < n; ++i) {
			cin >> line[i];
			sum += line[i];
		}
		for (int len = n; len >= 1; --len) {
			if(sum % len == 0)
			{
				int num = sum / len, cnt = 0;
				bool flag = true;
				for (int i = 0; i < n; ++i) {
					cnt += line[i];
					if(cnt == num)
						cnt = 0;
					if(cnt > num)
					{
						flag = false;
						break;
					}
				}
				if(flag)
				{
					cout << n - len << endl;
					break;
				}
			}
		}
	}
	return 0;
}
