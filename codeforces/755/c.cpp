#include<cstdio>
#include<algorithm>

int n;
int a[110], b[110];

int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i)
			scanf("%d", &a[i]);
		for(int i=1; i<=n; ++i)
			scanf("%d", &b[i]);
		std::sort(a+1, a+1+n);
		std::sort(b+1, b+1+n);
		bool flag = false;
		for(int i=1; i<=n; ++i)
		{
			if(a[i] == b[i] || a[i] + 1 == b[i])
				continue;
			flag = true;
			break;
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
