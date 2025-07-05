#include<cstdio>
#include<algorithm>

const int N = 1e5+10;
struct node {
	int x, y, val;
	bool operator<(const node a, const node b) {
		return a.val < b.val;
	}
};
node edge[N];
int F[N], line[N];
int n, m;

int find(int x) {
	return F[x] == x ? x : F[x] = find(F[x]);
}



int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &line[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].val);
	}
	sort(edge+1, edge+1+m);

	int l = 1, r = m, mid;
	while(l < r) {
		mid = (l + r) / 2;

	}

	printf("%d", edge[l].val);
	return 0;
}
