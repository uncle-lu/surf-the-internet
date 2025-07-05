#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool flag;
long long int n;
long long int line[20], ans[20];

void DFS(int x, long long int a, long long int b) {
	if(x > n) {
		if(a == 0) {
			flag = true;
			if(ans[n] > line[n])
				for(int i=1; i<=n; i++)
					ans[i] = line[i];
		}

		return ;
	}
	long long int l = max(b/a, line[x-1]+1), r = min((n-x+1)*(b/a), ans[n]);
	for (long long int i = l; i <= r; i++) {
		line[x] = i;
		long long int ta = a * i - b, tb = b * i, t = __gcd(ta, tb);
		if(ta < 0)continue;
		ta /= t; tb /= t;
		DFS(x+1, ta, tb);
	}
	return ;
}

int main() {
	long long int a, b;
	scanf("%lld %lld", &a, &b);

	while(!flag) {
		++n;
		ans[n] = 0x3f3f3f3f;
		DFS(1, a, b);
	}

	for (int i = 1; i <= n; ++i)
		printf("%lld ", ans[i]);

	return 0;
}
