#include <cstdio>

const int N = 110;
bool F[N][N*N];
int line[N];

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &line[i]);
        sum += line[i];
    }
    F[0][0] = true;
    for(int i = 1; i <= n; i++)
        for(int j = n / 2; j >= 1; j --)
            for(int k = sum / 2; k >= line[i]; k--)
                F[j][k] = F[j][k] || F[j - 1][k - line[i]];
    int ans = 0;
    for(int i = sum / 2; i >= 0; i--) {
        if(F[n/2][i]) {
            ans = i;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}