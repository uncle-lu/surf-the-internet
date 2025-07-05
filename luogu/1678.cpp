#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100001;
int line1[N], line2[N];
long long int sum;
int main() { int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		scanf("%d", &line1[i]);
	for(int i=1; i<=m; i++)
		scanf("%d", &line2[i]);
	sort(line1+1, line1+1+n);
	for(int i=1; i<=m; i++) {
		int l = 1, r = n, mid, val = line2[i];
		while(l < r) {
			mid = (l + r) / 2;
			if(line1[mid] < val)
				l = mid+1;
			else
				r = mid;
		}
		if(l == 1) {
			sum += abs(line1[l] - val);
		}
		else {
			sum += min(abs(line1[l]-val), abs(line1[l-1]-val));
		}
	}
	printf("%lld", sum);
	return 0;
}
