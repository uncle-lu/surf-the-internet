#include<cstdio>
#include<cstring>
bool tong[10000+10];
int main()
{
    int l, m, x, y, cnt = 0;
    memset(tong, true, sizeof(tong));
    scanf("%d %d", &l, &m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d", &x, &y);
        for(int j=x; j<=y; j++)
            tong[j] = false;
    }
    for(int i=0; i<=l; i++)
        if(tong[i])
            cnt++;
    printf("%d", cnt);
    return 0;
}