#include<cstdio>

int cnt[5];

int main()
{
    int n, temp;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &temp);
        if(temp <= 18) cnt[1]++;
        else if(temp >= 19 && temp <= 35) cnt[2]++;
        else if(temp >= 36 && temp <= 60) cnt[3]++;
        else cnt[4]++;
    }

    for(int i=1; i<=4; i++)
        printf("%.2lf%%\n", (double)cnt[i]/n * 100);

    return 0;
}