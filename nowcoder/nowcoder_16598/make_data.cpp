#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>

int main()
{
	srand(time(0));

	int n = 10;
	int H = rand()%100+1, S = rand()%100;
	printf("%d %d %d\n", n, H, S);
	for(int i=1; i<=n; ++i)
	{
		printf("%d %d %d\n", rand()%H, rand()%S, rand());
	}
	return 0;
}
