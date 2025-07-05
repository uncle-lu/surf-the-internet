#include<cstdio>
#include<cstring>
#include<queue>

const int N = 1e5+10;
const int ALL = (1<<19)-1;
int dis[ALL], line[N];
bool vis[ALL];

int main() {
	int c, n;
	char temp[20];
	memset(dis, 0x7f, sizeof(dis));
	std::queue<int>qu;
	scanf("%d %d\n", &c, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", temp+1);
		int front=0, back=0;
		for (int t = 1; t <= c; ++t) {
			front <<= 1; back <<= 1;
			if(temp[t] == 'G')
				front += 1;
			else
				back += 1;
		}
		line[i] = front;
		qu.push(back); dis[back] = 0; vis[back] = true;
	}
	while(!qu.empty()) {
		int now = qu.front();
		qu.pop();
		vis[now] = false;
		int sit = 1;
		for (int i = 1; i <= c; ++i, sit<<=1) {
			int t = now ^ sit;
			if(dis[t] > dis[now] + 1) {
				dis[t] = dis[now] + 1;
				if(vis[t])continue;
				vis[t] = true;
				qu.push(t);
			}
		}
	}

	for (int i = 1; i <= n; ++i) 
		printf("%d\n", c - dis[line[i]]);
	return 0;
}
