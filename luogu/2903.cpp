#include <cstdio>
#include <queue>

const int N = 1051;
struct node { // 齿轮的信息
    int x, y, r; // 坐标 半径
} line[N];
struct qunode{ // 待搜索状态的队列
    double speed, sum; // 当前齿轮的转速, 从start到当前齿轮的和
    int sit; // 搜索到当前位置的齿轮
};
bool link[N][N], vis[N];// link[i][j] 记录 齿轮i与齿轮j是否能链接 , vis[i]走过
int n, xt, yt;

bool check(int x, int y) {
    return  (line[x].x - line[y].x) * (line[x].x - line[y].x) + (line[x].y - line[y].y) * (line[x].y - line[y].y) == (line[x].r + line[y].r) * (line[x].r + line[y].r);
}

int main() {
    int start, end;
    scanf("%d %d %d", &n, &xt, &yt);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &line[i].x, &line[i].y, &line[i].r);
        if(line[i].x == 0 && line[i].y == 0) start = i;
        if(line[i].x == xt && line[i].y == yt) end = i;
    }

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            if(i != j && check(i, j))
                link[i][j] = true;
    
    std::queue<qunode>qu;
    qu.push((qunode){10000, 10000, start});
    vis[start] = true;
    while(!qu.empty()) {
        qunode now = qu.front();
        qu.pop();
        if(now.sit == end){
            printf("%d", (int)now.sum);
            break;
        }
        for(int i = 1; i <= n; i++) {
            if(vis[i] || !link[now.sit][i]) continue;
            vis[i] = true;
            qunode temp;
            temp.sit = i;
            temp.speed = now.speed * line[now.sit].r / line[i].r;
            temp.sum = now.sum + temp.speed;
            qu.push(temp);
        }
    }
    return 0;
}