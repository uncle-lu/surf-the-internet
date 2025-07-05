#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
int n, k, ans;
int line[N];

void quick_sort(int l, int r)
{
	if(l == r) {
		ans = line[l];
		return ;
	}

	int x = line[(l+r)/2], i = l-1, j = r+1;
	while(i < j)
	{
		do i++; while(line[i] < x);
		do j--; while(line[j] > x);
		if(i < j)
			swap(line[i], line[j]);
	}
	if(j - l + 1>= k)
		quick_sort(l, j);
	else
	{
		k -= j-l+1;
		quick_sort(j+1, r);
	}

	return ;
}

int main()
{
	scanf("%d %d", &n ,&k);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &line[i]);

	quick_sort(0, n-1);

	printf("%d", ans);
	
	return 0;
}
