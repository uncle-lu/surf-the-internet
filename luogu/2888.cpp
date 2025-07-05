#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 310;
int dis[N][N];

int main()
{
	memset(dis, 0x7f7f7f7f, sizeof(dis));
	int n, m, t, x, y, val;
	cin >> n >> m >> t;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y >> val;
		dis[x][y] = val;
	}

	for (int k = 1; k <= n; ++k)
		for (x = 1; x <= n; ++x)
			for (y = 1; y <= n; ++y)
				dis[x][y] = min( max( dis[x][k] , dis[k][y] ), dis[x][y]);

	while(t--)
	{
		cin >> x >> y;
		if(dis[x][y] != 0x7f7f7f7f)
			cout << dis[x][y] << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}
