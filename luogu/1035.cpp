#include<cstdio>

int main() {
    int k, n = 0;
    double s = 0;
    scanf("%d", &k);
    while(s <= k) {
        n++;
        s += 1.0 / n;
    }
    printf("%d", n);
    return 0;
}