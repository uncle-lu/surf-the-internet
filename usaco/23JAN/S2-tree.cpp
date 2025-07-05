#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1501;
const int AN = N*N + 2*N + 10;
struct node{
	int v, next;
};
node edge[AN+N+10];
int head[AN], cnt, n, rline[N], dline[N], d[N];
long long int sum;
char maps[N][N];

void add_edge(int x, int y)
{
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
	return ;
}

void del(int x, int y)
{
	int *before = &head[x];
	for(int i = head[x]; ~i; i=edge[i].next)
	{
		if(edge[i].v == y)
		{
			*before = edge[i].next;
			break;
		}
		before = &edge[i].next;
	}

	return ;
}
/*
void debug_show(int x)
{
	for(int i=head[x]; ~i; i=edge[i].next)
		printf("%d->", edge[i].v);
	printf("\n");
	return ;
}

void debug()
{
	for(int i=1; i<=10; i++)
		add_edge(1, i);
	debug_show(1);
	for(int i=10; i>=3; i--)
	{
		del(1, i);
		debug_show(1);
	}
	return ;
}
*/
int trans_num(int x, int y)
{
	if(x == n)
		return y;
	if(y == n)
		return n + x;
	return 2*n + x*n + y;
}

void DFS(int x, int val)
{
	sum = sum - d[x] + val;
	d[x] = val;
	for (int i = head[x]; ~i; i=edge[i].next)
		DFS(edge[i].v, val);
	return ;
}

int main()
{
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		scanf("%s %d\n", maps[i], &rline[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &dline[i]);

	for (int i = n-1; i >= 0; i--)
		for (int j = n-1; j >= 0; j--)
		{
			int fa, x = trans_num(i, j);
			if(maps[i][j] == 'D')
				fa = trans_num(i+1, j);
			else
				fa = trans_num(i, j+1);

			add_edge(fa, x);
		}

	for (int i = 0; i < n*2; ++i) 
		if( i < n )
		{
			DFS(i, dline[i]);
			sum -= dline[i];
		}
		else
		{
			DFS(i, rline[i-n]);
			sum -= rline[i-n];
		}

	printf("%lld\n", sum);
	
	int q, x, y;
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %d", &x, &y);
		x--; y--;
		int fa, now;
		if(maps[x][y] == 'D')
		{
			maps[x][y] = 'R';
			fa = trans_num(x, y+1);
		}
		else
		{
			maps[x][y] = 'D';
			fa = trans_num(x+1, y);
		}
		now = trans_num(x, y);
		del(fa, now);
		add_edge(fa, now);
		DFS(now, d[fa]);

		printf("%lld\n", sum);
	}

	return 0;
}
