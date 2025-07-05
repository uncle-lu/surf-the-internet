#include<cstdio>
#include<cstring>

char str1[510], str2[510];

int main()
{
    double y;
    scanf("%lf\n%s\n%s", &y, str1, str2);
    
    int len = strlen(str1), cnt = 0;
    for ( int i = 0; i < len; i++ )
        if(str1[i] == str2[i])
            cnt++;

    if((double)cnt/len >= y)
        printf("yes");
    else   
        printf("no");
    return 0;
}
