#include <cstdio>

bool F[60][1010];

int main() {
    int n, bl, ml, ci;
    scanf("%d %d %d", &n, &bl, &ml);
    F[0][bl] = true;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &ci);
        for(int j = ci; j <= ml; j++)
            F[i][j] |= F[i-1][j - ci];
        for(int j = 0; j <= ml - ci; j++)
            F[i][j] |= F[i-1][j + ci];
    }
    int ans = -1;
    for(int i = ml; i >= 0; i--)
        if(F[n][i]) {
            ans = i;
            break;
        }
    printf("%d", ans);
    return 0;
}