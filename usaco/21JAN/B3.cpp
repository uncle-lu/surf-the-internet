#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>line(n), h(n);
	for (int i = 0; i < n; ++i) 
		cin >> line[i];
	for (int i = 0; i < n; ++i) 
		cin >> h[i];

	sort(line.begin(), line.end());

	long long ans = 1;
	for (int i = n-1; i >= 0; --i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j)
			if(h[j] >= line[i])
				cnt++;
		ans *= cnt - (n-1-i) ;
	}

	cout << ans;

	return 0;
}
