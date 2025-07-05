#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int N = 1e5+10;
int n;
int a[N], b[N], c[N], t[N];
struct qnode{
	int t, x;
	friend bool operator<(const qnode _x, const qnode _y) {
		return _x.t < _y.t;
	}
};
struct node{
	int v, next;
}edge[2*N];
int head[N], cnt, fa[N];
int line[N], cline;

void add_edge(int x, int y) {
	edge[++cnt].v = y;
	edge[cnt].next = head[x];
	head[x] = cnt;
	return ;
}

void DFS(int x) {
	int tot = 0;
	for(int i=head[x]; ~i; i=edge[i].next) {
		if(edge[i].v == fa[x])continue;
		fa[edge[i].v] = x;
		DFS(edge[i].v);
		tot++;
	}
	if(tot == 0)line[++cline] = x;
	return ;
}

int st(int _a, int _b, int _c, int _m) {
	if(_c < 0) {
		int x = (1 - _b) / _c;
		if(x<=0)x = 1;
		if(x<_m) {
			_a -= _m - x;
			int l=1, r=x-1, mid;
			while(l < r) {
				mid = (l + r)/2;
				if( (mid*_c+_b+(x-1)*_c+_b)*(x-mid)/2 < _a )
					l = mid+1;
				else
					r = mid;
			}
			if((l*_c+_b+(x-1)*_c+_b)*(x-l)/2 < _a)
				return -1;
			else
				return l;
		}
	} 
	if((_c+_b+_c*_m+_b)*_m/2<_a)return -1;
	int l=1, r=_m, mid;
	while(l < r) {
		mid = (l + r)/2;
		if((mid*_c + _b + _m*_c+_b)*(_m-mid+1)/2 < _a)
			l = mid+1;
		else
			r = mid;
	}
	if((l*_c+_b+_m*_c+_b)*(_m-l+1)/2<_a)
		return -1;
	else
		return l;
}

bool check(int m) {
	for(int i=1; i<=n; i++) {
		t[i] = st(a[i], b[i], c[i], m);
		if(t[i] == -1)
			return false;
	}
	priority_queue<qnode>qu;
	for(int i=1; i<=cline; i++)
		qu.push((qnode){t[line[i]], line[i]});
	int tot=n;
	while(!qu.empty()) {
		qnode now = qu.top(); qu.pop();
		if(now.t<tot)
			return false;
		if(fa[now.x] != 0)
			qu.push((qnode){t[fa[now.x]], fa[now.x]});
		tot--;
	}
	return true;
}

int main() {
	memset(head, -1, sizeof(head));
	int u, v;
	scanf("%d", &n);
	for(int i=1; i<=n; i++) 
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
	for(int i=1; i<=n-1; i++) {
		scanf("%d %d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	DFS(1);

	int l = 1, r = 1e9+1, mid;
	while(l < r){
		mid = (l + r) / 2;
		if(check(mid))
			r = mid;
		else
			l = mid+1;
	}
	
	printf("%d", l);
	return 0;
}
