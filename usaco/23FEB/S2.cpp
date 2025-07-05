#include<cstdio>
#include<algorithm>

struct node{
	long long int x, y, t;
	friend bool operator<(const node a, const node b) {
		return a.t < b.t;
	}
};

const int N = 1e5+10;
node line[N];

int main() {
	int g, n, cnt = 0;
	long long int x, y, t;
	scanf("%d %d", &g, &n);
	for (int i = 0; i < g; ++i) 
		scanf("%lld %lld %lld", &line[i].x, &line[i].y, &line[i].t);
	std::sort(line, line+g);

	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld %lld", &x, &y, &t);

		int l=0, r=g-1, mid;
		while(l < r) {
			mid = (l + r) / 2;
			if(t < line[mid].t)
				r = mid;
			else
				l = mid + 1;
		}
		bool flag = false;
		if(l != 0) {
			int temp = l-1;
			if((line[temp].x-x)*(line[temp].x-x) + (line[temp].y-y)*(line[temp].y-y) > (line[temp].t-t)*(line[temp].t-t))
				flag = true;
		}
		if(l != g) {
			if((line[l].x-x)*(line[l].x-x) + (line[l].y-y)*(line[l].y-y) > (line[l].t-t)*(line[l].t-t))
				flag = true;
		}
		if(flag)
			cnt++;
	}

	printf("%d", cnt);
	return 0;
}
