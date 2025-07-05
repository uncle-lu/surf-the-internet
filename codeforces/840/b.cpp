#include<cstdio>
#include<cstring>
#include<algorithm>

const int N = 100010;
int n, k, mi[N];
struct monster{
	int h, p;
	friend bool operator<(const monster a, const monster b) {
		return a.h > b.h || (a.h == b.h && a.p > b.p);
	}
};
monster line[N];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {
		memset(mi, 0, sizeof(mi));
		memset(line, 0, sizeof(line));
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &line[i].h);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &line[i].p);
		}

		std::sort(line, line+n);

		mi[0] = line[0].p;
		for (int i = 1; i < n; ++i) {
			mi[i] = mi[i-1] > line[i].p ? line[i].p : mi[i-1];
		}

		int before = 0;
		for (int i = n-1; i >= 0; --i) {
			while(line[i].h - before > k && k >= 0)
			{
				before += k;
				k -= mi[i];
			}
			if(k < 0)
				break;
		}
		if(line[1].h <= before + k && k >= 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
