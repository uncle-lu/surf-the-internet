#include <cstdio>

const int N = 1e5 + 10;
int q, n, top, d[N], c[N], sta[N], nex[N][26];
long long int sum[N][26];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &d[i], &c[i]);

    for (int i = 1; i <= n; i++) {
        while (top != 0 && d[sta[top]] < d[i]) {
            nex[sta[top]][0] = i;
            top--;
        }
        sta[++top] = i;
        sum[i][0] = c[i];
    }

    for (int j = 1; j <= 25; j++)      // 枚举倍数
        for (int i = 1; i <= n; i++) { // 枚举每个盘子
            nex[i][j] = nex[nex[i][j - 1]][j - 1];
            sum[i][j] = sum[i][j - 1] + sum[nex[i][j - 1]][j - 1];
        }

    while (q--) {
        int r, v;
        scanf("%d %d", &r, &v);
        for (int i = 25; i >= 0; i--)
            if (v > sum[r][i]) {
                v -= sum[r][i];
                r = nex[r][i];
            }
        printf("%d\n", r);
    }
    return 0;
}