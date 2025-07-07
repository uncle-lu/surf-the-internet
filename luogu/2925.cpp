#include <cstdio>

const int N = 5e4 + 10;

bool F[N];

int main() {
    int c, h, v, ans = 0;
    scanf("%d %d", &c, &h);
    F[0] = 1;
    for(int i = 1; i <= h; i++) {
        scanf("%d", &v);
        for(int j = c; j >= v; j--)
            F[j] |= F[j - v];
    }
    for(int i = c; i >= 0; i--)
        if(F[i]) {
            ans = i;
            break;
        }
    printf("%d", ans);
    return 0;
}