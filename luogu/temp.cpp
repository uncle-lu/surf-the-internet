#include <cstdio>
#include <algorithm>

const int M = 1e5 + 10, N = 1e5 + 10;
struct node {
    int u, v, val; // (u, v) 存在一条权值为 val 的无向边
	friend bool operator<(const node a, const node b) {
		return a.val < b.val;
	}
} edge[M];
int father[N];

int find_father(int x) {
	return father[x] == x ? x : father[x] = find_father(father[x]);
}

int main() {
	int n, m;
	for(int i = 1; i <= n; i++) // 并查集初始化	
		father[i] = i;
	std::sort(edge + 1, edge + 1 + m);
	int tot = 0; // 记录选择最小生成树的边数
	int sum = 0; // 记录最小生成树的权值和
	for(int i = 1; i <= m; i++) { // 枚举每一条边
		int x = find_father(edge[i].u), y = find_father(edge[i].v);
		if(x != y) {
			sum += edge[i].val;
			father[y] = x; // 合并(u,v)所在的集合
			tot++; // 选择边的数量 + 1
		}
		if(tot == n - 1) // 选择的边数量，刚好到树的数量 => 不会再选其他任何边了
			break;
	}
	printf("%d", sum);
	return 0;
}