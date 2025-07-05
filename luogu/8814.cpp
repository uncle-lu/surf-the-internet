#include<cstdio>

int main() {
    int k=1;
    scanf("%d", &k);
    while(k--) {
        long long int n, d, e;
        scanf("%lld %lld %lld", &n, &d, &e);
        long long int s = n - e*d + 2;
        long long int l = 1, r = s / 2, mid;
        while(l < r) {
            mid = (l + r + 1) / 2;
            if(mid * (s - mid) <= n)
                l = mid;
            else
                r = mid - 1;
        }
        if((l * (s-l)) == n) 
            printf("%lld %lld\n", l, s-l);
        else  
            printf("NO\n");
    }
    return 0;
}