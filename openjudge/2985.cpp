#include<cstdio>

int F[2000];
int line[21];
int n, t;

int main()
{
	scanf("%d %d", &n, &t);
	for(int i=1; i<=n; ++i)
		scanf("%d", &line[i]);

	int top = 0;
	F[0] = 1;
	for(int i=1; i<=n; ++i)
	{
		for(int j=top; j>=0; j--)
		{
			F[j+line[i]] += F[j];
			if(F[j+line[i]]>0 && j+line[i]>top)
				top = j+line[i];
		}
	}
	printf("%d", F[t]);
	return 0;
}
