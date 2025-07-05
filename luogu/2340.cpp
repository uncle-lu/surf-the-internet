#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 410, P = 400000;
int F[800010], s[N], f[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf("%d %d", &s[i], &f[i]);

	memset(F, -0x7f, sizeof(F));
	F[0 + P] = 0;
	for (int i = 1; i <= n; ++i)
	{
		if(s[i] >= 0)
			for (int j = 2*P; j >= s[i]; j--) 
				F[j] = max(F[j], F[j-s[i]] + f[i]);
		else
			for (int j = 0; j <= 2*P + s[i]; j++)
				F[j] = max(F[j], F[j-s[i]] + f[i]);
	}

	int ans = 0;
	for (int i = 0; i <= P; ++i)
		if(F[i + P] > 0)
			ans = max(ans, F[i + P] + i);

	printf("%d", ans);
	return 0;
}
