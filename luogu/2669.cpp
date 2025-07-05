#include<cstdio>

int main() {
    int n, sum = 0, cnt = 1;
    scanf("%d", &n);
    for(int i=1; i<=n; ) {
        for(int j=1; j<=cnt&&i<=n; j++, i++)
            sum += cnt;
        cnt++;
    }
    printf("%d", sum);
    return 0;
}