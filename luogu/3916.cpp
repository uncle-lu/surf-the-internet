#include<iostream>
#include<cstring>
using namespace std;

const int N=1e5+10;
struct node{
	int v, next;
};
node edge[N];
int head[N], cnt, A[N], sit;

void add_edge(int x, int y)
{
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
	return ;
}

void DFS(int x)
{
	if(A[x])return ;
	A[x] = sit;
	for (int i = head[x]; ~i; i=edge[i].next)
		DFS(edge[i].v);
	return ;
}

int main()
{
	memset(head, -1, sizeof(head));
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		add_edge(y, x);
	}

	for (int i = n; i >= 1; --i) {
		sit = i;
		DFS(i);
	}

	for (int i = 1; i <= n; ++i) {
		cout << A[i] << ' ';
	}

	return 0;
}
