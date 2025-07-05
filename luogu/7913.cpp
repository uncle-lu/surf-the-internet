#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int N = 1e5+10;
struct node{
	int a, b;
	friend bool operator<(const node x, const node y){
		return x.a < y.a ;
	}
	friend bool operator>(const node x, const node y) {
		return x.a > y.a;
	}
};
node line1[N], line2[N];
int n, m1, m2; 
int tong1[N], tong2[N];

void calc(int m, node* line, int* tong) {
	priority_queue<int, vector<int>, greater<int> >ports;
	priority_queue<node, vector<node>, greater<node> >qu;
	for(int i=1; i<=n; i++) ports.push(i);
	for(int i=1; i<=m; i++) {
		while((!qu.empty()) && qu.top().a < line[i].a){
			ports.push(qu.top().b);
			qu.pop();
		}
		if(ports.empty())continue;
		qu.push((node){line[i].b, ports.top()});
		tong[ports.top()]++;
		ports.pop();
	}
	for(int i=1; i<=n; i++)
		tong[i] += tong[i-1];
	return ;
}

int main() {
	scanf("%d %d %d", &n, &m1, &m2);
	for(int i=1; i<=m1; i++)
		scanf("%d %d", &line1[i].a, &line1[i].b);
	for(int i=1; i<=m2; i++)
		scanf("%d %d", &line2[i].a, &line2[i].b);

	sort(line1+1, line1+1+m1);
	sort(line2+1, line2+1+m2);

	calc(m1, line1, tong1);
	calc(m2, line2, tong2);

	int ans = 0;
	for(int i=0; i<=n; i++){
		ans = max(ans, tong1[i] + tong2[n-i]);
	}
	printf("%d", ans);
	return 0;
}
