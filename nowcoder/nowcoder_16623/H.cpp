#include<cstdio>//uncle-lu
#include<cstring>
#include<vector>
#include<algorithm>

const int N = 2e5+10;
struct node{
	int v,next;
};
node edge[N];
int head[N];
long long int line[N], tong[N];
int n, k, cnt, tot;

void init()
{
	memset(head, -1, sizeof(head));
	cnt = 0;
	return ;
}

void add_edge(int x, int y)
{
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
	return ;
}

void DFS(int x, int fa, long long int mx)
{
	for(int i=head[x];~i;i=edge[i].next)
	{
		int v = edge[i].v;
		if(v == fa)continue;
		DFS(v, x, mx);
		tong[x] += tong[v];
	}

	if(tong[x] > mx)
	{
		std::vector<long long int>l;
		for(int i=head[x]; ~i; i=edge[i].next)
		{
			int v = edge[i].v;
			if(v == fa)continue;
			l.push_back(tong[v]);
		}
		std::sort(l.begin(), l.end());
		while(tong[x] > mx)
		{
			tot++;
			tong[x] -= l.back();
			l.pop_back();
		}
	}
	return ;
}

bool check(long long int mx)
{
	tot = 0;
	for(int i=1; i<=n; ++i)
	{
		tong[i] = line[i];
		if(tong[i] > mx)
			return false;
	}
	DFS(1, 0, mx);
	return tot <= k-1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		init();
		scanf("%d %d", &n, &k);
		int x, y;
		long long int sum = 0;
		for(int i=1; i<=n-1; ++i)
		{
			scanf("%d %d", &x, &y);
			add_edge(x, y);
			add_edge(y, x);
		}
		for(int i=1; i<=n; ++i)
		{
			scanf("%lld", &line[i]);
			sum += line[i];
		}

		long long int l = 1, r = sum, mid;
		while(l < r)
		{
			mid = (l+r) >> 1;
			if(check(mid))
				r = mid;
			else
				l = mid+1;
		}
		printf("Case #%d: %lld\n", t, r);
	}
	
	return 0;
}
