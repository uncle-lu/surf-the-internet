#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge{
	int x, y, val;
	friend bool operator<(const edge a, const edge b)
	{
		return a.val < b.val;
	}
};

const int N = 510;
int maps[N][N];
int Fa[N];

int find(int x)
{
	return Fa[x] == x ? x : Fa[x] = find(Fa[x]);
}

int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= b; ++i)
		Fa[i] = i;
	for (int i = 1; i <= b; ++i) 
		for (int j = 1; j <= b; ++j) 
			cin >> maps[i][j];

	vector<edge>line;
	for (int i = 1; i <= b; ++i) 
		for (int j = i+1; j <= b; ++j) 
			if(maps[i][j])
				line.push_back((edge){i, j, maps[i][j]});

	for (int i = 1; i <= b; ++i)
		line.push_back((edge){0, i, a});

	sort(line.begin(), line.end());

	int cnt = 0, ans = 0;
	for(auto l : line)
	{
		int xx = find(l.x), yy = find(l.y);
		if(xx != yy)
		{
			Fa[yy]=xx;
			cnt++;
			ans += l.val;
		}
	}

	cout << ans;

	return 0;
}
