#include<iostream>
using namespace std;

const int N = 1501;
char maps[N][N];
int cnt[N][N], lline[N], rline[N];
long long int ans;
int n;

void make_cnt()
{
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) {
			if(maps[i][j] == 'D')
				cnt[i+1][j] += cnt[i][j] + 1;
			else
				cnt[i][j+1] += cnt[i][j] + 1;
			cnt[i][j] ++;
		}
	for (int i = 0; i < n; ++i) {
		ans += cnt[i][n] * rline[i];
		ans += cnt[n][i] * lline[i];
	}
	return ;
}

void after(int x, int y, int f)
{
	int temp = cnt[x][y];
	while(x != n && y != n)
	{
		if(maps[x][y] == 'D')
			x++;
		else
			y++;
		cnt[x][y] += f*temp;
	}
	if(x == n)
		ans = ans + f * temp * lline[y];
	else
		ans = ans + f * temp * rline[x];

	return ;
}

int main()
{
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> maps[i] >> rline[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> lline[i];
	}
	make_cnt();

	cout << ans << '\n';

	int Q;
	cin >> Q;
	while(Q--)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		after(x, y, -1);
		if(maps[x][y] == 'D')
			maps[x][y] = 'R';
		else
			maps[x][y] = 'D';
		after(x, y, 1);
		cout << ans << '\n';
	}

	return 0;
}
