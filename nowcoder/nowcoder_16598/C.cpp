#include<cstdio>
#include<cmath>
#include<algorithm>

const int N=1e5+10;
struct node{
	int x,y;
};
node edge[N];
int ID = 1, cnt;
long long int k;

void add_edge(int x, int y)
{
	edge[++cnt].x = x;
	edge[cnt].y = y;
	return ;
}

void get_h(long long int &h1, long long int &h2, long long int x)
{
	/*
	for(long long int i=sqrt(x); i>=1; --i)
	{
		if(x%i==0)
		{
			h1 = x/i;
			h2 = i;
			return ;
		}
	}*/
	if(x%2==0)
	{
		h1 = std::max(x/2, 2LL);
		h2 = std::min(x/2, 2LL);
	}
	else
	{
		h1 = x; 
		h2 = 1;
	}
	return ;
}

void DFS(long long int x, int root)
{
	x-=1;
	if(x == 1)
		return ;

	long long int h1, h2;
	get_h(h1, h2, x);

	int h1_id = ++ID, h2_id;
	add_edge(root, h1_id);
	if(h2 != 1)
	{
		h2_id = ++ID;
		add_edge(root, h2_id);
	}

	DFS(h1, h1_id);
	if(h2 != 1)
		DFS(h2, h2_id);
	
	return ;
}

int main()
{
	scanf("%lld", &k);

	DFS(k, 1);

	printf("%d\n", ID);
	for(int i=1; i<=cnt; ++i)
	{
		printf("%d %d\n", edge[i].x, edge[i].y);
	}

	return 0;
}
