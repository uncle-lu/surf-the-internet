#include<iostream>
#include<cstring>
using namespace std;

char str[210];

int main()
{
    cin.getline(str, 210);
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'E')
            str[i] += 21;
        else if(str[i] >= 'F' && str[i] <= 'Z')
            str[i] -=5;
    }
    printf("%s", str);
    return 0;
}