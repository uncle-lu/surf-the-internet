#include<cstdio>//uncle-lu
#include<algorithm>

int n;

int main()
{
	scanf("%d", &n);
	int l=1, r=n, x;
	while(l!=r)
	{
		printf("? %d %d\n", l, r);
		fflush(stdout);

		scanf("%d", &x);

		if(x == l) { l++; continue; }
		if(x == r) { r--; continue; }

		printf("? %d %d\n", l, x);
		fflush(stdout);

		int temp;
		scanf("%d", &temp);
		if(temp == x)
			r = x-1;
		else
			l = x+1;
	}
	printf("! %d\n", l);
	fflush(stdout);
	return 0;
}
