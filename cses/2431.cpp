#include <cstdio>

int main() {
    int q;
    long long int k;
    scanf("%d", &q);
    while(q--) {
        scanf("%lld", &k);
        int base = 1;
        long long int limit = 9, ans = 1;
        while(k > limit) {
            base ++;
            limit = limit * 10;
        }
        k -= limit;
        for(int i = 1; i <= base; i++) 
            ans *= 10;
        ans = k / base + ans;
        k %= base;
        for(int i = 1; i <= base; i++)
    }

    return 0;
}