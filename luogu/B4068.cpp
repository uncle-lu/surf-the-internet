#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 3e3 + 10;
bool vis[N*N];
int line[N];

int main() {
    int n;
    scanf("%d", &n);
    line[1] = 1; vis[1] = true;
    for(int i = 2; i <= n; i++) {
        if(line[i - 1] - i > 0 && !vis[line[i-1] - i])
            line[i] = line[i-1] - i;
        else
            line[i] = line[i-1] + i;
        vis[line[i]] = true;
    }
    sort(line + 1, line + 1 + n);
    for(int i = 1; i <= n; i++) 
        printf("%d ", line[i]);
    return 0;
}