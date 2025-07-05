#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e5+10;
const int mod = 1e9 + 7;
struct node{
	int x, y;
	long long int sumx, sumy;
};
node line[N];
int n;
long long int ans;

bool cmp1(node a, node b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp2(node a, node b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

void turn() {
	for (int i = 1; i <= n; ++i) {
		int tempx = line[i].x, tempy = line[i].y;
		line[i].x = tempy; line[i].y = - tempx;
		line[i].sumx = 0; line[i].sumy = 0;
	}
	return ;
}

void sum() {
	sort(line + 1, line + 1 + n, cmp1);
	int cnt = 0;
	for (int i = 2; i <= n; ++i) {
		if(line[i].x == line[i-1].x) {
			cnt ++;
			line[i].sumx = (line[i-1].sumx + cnt * (line[i].y - line[i-1].y) % mod) % mod;
		}
		else
			cnt = 0;
	}
	sort(line + 1, line + 1 + n, cmp2);
	cnt = 0;
	for (int i = 2; i <= n; ++i) {
		if(line[i].y == line[i-1].y) {
			cnt ++;
			line[i].sumy = (line[i-1].sumy + cnt * (line[i].x - line[i-1].x) % mod ) % mod;
		}
		else
			cnt = 0;
	}
	for (int i = 1; i <= n; ++i) {
		ans = (ans + line[i].sumx * line[i].sumy % mod) % mod;
	}
	return ;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &line[i].x, &line[i].y);
	}
	sum();
	turn();
	sum();
	turn();
	sum();
	turn();
	sum();

	printf("%lld", ans);
	return 0;
}
