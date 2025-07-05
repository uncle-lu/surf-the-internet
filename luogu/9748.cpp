#include<cstdio>
#include<cmath>

int main() {
    int n, ans1 = 0, ans2 = 0;
    scanf("%d", &n);
    while(n != 0) {
        ans1 ++;
        if(ans2 == 0 && n % 3 == 1)
            ans2 = ans1;
        n = n - ceil(n / 3.0);
    }
    printf("%d %d", ans1, ans2);
    return 0;
}