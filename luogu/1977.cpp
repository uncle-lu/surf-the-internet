#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 110;
int f[N][N];
int t[N], z[N], sum[N];

int main() {
    int n, k, d, s;
    scanf("%d %d %d %d", &n, &k, &d, &s);
    for (int i = 1; i <= k; i++) {
        scanf("%d %d", &t[i], &z[i]);
        sum[i] = sum[i - 1] + z[i];
    }
    if (sum[k] < n) {
        printf("impossible");
        return 0;
    }
    memset(f, 0x7f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= sum[i]; j++) {
            f[i][j] = f[i - 1][j];
            for (int now = 1; now <= z[i] && j - now >= 0; now++)
                f[i][j] = min(f[i][j], f[i - 1][j - now] + d + now * t[i]);
        }

    printf("%d", f[k][n]);
    return 0;
}