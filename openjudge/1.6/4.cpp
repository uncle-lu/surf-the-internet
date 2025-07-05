#include<cstdio>

int line[110];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) {
        scanf("%d", &line[i]);
    }

    for(int i=1; i<=n/2; ++i) {
        int temp = line[i];
        line[i] = line[n-i+1];
        line[n-i+1] = temp;
    }

    for(int i=1; i<=n; i++) {
        printf("%d ", line[i]);
    }

    return 0;
}
