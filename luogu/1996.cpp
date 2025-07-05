#include<cstdio>

struct node{
	int val, end;
};
node line[110];

void cut(int x)
{
	int e = line[x].end;
	line[f].end = e;
	return ;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		line[i].val = i;
		line[i].end = i+1;
	}
	line[n].end = 1;
	
	int now = 1, tot = n, cnt = 1;
	
	while( tot > 0 )
	{
		if(cnt == m)
		{
			printf("%d ", line[now].val);
			cut(now);
			cnt = 1;
			tot--;
		}
		else
		{
			cnt ++;
		}
		now = line[now].end;
	}
	
	return 0;
}
