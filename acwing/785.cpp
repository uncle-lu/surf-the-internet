#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 100010;

int n, line[N];

void quick_sort(int l, int r)
{
	if(l >= r)
		return ;

	int x = line[(l+r)/2], i = l - 1, j = r + 1;
	while(i < j)
	{
		do { i++; } while(line[i] < x);
		do { j--; } while(line[j] > x);
		if(i < j) swap(line[i], line[j]);
	}

	quick_sort(l, j);
	quick_sort(j+1, r);

	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &line[i]);

	quick_sort(0, n-1);

	for (int i = 0; i < n; ++i) 
		printf("%d ", line[i]);

	return 0;
}
