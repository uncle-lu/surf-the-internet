#include <cstdio>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int cnt = c * 60 + d - (a * 60 + b);
    printf("%d %d", cnt / 60, cnt % 60);
    return 0;
}