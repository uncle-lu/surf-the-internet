#include <cstdio>

void DFS(int x, int last_sit) {
    if(...) { // 枚举到第k位之后
        if(check(sum)){
            ans++;
        }
    }
    for(int i = last_sit + 1; i <= n; i++) {
        sum += line[i];
        DFS(x + 1, i);
        sum -= line[i];
    }
}

int main() {

} 