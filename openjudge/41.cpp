#include<cstdio>//uncle-lu
#include<algorithm>

int line[1000010];

int main()
{
	int x, k;
	scanf("%d,%d", &k, &x);
	if(k > x)
	{
		printf("NO");
		return 0;
	}

	line[1] = k;
	int cnt = 1, i = 1;
	bool flag ;
	while( true )
	{
		if(line[i] > 1000100)
		{
			flag = false;
			break;
		}
		if(line[i] == x)
		{
			flag = true;
			break;
		}
		line[++cnt] = line[i] * 2 + 1;
		line[++cnt] = line[i] * 3 + 1;
		i++;
	}
	if(flag)
		printf("YES");
	else
		printf("NO");
	
	return 0;
}
