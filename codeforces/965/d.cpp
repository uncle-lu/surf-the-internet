#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int w, l, temp;
	cin >> w >> l;
	vector<int>sum(w);
	for (int i = 1; i < w; ++i)
	{
		cin >> temp;
		sum[i] = sum[i-1] + temp; 
	}

	int ans = 0x7f7f7f7f;
	for (int i = 0; i < w-l; ++i) {
		ans = min(ans, sum[i+l] - sum[i]);
	}

	cout << ans;
	return 0;
}
