#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
int n, m, cnt1, cnt2, F[N], line1[N], line2[N];
long long int ans1[N], ans2[N];

int find_father(int x) {
	return F[x] == x ? x : F[x] = find_father(F[x]);
}

void init() {
	for(int i=1; i<=n; i++) F[i] = i;
	cnt1 = cnt2 = 0;
	memset(line1, 0, sizeof(line1));
	memset(line2, 0, sizeof(line2));
	memset(ans1, 0x7f, sizeof(ans1));
	memset(ans2, 0x7f, sizeof(ans2));
	return ;
}

long long int count(int x, int* line, int cnt) {
	int l = 1, r = cnt, mid;
	while(l < r) {
		mid = (l + r + 1) / 2;
		if(line[mid] < x)
			l = mid;
		else
			r = mid - 1;
	}
	long long int temp = (long long int)(line[l] - x) * (line[l] - x);
	if(l != cnt) {
		l++;
		temp = min(temp, (long long int)(line[l] - x) * (line[l] - x));
	}
	return temp;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);
		init();
		int x, y;
		for (int i = 0; i < m; ++i) {
			scanf("%d %d", &x, &y);
			x = find_father(x);
			y = find_father(y);
			F[x] = y;
		}
		for (int i = 1; i <= n; ++i) {
			if(find_father(i) == find_father(1))
				line1[++cnt1] = i;
			if(find_father(i) == find_father(n))
				line2[++cnt2] = i;
		}
		sort(line1 + 1, line1 + 1 + cnt1);
		sort(line2 + 1, line2 + 1 + cnt2);
		if(find_father(1) == find_father(n)) {
			printf("0\n");
			continue;
		}
		int fa1 = find_father(1), fa2 = find_father(n);
		ans1[fa1] = 0; ans2[fa2] = 0;
		for (int i = 1; i <= n; ++i) {
			int fa = find_father(i);
			if(fa != fa1) {
				ans1[fa] = min(ans1[fa], count(i, line1, cnt1));
			}
			if(fa != fa2) {
				ans2[fa] = min(ans2[fa], count(i, line2, cnt2));
			}
		}
		long long int ans;
		for (int i = 1; i <= n; ++i) {
			int fa = find_father(i);
			if(i == 1)
				ans = ans1[fa] + ans2[fa];
			ans = min(ans, ans1[fa] + ans2[fa]);
		}
		printf("%lld\n", ans);
	}
	return 0;

}
