#include<cstdio>
#include<algorithm>

const int N = 1.5 * 1e5 + 10;
struct node{
	int sit, val;
	friend bool operator<(const node a, const node b) {
		return a.val < b.val;
	}
};
node line[N];
int pos[N], a[N];
long long int sum[N];

int main() {
	int n, T, x, y;
	long long int all = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		line[i] = (node){ i, a[i] };
	}
	std::sort(line+1, line+1+n);
	for (int i = 1; i <= n; ++i) {
		pos[line[i].sit] = i;
		sum[i] = sum[i-1] + line[i].val;
		all += 1LL * line[i].val * i;
	}
	scanf("%d", &T);
	while(T--) {
		long long int temp = all;
		scanf("%d %d", &x, &y);
		if(a[x] < y) {
			int l = pos[x]+1, r = n, mid;
			while(l < r) {
				mid = (l + r + 1) / 2;
				if(line[mid].val <= y)
					l = mid;
				else
					r = mid - 1;
			}
			if(line[l].val > y)
				l--;
			temp = temp - 1LL*a[x]*pos[x] - (sum[l]-sum[pos[x]]) + 1LL*y*l;
		}
		else if(a[x] > y) {
			int l = 1, r = pos[x]-1, mid;
			while(l < r) {
				mid = (l + r + 1) / 2;
				if(line[mid].val <= y)
					l = mid;
				else
					r = mid - 1;
			}
			if(line[l].val > y) 
				l--;
			temp = temp - 1LL*a[x]*pos[x] + (sum[pos[x]-1]-sum[l]) + 1LL*y*(l+1);
		}
		printf("%lld\n", temp);
	}
	return 0;
}
