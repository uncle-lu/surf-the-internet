#include<cstdio>
#include<vector>
using namespace std;

const int N = 5 * 1e6 + 10;
vector<int>P[4];
bool f[N];

void init() {
	vector<int>pline;
	for (int i = 2; i < N; ++i) {
		if(!f[i]){
			pline.push_back(i);
		}
		for (auto p : pline) {
			if(i * p >= N) break;
			f[i * p] = true;
			if(i % p == 0) break;
		}
	}
	for (auto p : pline) {
		P[p % 4].push_back(p);
	}
	return ;
}

int main() {
	int T, n;
	scanf("%d", &T);
	init();
	while(T--) {
		scanf("%d", &n);
		vector<int>line(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &line[i]);
		}
		int ans = N, relans;
		for (auto i : line) {
			int ans_temp;
			if(i % 4 == 0) {
				ans_temp = i / 2;
			}
			else {
				int l = 0, r = P[i % 4].size() - 1, mid;
				while(l < r) {
					mid = (l + r + 1) / 2;
					if(P[i % 4][mid] <= i)
						l = mid;
					else
						r = mid - 1;
				}
				ans_temp = (i - P[i % 4][l]) / 2 + 1;
			}
			if(ans_temp/2 < ans/2) {
				ans = ans_temp;
				relans = ans_temp;
			}
		}
		if(relans % 2)
			printf("Farmer John\n");
		else
			printf("Farmer Nhoj\n");
	}
	return 0;
}
