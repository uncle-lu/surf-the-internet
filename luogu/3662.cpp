#include<cstdio>

const int N = 1e5+10;
int sum[N];

int main() {
    int n, k, b, temp; 
    scanf("%d %d %d", &n, &k, &b);
    for(int i=1; i<=b; i++) {
        scanf("%d", &temp);
        sum[temp] += 1;
    }
    for(int i=1; i<=n; i++)
        sum[i] += sum[i-1];
    int mi = N;
    for(int i=k; i<=n; i++) {
        if(mi > sum[i] - sum[i-k])
            mi = sum[i] - sum[i-k];
    }
    printf("%d", mi);
    return 0;
}