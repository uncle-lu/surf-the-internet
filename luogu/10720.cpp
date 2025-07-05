#include <cmath>
#include <cstdio>

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int s = sqrt(n), cnt = 0;
        for (int i = 2; i <= s; i++)
            if (n % i == 0) {
                cnt++;
                if (cnt >= 3)
                    break;
                while (n % i == 0)
                    n /= i;
            }
        if(n != 1)
            cnt++;
        printf("%d\n", cnt == 2 ? 1 : 0);
    }
    return 0;
}