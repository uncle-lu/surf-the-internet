#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1e5+10;
struct node{
	int v, next, pos;
	bool is_first;
};
node edge[2*N];
int head[N], ans[N];
int n, m, ans_cnt, cnt=-1, _first, ig_edge;
bool vis[N], this_vis[N], vis_cow[N];

void add_edge(int x, int y, int pos, bool f) {
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	edge[cnt].pos = pos;
	edge[cnt].is_first = f;
	head[x] = cnt;
	return ;
}

void find_cycle(int x, int pre = -1) {
	for(int i=head[x]; ~i && (_first == -1); i = edge[i].next) {
		int v = edge[i].v;
		if(i == (pre^1) && pre != -1) continue;
		if(this_vis[v]) {
			if(edge[i].is_first) {
				_first = x;
				ig_edge = i;
			} else {
				_first = v;
				ig_edge = i^1;
			}
			return ;
		} else {
			this_vis[v] = true;
			find_cycle(v, i);
		}	
	}
	return ;
}

void DFS(int x) {
	vis[x] = true;
	for(int i=head[x]; ~i; i=edge[i].next) {
		int v = edge[i].v;
		if(vis[v] || i == ig_edge )continue;
		ans[++ans_cnt] = edge[i].pos;
		vis_cow[edge[i].pos] = true;
		DFS(v);
	}
	return ;
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		int f, s;
		scanf("%d %d", &f, &s);
		add_edge(f, s, i, true);
		add_edge(s, f, i, false);
	}
	for(int i=1; i<=m; i++) {
		if(vis[i]) continue;
		memset(this_vis, false, sizeof(this_vis));
		_first = -1; ig_edge = -1; this_vis[i] = true;
		find_cycle(i);
		if(_first == -1) {
			DFS(i);
		} else {
			ans[++ans_cnt] = edge[ig_edge].pos;
			vis_cow[edge[ig_edge].pos] = true;
			DFS(_first);
		}
	}

	int c = 0;
	for(int i=1; i<=n; i++)
		if(!vis_cow[i]) {
			c++;
			ans[++ans_cnt] = i;
		}
	printf("%d\n", c);
	for(int i=1; i<=n; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}
