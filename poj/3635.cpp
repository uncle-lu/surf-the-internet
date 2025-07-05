#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct node {
	int x, f, d;
	friend bool operator<(const node a, const node b) {
		return a.d > b.d;
	}
};
const int N = 1010;
int n, m, p[N], d[N][110];
bool vis[N][110];
vector<pair<int, int> >E[N];

void func() {
	int c, s, t;
	scanf("%d %d %d", &c, &s, &t);
	memset(d, 0x7f, sizeof(d));
	memset(vis, false, sizeof(vis));
	d[s][0] = 0;
	priority_queue<node>qu;
	qu.push((node){s, 0, 0});
	while(!qu.empty()) {
		node now = qu.top(); qu.pop();

		if(now.x == t) {
			printf("%d\n", d[now.x][now.f]);
			return ;
		}

		if(vis[now.x][now.f]) continue;
		vis[now.x][now.f] = true;

		if(now.f < c && d[now.x][now.f+1] > d[now.x][now.f] + p[now.x]) {
			d[now.x][now.f+1] = d[now.x][now.f] + p[now.x];
			qu.push((node){now.x, now.f+1, d[now.x][now.f+1]});
		}

		for(int i = 0; i < (int)E[now.x].size(); i++)
		{
			pair<int, int> edge = E[now.x][i];
			if(edge.second <= now.f && d[edge.first][now.f - edge.second] > d[now.x][now.f]) {
				d[edge.first][now.f - edge.second] = d[now.x][now.f];
				qu.push((node){ edge.first, now.f - edge.second, d[edge.first][now.f - edge.second] });
			}
		}
	}
	printf("impossible\n");
	return ;
}

int main() {
	int x, y, v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i]);
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &x, &y, &v);
		E[x].push_back(make_pair(y, v));
		E[y].push_back(make_pair(x, v));
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		func();
	}
	return 0;
}
