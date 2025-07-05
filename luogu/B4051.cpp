#include <cstdio>

int n, m;

int main() {
    int temp, mx = -1e9;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &temp);
        mx = temp > mx ? temp : mx;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &temp);
        if(n == 1 || temp > 0)
            mx += temp;
    }
    printf("%d", mx);
    return 0;
}