#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 1e4+10;
const int M = 1e5+10;
struct node{
	int v, next;
};
node edge1[M], edge2[M];
int line[N], head1[N], head2[N], cnt1, cnt2, num, top, scc;
int dfn[N], low[N], sta[N], color[N], val[N], d[N], in[N];
bool vis[N];
int n, m;

void add_edge1(int x, int y) {
	edge1[++cnt1].v = y;
	edge1[cnt1].next = head1[x];
	head1[x] = cnt1;
	return ;
}

void add_edge2(int x, int y) {
	edge2[++cnt2].v = y;
	edge2[cnt2].next = head2[x];
	head2[x] = cnt2;
	return ;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	sta[++top] = x; vis[x] = true;
	for (int i = head1[x]; ~i; i = edge1[i].next) {
		int v = edge1[i].v;
		if(!dfn[v]) {
			tarjan(v);
			low[x] = min(low[x], low[v]);
		}
		else if(vis[v])
			low[x] = min(low[x], dfn[v]);
	}
	if(dfn[x] == low[x]) {
		scc++;int temp;
		do {
			temp = sta[top--];
			vis[temp] = false;
			color[temp] = scc;
			val[scc] += line[temp];
		} while(temp != x);
	}
	return ;
}

int main() {
	memset(head1, -1, sizeof(head1));
	memset(head2, -1, sizeof(head2));
	int x, y;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", &line[i]);
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d", &x, &y);
		add_edge1(x, y);
	}
	for (int i = 1; i <= n; ++i)
		if(!dfn[i]) tarjan(i);

	for (int i = 1; i <= n; ++i) 
		for (int j = head1[i]; ~j; j = edge1[j].next ) {
			int v = edge1[j].v;
			if(color[i] == color[v])continue;
			add_edge2(color[i], color[v]);
			in[color[v]]++;
		}

	int ans = 0;
	queue<int>qu;
	for (int i = 1; i <= scc; ++i)
		if(!in[i])qu.push(i);

	while(!qu.empty()) {
		int now = qu.front();
		qu.pop();
		d[now] += val[now];
		ans = max(ans, d[now]);
		for (int i = head2[now]; ~i; i = edge2[i].next) {
			int v = edge2[i].v;
			d[v] = max(d[v], d[now]);
			in[v]--;
			if(!in[v])
				qu.push(v);
		}
	}

	printf("%d", ans);
	return 0;
}
