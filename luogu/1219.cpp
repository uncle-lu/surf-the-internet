#include<cstdio>
#include<cstring>

int line[20], n, cnt;
bool visit_1[30], visit_2[30], visit_3[30];

void DFS(int x)
{
	if(x > n)
	{
		cnt++;
		if(cnt <= 3)
		{
			for(int i=1; i<=n; ++i)
				printf("%d ", line[i]);
			printf("\n");
		}
		return ;
	}

	for(int i=1; i<=n; ++i)
	{
		if(visit_1[i] || visit_2[i+x] || visit_3[x-i+n])continue;
		visit_1[i] = visit_2[i+x] = visit_3[x-i+n] = true;
		line[x] = i;
		DFS(x+1);
		visit_1[i] = visit_2[i+x] = visit_3[x-i+n] = false;
	}

	return ;
}

int main()
{
	scanf("%d", &n);
	DFS(1);
	printf("%d", cnt);
	return 0;
}
