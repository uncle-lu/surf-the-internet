#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
	int x, y;
	double val;
	friend bool operator<(const edge a, const edge b) {
		return a.val < b.val;
	}
};

const int N = 510;
int x[N], y[N], Fa[N];

double dis(int a, int b)
{
	return sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));
}

int find_father(int a)
{
	return Fa[a] == a ? a : Fa[a] = find_father(Fa[a]);
}

int main()
{
	int s, p;
	cin >> s >> p;
	vector<edge>line;
	for (int i = 1; i <= p; ++i) {
		cin >> x[i] >> y[i];
		Fa[i] = i;
		for (int j = 1; j < i; ++j) {
			line.push_back((edge){ i, j, dis(i, j) });
		}
	}

	sort(line.begin(), line.end());

	int cnt = 0;
	for(auto l : line)
	{
		int xx = find_father(l.x), yy = find_father(l.y);
		if(xx != yy)
		{
			Fa[yy] = xx;
			cnt++;
			if(cnt >= p - s)
			{
				printf("%.2lf", l.val);
				break;
			}
		}
	}

	return 0;
}
