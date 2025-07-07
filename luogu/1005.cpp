#include <bits/stdc++.h>
using namespace std;

const int N = 81;
__int128 f[N][N], base[N], ans;
int line[N];

void output(__int128 x) {
    if (x >= 10)
        output(x / 10);
    putchar(x % 10 + '0');
    return;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    base[0] = 1;
    for (int i = 1; i <= m; i++)
        base[i] = base[i - 1] * 2;
    for (int i = 1; i <= n; i++) {
        memset(f, 0, sizeof(f));
        for (int j = 1; j <= m; j++)
            scanf("%d", &line[j]);
        for (int j = 1; j <= m; j++)
            f[j][j] = (__int128)line[j] * base[m];
        for (int len = 2; len <= m; len++)
            for (int l = 1; l <= m - len + 1; l++) {
                int r = l + len - 1;
                f[l][r] = max(f[l + 1][r] + base[m - len + 1] * line[l], f[l][r - 1] + base[m - len + 1] * line[r]);
            }
        ans += f[1][m];
    }
    output(ans);
    return 0;
}