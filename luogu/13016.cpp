#include <algorithm>
#include <cmath>
#include <cstdio>

int jump(int x) {
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return x / i;
    return 1;
}

int solve(int x, int y) {
    int ans = 0;
    while (x != y) {
        if (x < y)
            y = jump(y);
        else
            x = jump(x);
        ans++;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", solve(x, y));
    }
    return 0;
}