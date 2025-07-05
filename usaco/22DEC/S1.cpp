#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int N = 2*1e5 + 10;
struct node{
	long long int v;
	int next;
};
struct ansNode{
	int x, y;
	long long int v;
};
vector<ansNode>ans;
node edge[2*N];
int n, head[N], cnt;
long long int h[N], sum[N], num[N], aim;

void add_edge(int x, int y){
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
	return ;
}

void build(int x, int f){
	num[x] = 1; sum[x] = h[x];
	for(int i=head[x]; ~i; i=edge[i].next){
		int v = edge[i].v;
		if(v == f)continue;
		build(v, x);
		num[x] += num[v];
		sum[x] += sum[v];
	}
	return ;
}

void DFS(int x, int f){
	for(int i=head[x]; ~i; i=edge[i].next){
		int v = edge[i].v;
		if(v == f)continue;
		if(sum[v] >= aim * num[v]) {
			DFS(v, x);
			if(h[v] > aim){
				ans.push_back((ansNode){v, x, h[v] - aim});
				h[x] += h[v] - aim;
				sum[v] -= h[v] - aim;
				h[v] = aim;
			}
		}
	}

	for(int i=head[x]; ~i; i=edge[i].next){
		int v = edge[i].v;
		if(v == f)continue;
		if(sum[v] < aim * num[v]) {
			ans.push_back((ansNode){ x, v, aim*num[v] - sum[v] });
			h[x] -= aim*num[v] - sum[v];
			h[v] += aim*num[v] - sum[v];
			sum[v] = aim*num[v];
			DFS(v, x);
		}
	}

	return ;
}

int main()
{
	memset(head, -1, sizeof(head));
	int x, y;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &h[i]);
		aim += h[i];
	}
	for (int i = 1; i <= n-1; ++i) {
		scanf("%d %d", &x, &y);
		add_edge(x, y);
		add_edge(y, x);
	}
	build(1, 0);
	aim /= n;
	DFS(1, 0);
	
	printf("%d\n",(int)ans.size());
	for(auto i : ans){
		printf("%d %d %lld\n", i.x, i.y, i.v);
	}
	return 0;
}
