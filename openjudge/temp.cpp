#include<cstdio>

int n, k, sum;
int line[1010];

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &line[i]);
    scanf("%d", &k);

    for(int i=1; i<=n; ++i)
        if(line[i] % 10 == k)
            sum += line[i];
    
    printf("%d", sum);

    return 0;
}