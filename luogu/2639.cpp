#include <cstdio>

bool F[45010];

int main() {
    int h, n, v;
    scanf("%d %d", &h, &n);
    F[0] = true;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v);
        for(int j = h; j >= v; j--)
            F[j] |= F[j - v];
    }
    int ans = 0;
    for(int i = h; i >= 0; i--)
        if(F[i]) {
            ans = i;
            break;
        }
    printf("%d", ans);
    return 0;
}