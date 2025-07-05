#include <cmath>
#include <cstdio>

long long int n;

int main() {
    int ans = 0;
    scanf("%lld", &n);
    long long int s = sqrt(n);
    for (int i = 2; i <= s; i++)
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            for(int i = 1; i <= cnt; i++) {
                ans ++;
                cnt -= i;
            }
        }
    if(n != 1)
        ans++;
    printf("%d", ans);
    return 0;
}