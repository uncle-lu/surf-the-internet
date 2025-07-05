#include <cstdio>
#include <cmath>

bool check(int x) {
    for(int i = 2; i <= sqrt(x); i++) 
        if(x % i == 0)
            return false;
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int h, ans = 0, tack = 1;
        scanf("%d", &h);
        do {
            if(check(h)) {
                ans++;
                h = 0;
                break;
            }
            h -= tack;
            tack *= 2;
            ans++;
        } while(h > 0);
        printf("%d\n", (ans == 0 || h != 0) ? -1 : ans);
    }
    return 0;
}