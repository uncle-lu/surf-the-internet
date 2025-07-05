#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int val, sit;
	friend bool operator<(const node a, const node b) {
		return a.val < b.val;
	}
}line[100010];
int main() {
	int n, m;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%d", &line[i].val);
		line[i].sit = i;
	}
	sort(line+1, line+1+n);
	scanf("%d", &m);
	for(int i=1; i<=m; i++) {
		int l = 1, r = n, mid, val;
		scanf("%d", &val);
		while(l <  r) {
			mid = (l + r) / 2;
			if(line[mid].val < val)
				l = mid+1;
			else
				r = mid;
		}
		if(line[l].val != val)
			printf("0\n");
		else
			printf("%d\n", line[l].sit);
	}
	return 0;
}
