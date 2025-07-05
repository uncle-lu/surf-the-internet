#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge{
	int x, y, val;
	friend bool operator<(const edge a, const edge b) {
		return a.val > b.val;
	}
};

const int N = 100010;
int Fa[N];

int find(int x)
{
	return Fa[x] == x ? x : Fa[x] = find(Fa[x]);
}

int main()
{
	int n, m, k, u, v, w;
	cin >> n >> m >> k;
	vector<edge>line;
	for (int i = 1; i <= n; ++i)
		Fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		line.push_back((edge){u, v, w});
	}
	sort(line.begin(), line.end());

	int cnt = 0, ans = 0;
	for(auto l : line)
	{
		int xx = find(l.x) , yy = find(l.y);
		if(xx != yy)
		{
			Fa[yy] = xx;
			ans += l.val;
			cnt++;
			if(cnt == k)
				break;
		}
	}

	cout << ans;

	return 0;
}
