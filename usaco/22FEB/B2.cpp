#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, temp, ans = 0;
	cin >> n;
	vector<int>tong(n+1), line(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> temp;
		tong[temp] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> temp;
		line[i] = tong[temp];
	}
	int mi = 1e6;
	for (int i = n; i >= 1; --i) {
		if(line[i] < mi)
			mi = line[i];
		else
			ans++;
	}
	cout << ans;
	return 0;
}
