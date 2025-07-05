#include<cstdio>
#include<cstring>

const int N = 1e5+10;
struct node{
	int v, next;
};
node edge[2 * N];
int head[N], cnt, ans;

void add_edge(int x, int y) {
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
	return ;
}

void DFS(int x, int fa) {
	int son = 0, t = 1;
	for(int i=head[x]; ~i; i=edge[i].next) {
		if(edge[i].v == fa)continue;
		DFS(edge[i].v, x);
		son++;
	}
	while(son >= t) {
		ans++;
		t <<= 1;
	}
	return ;
}

int main() {
	memset(head, -1, sizeof(head));
	int n, x, y;
	scanf("%d", &n);
	for (int i = 1; i <= n-1; ++i) {
		scanf("%d %d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
	}
	ans += n-1;
	DFS(1, 0);
	printf("%d", ans);
	return 0;
}
