#include<cstdio>//uncle-lu
#include<algorithm>

int check(int x, int y)
{
	int temp = x/3 * y;
	if(x % 3 == 1){
		temp += y / 3 + (y%3 ? 1 : 0);
	}
	if(x % 3 == 2){
		temp += (y / 3) * 2 + y%3;
	}
	return temp;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; ++i)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int mi = std::min(check(n, m), check(m, n));
		printf("%d\n", mi);
	}
	return 0;
}
