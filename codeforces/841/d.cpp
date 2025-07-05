#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int n, m;

bool check(int x, vector<vector<int> >maps)
{
	vector<vector<int> >sum(n+10, vector<int>(m+10));
	int temp;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if(maps[i][j] < x)
				temp = 0;
			else
				temp = 1;
			sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + temp;
		}
	}

	for (int i = x; i <= n; ++i) {
		for (int j = x; j <= m; ++j) {
			temp = sum[i][j] - sum[i-x][j] - sum[i][j-x] + sum[i-x][j-x];
			if(temp == x * x)
				return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		vector<vector<int> >maps(n, vector<int>(m));
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j) 
				cin >> maps[i][j];

		int l = 0, r = min(n, m), mid;
		while(l < r)
		{
			mid = (l + r + 1) / 2;
			if(check(mid, maps))
				l = mid;
			else
				r = mid-1;
		}
		cout << l << endl;
	}
	return 0;
}
