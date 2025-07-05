#include<iostream>
#include<vector>
using namespace std;

const int N = 110;
int a[N];
vector<int>p[N];

bool DFS(int x)
{
	if(p[x].empty())
	{
		if(a[x])
		{
			a[x]--;
			return true;
		}
		else
			return false;
	}

	for(int i : p[x])
	{
		if(a[i]>0)
			a[i]--;
		else
		{
			if(!DFS(i))
				return false;
		}
	}

	return true;
}

int main()
{
	int n, k, x, cnt, temp, ans; 
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ans = a[n];
	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> x >> cnt ;
		for (int j = 0; j < cnt; ++j) {
			cin >> temp;
			p[x].push_back(temp);
		}
	}

	while(DFS(n))
		ans++;

	cout << ans;
	return 0;
}
