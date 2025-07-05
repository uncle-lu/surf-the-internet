#include<cstdio>

int gcd(int x, int y)
{
    if(y == 0)return x;
    return gcd(y, x%y);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));
    return 0;
}