#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int M = 250010;
const int N = 1e6+10;
struct node {
	int v, next;
};
node toCir[M];
node toPoint[M];
int headToCir[N], headToPoint[N], cntToCir, cntToPoint, size[M];
bool vis[M], ans[N];
void add_edge_Cir(int cow, int cir) {
	toCir[++cntToCir].v = cir;
	toCir[cntToCir].next = headToCir[cow];
	headToCir[cow] = cntToCir;
	return ;
}
void add_edge_Poi(int cow, int cir) {
	toPoint[++cntToPoint].v = cow;
	toPoint[cntToPoint].next = headToPoint[cir];
	headToPoint[cir] = cntToPoint;
	return ;
}
int main() {
	memset(headToCir, -1, sizeof(headToCir));
	memset(headToPoint, -1, sizeof(headToPoint));
	int n, g, cow;
	scanf("%d %d", &n, &g);
	for(int i=1; i<=g; i++) {
		scanf("%d", &size[i]);
		for(int j=1; j<=size[i]; j++) {
			scanf("%d", &cow);
			add_edge_Cir(cow, i);
			add_edge_Poi(cow, i);
		}
	}
	queue<int>qu;
	ans[1] = true;
	for(int i=headToCir[1]; ~i; i=toCir[i].next) {
		int cir = toCir[i].v;
		vis[cir] = true;
		qu.push(cir);
	}
	while(!qu.empty()) {
		int now = qu.front(); qu.pop();
		vis[now] = false;
		int cnt = 0, last = 0;
		for(int i=headToPoint[now]; ~i; i=toPoint[i].next) {
			int point = toPoint[i].v;
			if(ans[point])
				cnt++;
			else
				last = point;
		}
		if(cnt == size[now]-1) {
			ans[last] = true;
			for(int i=headToCir[last]; ~i; i=toCir[i].next) {
				int cir = toCir[i].v;
				if(vis[cir])continue;
				qu.push(cir);
				vis[cir] = true;
			}
		}
	}
	int ansCnt = 0;
	for(int i=1; i<=n; i++)
		if(ans[i])
			ansCnt++;
	printf("%d", ansCnt);
	return 0;
}
