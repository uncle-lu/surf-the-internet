#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	long long x, y;
	int step;
	friend bool operator<(const node a, const node b){
		return a.x < b.x || (a.x == b.x && a.y < b.y) || (a.x == b.x && a.y == b.y && a.step < b.step);
	}
	friend bool operator==(const node a, const node b){
		return a.x == b.x && a.y == b.y;
	}
};
node line[50];
vector<node>line1, line2;
long long int ans[50], target_x, target_y;
int _end, n;

void DFS(int sit, node now)
{
	if(sit > _end) {
		if(_end == n/2)line1.push_back(now);
		if(_end == n)line2.push_back(now);
		return ;
	}
	node temp = (node){ now.x + line[sit].x, now.y + line[sit].y , now.step + 1 };
	DFS(sit+1, temp);
	DFS(sit+1, now);
	return ;
}

int main()
{
	cin >> n;
	cin >> target_x >> target_y;
	for (int i = 1; i <= n; ++i) {
		cin >> line[i].x >> line[i].y;
	}
	_end = n/2;
	DFS(1, (node){0, 0, 0});
	_end = n;
	DFS(n/2+1, (node){0, 0, 0});
	sort(line1.begin(), line1.end());
	sort(line2.begin(), line2.end());

	long long int line1_k[25], line2_k[25];
	int len1 = line1.size(), len2 = line2.size();
	int i = 0, j = len2-1;
	while(i < len1 && j >= 0){
		if(line1[i].x + line2[j].x < target_x || (line1[i].x + line2[j].x == target_x && line1[i].y + line2[j].y < target_y))
			i++;
		else if(line1[i].x + line2[j].x > target_x || (line1[i].x + line2[j].x == target_x && line1[i].y + line2[j].y > target_y))
			j--;
		else {
			memset(line1_k, 0, sizeof(line1_k));
			memset(line2_k, 0, sizeof(line2_k));
			int t;
			for(t = i; t < len1 && line1[i] == line1[t]; t++)
				line1_k[line1[t].step]++;
			i = t;
			for(t = j; t >= 0 && line2[j] == line2[t]; t--)
				line2_k[line2[t].step]++;
			j = t;

			for(int a=0; a<=20; a++)
				for(int b=0; b<=20; b++)
					ans[a+b] += 1LL * line1_k[a] * line2_k[b];
		}
	}

	for (i = 1; i <= n; ++i) 
		cout << ans[i] << '\n';

	return 0;
}
