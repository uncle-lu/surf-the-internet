#include<cstdio>

int main()
{
	int i=1, n, a, c=-1, s=0;
	scanf("%d", &n);
	while(i<=n){
		scanf("%d", &a);
		if(c>a)++s;
		else c=a;
		i++;
	}
	printf("%d", s);
	return 0;
}
