#include<cstdio>
#include<cstring>

const int N = 2510;
struct node {
	int v, next;
};
node edge[2*N];
int head[N], cnt, n;
int line[N], temp[N];

void add_edge(int x, int y) {
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
	return ;
}

void DFS(int x, int fa = -1) {
	for (int i=head[x]; ~i; i=edge[i].next) {
		int v = edge[i].v;
		if(v == fa)continue;
		DFS(v, x);
		temp[x] = (temp[x] + 12 - temp[v]) % 12;
	}
	return ;
}

int main() {
	memset(head, -1, sizeof(head));
	int x, y;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &line[i]);
	for (int i = 1; i <= n-1; ++i) {
		scanf("%d %d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		memcpy(temp, line, sizeof(line));
		DFS(i);
		if(temp[i] == 0 || temp[i] == 1){
			ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
