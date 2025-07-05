#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;

int n, k;
long long int s, f[30];
int line[30];
vector<pair<long long int, int> >line1, line2;

void DFS(bool mode, int x, int cnt, long long int sum) {
	if(sum > s)return ;
	if(mode && x > n/2) {
		line1.push_back(make_pair(sum, cnt));
		return ;
	}
	else if(x > n) {
		line2.push_back(make_pair(sum, cnt));
		return ;
	}

	DFS(mode, x+1, cnt, sum);
	DFS(mode, x+1, cnt, sum + line[x]);
	if(cnt < k && line[x] <= 20) DFS(mode, x+1, cnt+1, sum + f[line[x]]);
	return ;
}

int main() {
	scanf("%d %d %lld", &n, &k, &s);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &line[i]);
	f[0] = 1;
	for(int i=1; i<=20; i++)
		f[i] = f[i-1] * i;
	
	DFS(true, 1, 0, 0);
	DFS(false, n/2+1, 0, 0);

	sort(line1.begin(), line1.end(), greater<pair<long long int, int> >());
	sort(line2.begin(), line2.end(), less<pair<long long int, int> >());

	int curr1 = 0, curr2 = 0, len1 = line1.size(), len2 = line2.size();
	long long int ans = 0;
	while(curr1 < len1 && curr2 < len2) {
		while(curr1 < len1 && line1[curr1].first + line2[curr2].first > s)curr1++;
		while(curr2 < len2 && line1[curr1].first + line2[curr2].first < s)curr2++;
		if(curr1 >= len1 || curr2 >= len2)break;
		if(line1[curr1].first + line2[curr2].first != s)continue;
		int cnt1[30], cnt2[30];
		memset(cnt1, 0, sizeof(cnt1)); memset(cnt2, 0, sizeof(cnt2));
		do {
			cnt1[line1[curr1].second]++;
			curr1++;
		} while(curr1 < len1 && line1[curr1].first == line1[curr1-1].first);
		do {
			cnt2[line2[curr2].second]++;
			curr2++;
		} while(curr2 < len2 && line2[curr2].first == line2[curr2-1].first);
		for (int i = 0; i <= k; ++i) 
			for (int j = 0; j + i <= k; ++j) 
				ans += 1LL * cnt1[i] * cnt2[j];
	}

	printf("%lld", ans);
	return 0;
}
