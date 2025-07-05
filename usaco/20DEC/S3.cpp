#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1010;
struct node{
	int v, next;
};
struct point{
	int x, y;
	bool f;
	friend bool operator<(const point a, const point b) {
		return a.x < b.x;
	}
};
node edge[N];
point line[N];
int head[N], cnt, Ecnt, Ncnt;
bool vis[N];

int main() {
	memset(head, -1, sizeof(head));
	int n, x, y; char mod;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%c %d %d\n", &mod, &line[i].x, &line[i].y);
		line[i].f = (mod == 'E' ? true : false);
	}
	sort(line+1, line+1+n);
	for (int i = 1; i <= n; ++i) {
		if(line[i].f)continue;

		for (int j=i-1; j>=1; j--) {
			if(!line[j].f || vis[j])continue;
			


		}
	}
}
