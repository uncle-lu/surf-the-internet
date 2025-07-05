#include<cstdio>
#include<algorithm>
using namespace std;

int line[100010];
int n;

void qsort(int l, int r)
{
	if(l >= r)return ;

	int mid = (l + r)/2;
	int temp = line[mid];
	int left = l, right = r-1;

	swap(line[mid], line[r]);

	do{
		while(line[left]<temp)left++;
		while(left<right && line[right]>temp)right--;
		swap(line[left], line[right]);
	}while(left < right);

	swap(line[left], line[right]);
	swap(line[left], line[r]);

	qsort(l, left-1);
	qsort(left+1, r);
	return ;
}

int main()
{
	freopen("in", "r", stdin);
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		scanf("%d", &line[i]);

	qsort(1, n);

	for(int i=1; i<=n; ++i)
		printf("%d ", line[i]);

	return 0;
}
