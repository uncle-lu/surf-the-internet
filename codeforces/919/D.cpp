#include<cstdio>
#include<cstring>

int n, q;

void solve() {
	scanf("%d %d", &n, &q);
	int lst[n+10];
	long long int s[n+10];
	memset(lst, 0, sizeof(lst));
	memset(s, 0, sizeof(s));
	for(int i=1; i<=n; i++) {
		int type, x;
		scanf("%d %d", &type, &x);
		if(type == 1) {
			lst[i] = x;
			s[i] = s[i-1] + 1;
		}
		else {
			lst[i] = lst[i-1];
			s[i] = ((x + 1) > 2e18 / s[i-1]) ? (long long)2e18: s[i-1]*(x+1);
		}
	}
	for(int i=1; i<=q; i++) {
		long long int temp;
		scanf("%lld", &temp);
		while(temp > 0) {
			int l=1, r=n, mid;
			while(l < r) {
				mid = (l + r) >> 1;
				if(s[mid] < temp)
					l = mid+1;
				else
					r = mid;
			}
			if(s[l] == temp) {
				printf("%d%c", lst[l], " \n"[i==q]);
				break;
			}
			if(temp % s[l-1] == 0) {
				printf("%d%c", lst[l-1], " \n"[i==q]);
				break;
			}
			temp = temp % s[l-1];
		}
	}
	return ;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		solve();
	}
	return 0;
}
