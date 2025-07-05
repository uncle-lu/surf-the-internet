#include <cstdio>
#include <cstring>
const int N = 1010;
int d[N], c[N], f[N][N];
int main() {
    memset(f, 0x7f, sizeof(f));
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &c[i]);
    for (int i = 0; i <= m; i++)
        f[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        int mi = f[i - 1][i - 1];
        for (int j = i; j <= m; j++) {
            if (f[i - 1][j - 1] < mi)
                mi = f[i - 1][j - 1];
            f[i][j] = mi + c[j] * d[i];
        }
    }
    int ans = f[n][n];
    for (int i = n + 1; i <= m; i++)
        if (f[n][i] < ans)
            ans = f[n][i];
    printf("%d", ans);
    return 0;
}