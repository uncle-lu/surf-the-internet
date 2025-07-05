#include<cstdio>

int count(int x) {
    int sum = 0;
    for(int i=1; i<x; i++)
        if(x % i == 0)
            sum += i;
    return sum;
}

int main() {
    int s;
    scanf("%d", &s);
    while(true) {
        int other = count(s);
        if(other != s && count(other) == s ) {
            printf("%d %d", s, other);
            break;
        }
        s++;
    }
    return 0;
}