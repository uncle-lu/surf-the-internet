#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int line1[N], line2[N], n, m;
int main() {
	scanf("%d %d", &n ,&m);
	for(int i=1; i<=n; i++)
		scanf("%d", &line1[i]);
	for(int i=1; i<=m; i++)
		scanf("%d", &line2[i]);
	sort(line2+1, line2+1+m);
	for(int i=1; i<=n; i++) {
		int l=1, r=m, mid;
		while(l < r) {
			mid = (l + r) / 2;
			if(line1[i] > line2[mid])
				l = mid+1;
			else
				r = mid;
		}
		if(line1[i] == line2[l]) {
			printf("%d ", line1[i]);
		}
	}
	return 0;
}
