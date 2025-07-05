#include<cstdio>//uncle-lu
#include<cmath>
#include<cstdlib>
#include<algorithm>

struct node{
	int x,y;
};
node line[1010];
int n;

long long int check(int x, int y)
{
	long long int sum = 0;
	for(int i=1; i<=n; ++i)
		sum += abs(line[i].x - x) + abs(line[i].y - y);

	return sum;
}

int main()
{
	//freopen("in","r",stdin);
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t)
	{
		scanf("%d", &n);
		long long int sum_x = 0, sum_y = 0;
		int ans_x1 = -1, ans_x2 = -1, ans_y1 = -1, ans_y2 = -1;
		for(int i=1; i<=n; ++i)
		{
			scanf("%d %d", &line[i].x, &line[i].y);
			sum_x += line[i].x;
			sum_y += line[i].y;
		}
		if(sum_x % n == 0)
			ans_x1 = sum_x/n;
		else
		{
			ans_x1 = ceil((double)sum_x/n);
			ans_x2 = floor((double)sum_x/n);
		}

		if(sum_y % n == 0)
			ans_y1 = sum_y/n;
		else
		{
			ans_y1 = ceil((double)sum_y/n);
			ans_y2 = floor((double)sum_y/n);
		}

		int mx = check(ans_x1, ans_y1), cnt = 1;
		if(ans_x2 != -1)
		{
			long long int temp = check(ans_x2, ans_y1);
			if(temp == mx)
				cnt++;
			else if(temp < mx)
				mx = temp, cnt = 1;
		}
		if(ans_y2 != -1)
		{
			long long int temp = check(ans_x1, ans_y2);
			if(temp == mx)
				cnt++;
			else if(temp < mx)
				mx = temp, cnt = 1;
		}
		if(ans_x2 != -1 && ans_y2 != -1)
		{
			long long int temp = check(ans_x2, ans_y2);
			if(temp == mx)
				cnt++;
			else if(temp < mx)
				mx = temp, cnt = 1;
		}

		for(int i=1; i<=n; ++i)
		{
			if(line[i].x == ans_x1 && line[i].y == ans_y1)continue;
			if(line[i].x == ans_x1 && line[i].y == ans_y2)continue;
			if(line[i].x == ans_x2 && line[i].y == ans_y1)continue;
			if(line[i].x == ans_x2 && line[i].y == ans_y2)continue;
			long long int temp = check(line[i].x, line[i].y);
			if(temp == mx)
				cnt++;
			else if(temp < mx)
				mx = temp, cnt = 1;
		}

		printf("%d\n", cnt);
	}

	return 0;
}
