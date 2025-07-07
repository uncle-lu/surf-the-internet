#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010;
int F[N], v[N];

int main() {
    int S;
    scanf("%d", &S);
    for(int i = 1; i <= S; i++) 
        for(int j = 1; j < i; j++) 
            if(i % j == 0)
                v[i] += j;

    for(int i = 1; i <= S; i++)
        for(int j = S; j >= i; j--)
            F[j] = max(F[j], F[j - i] + v[i]);

    printf("%d", F[S]);
    return 0;
}