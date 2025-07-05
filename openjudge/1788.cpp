#include<cstdio>

int line[1000010];// => 存储算过的答案
int Pell(int x)// -> 求第x项的Pell数列
{
    if(x == 1)return 1;
    if(x == 2)return 2;
    if(line[x] != 0) // ->有存过的答案 ->之前算过了
        return line[x];
    line[x] = (2 * Pell(x-1) + Pell(x-2)) % 32767;
    return line[x];
}

int main()
{
    int T, n;
    scanf("%d", &T);
    for(int t=1; t<=T; ++t)
    {
        scanf("%d", &n);
        printf("%d\n", Pell(n) );
    }
    return 0;
}