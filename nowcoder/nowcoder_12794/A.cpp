#include<cstdio>//uncle-lu
#include<algorithm>

int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		int temp, c = 1;
		scanf("%d", &temp);
		while(c<temp)
			c <<= 1;
		printf("Input value: %d\n%d\n\n", temp, c);
	}

	return 0;
}
