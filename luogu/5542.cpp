#include <cstdio>

const int N = 1010;
int cha[N][N], sum[N][N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        cha[x1][y1] += 1;
        cha[x2][y1] -= 1;
        cha[x1][y2] -= 1;
        cha[x2][y2] += 1;
    }
    for (int i = 0; i < N; i++)
        for (int j = 1; j < N; j++)
            cha[j][i] += cha[j - 1][i];

    for (int i = 0; i < N; i++)
        for (int j = 1; j < N; j++)
            cha[i][j] += cha[i][j - 1];

    int cnt = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (cha[i][j] == k)
                cnt++;
    printf("%d", cnt);
    return 0;
}