#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>line(n);
	for(int& i : line)
		cin >> i;
	sort(line.begin(), line.end());

	long long int ans=0;
	int cnt=0;
	for (int i = 0; i < n; ++i) {
		if(1LL * (n-i) * line[i] > ans)
		{
			ans = 1LL*(n-i)*line[i];
			cnt = line[i];
		}
	}

	cout << ans << " " << cnt;
	return 0;
}
