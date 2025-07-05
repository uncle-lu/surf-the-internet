#include<cstdio>//uncle-lu
#include<cmath>
#include<algorithm>

bool check(int x)
{
	int temp = x, ans = 0;
	while(temp)
	{
		ans = ans*10 + temp%10;
		temp /= 10;
	}

	if(ans == x)
		return true;
	else
		return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		int temp, tips;
		scanf("%d", &temp);
		printf("Input cost: %d\n", temp);
		tips = (int)ceil(temp*0.2);
		while(!check(temp+tips))
			tips++;
		printf("%d %d\n\n",tips, tips+temp);
	}

	return 0;
}
