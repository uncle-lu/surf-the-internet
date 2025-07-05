#include<cstdio>
#include<algorithm>

int line[100010];
int n;

void debug()
{
	for(int i=1; i<=n; ++i)
		printf("%d ", line[i]);
	printf("\n");
	return ;
}

void qsort(int x, int y)
{
	if(x >= y)
		return ;
	int mid_val, low, high;
	mid_val = line[(x+y)/2];
	low = x;
	high = y;
	while(low < high)
	{
		while(low < high && line[low] < mid_val) low ++;
		while(low < high && line[high] > mid_val) high --;
		std::swap(line[high], line[low]);
	}

	qsort(x, low-1);
	qsort(low+1, y);

	return ;
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		scanf("%d", &line[i]);

	qsort(1, n);

	for(int i=1; i<=n; ++i)
		printf("%d ", line[i]);
}
