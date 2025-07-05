#include <cstdio>

const int N = 2e6+10;
char str[N];
int g[N], dp[N];

int main() {
    int n;
    long long ans = 0;
    scanf("%d", &n);
    scanf("%s", str + 1);
    for(int i = 1; i <= n; i++) {
        g[i] = i - 1;
        while(str[g[i]] != str[i] && g[i] > 0)
            g[i] = g[g[i]] - 1;
        if(g[i] > 0)
            dp[i] = dp[g[i] - 1] + 1;
    }
    for(int i = 1; i <= n; i++)
        ans += dp[i];
    printf("%lld", ans);
    return 0;
}