#include<cstdio>
#include<cstring>

char line[10];

int main()
{
    line[0] = 'a';
    line[1] = 'b';
    line[2] = 'c';
    line[3] = '\0';

    printf("%s", line);

    return 0;
}