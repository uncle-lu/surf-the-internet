#include<cstdio>
int tong[3010], line[3010];
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &line[i]);

    for(int i=2; i<=n; i++)
    {
        int temp = line[i] - line[i-1];
        if(temp < 0) temp = -temp;
        if(temp >= n) { printf("Not jolly"); return 0; }
        tong[temp] ++;
    }
    bool flag = true;
    for(int i=1; i<=n-1; i++)
        if(tong[i] != 1)
        {
            flag = false;
            break;
        }
    if(flag)printf("Jolly");
    else printf("Not jolly");

    return 0;
}