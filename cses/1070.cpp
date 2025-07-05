#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    if(n == 1) {
        printf("1");
        return 0;
    }
    if(n == 4) {
        printf("2 4 1 3");
        return 0;
    }
    if(n < 5) {
        printf("NO SOLUTION");
        return 0;
    }
    for(int i = 1; i <= n; i += 2)
        printf("%d ", i);
    for(int i = 2; i <= n; i += 2)
        printf("%d ", i);
    return 0;
}