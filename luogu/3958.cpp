#include<cstdio>
#include<cstring>

long long int x[1010], y[1010], z[1010];
bool visit[1010];
bool flag;
int n;
long long int h, r;

long long int dis(int a, int b)
{
	return (x[a] - x[b])*(x[a] - x[b]) + (y[a] - y[b])*(y[a] - y[b]) + (z[a] - z[b])*(z[a] - z[b]);
}

void DFS(int xx)
{
	if(z[xx] + r >= h)
	{
		flag = true;
		return ;
	}

	for(int i=1; i<=n; ++i)
	{
		if(visit[i])continue;
		if(4LL*r*r >= dis(xx, i))
		{
			visit[i] = true;
			DFS(i);
			if(flag)return ;
		}
	}

	return ;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		memset(visit, 0, sizeof(visit));
		flag = false;
		scanf("%d %lld %lld", &n, &h, &r);
		for(int i=1; i<=n; ++i)
			scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);

		for(int i=1; i<=n; ++i)
		{
			if(z[i] <= r && !visit[i])
			{
				visit[i] = true;
				DFS(i);
				if(flag)break;
			}
		}

		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
