#include<cstdio>//uncle-lu
#include<cstring>
#include<algorithm>

const int N = 100010;

struct node{
	int v, next, val;
};
node edge[N*2];
int head[N];
int F[N], G[N];
int A[N], B[N], A_sit[N], B_sit[N];
bool Tong[N];
int n, k;

void add_edge(int x, int y, int val)
{
	edge[++cnt].val = val;
	edge[cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
	
	return ;
}

bool DFS_1(int x, int father)
{
	bool flag = false;
	for(int i=head[x]; ~i; i=edge[i].next)
	{
		if(edge[i].v == father)
			continue;

		if(DFS_1(edge[i].v, x))
		{
			flag = true;
			F[x] += F[edge[i].v] + edge[i].val * 2;
			if(A[x] < A[edge[i].v] + edge[i].val)
			{
				A[x] = A[edge[i].v] + edge[i].val;
				A_sit[x] = edge[i].v;
			}
		}
	}

	Tong[x] |= flag;

	return Tong[x];
}

bool DFS_2(int x, int father)
{
	if(Tong[x])
	{
		G[x] = G[father];
		if(B_sit[father] != x)
		{

		}
		else
			B[x] = 
	}

	for(int i=head[x]; ~i; i=edge[i].next)
	{
		if(edge[i].v == father)
			continue;
		DFS_2(edge[i].v, x);
	}


	return Tong[x];
}

int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d %d", &n, &k);
	int x, y, val;
	for(int i=1; i<=n-1; ++i)
	{
		scanf("%d %d %d", &x, &y, &val);
		add_edge(x, y, val);
		add_edge(y, x, val);
	}
	for(int i=1; i<=k; ++i)
	{
		scanf("%d", &x);
		Tong[x] = true;
	}

	DFS_1(1, 0);
	B_sit[1] = A_sit[1];
	DFS_2(1, 0);

	return 0;
}
