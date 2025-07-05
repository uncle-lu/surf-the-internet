#include<cstdio>//uncle-lu
#include<algorithm>

const int N = 1e5 + 10;
int n, m, k;
int line_a_z[N], line_a_f[N], line_b_z[N], line_b_f[N];
int a_max, a_min=0x7f7f7f7f, b_max, b_min=0x7f7f7f7f;

bool cmp_2(int a, int b) { return a<b; }

bool check(int x)
{
	printf("x = %d\n", x);
	int cnt = 0;
	int curr = line_b_z[0];
	for(int i=1; i<=line_a_z[0]; ++i)
	{
		while(line_a_z[i] * line_b_z[curr] >= x && curr >= 1)
		{
			printf("%d * %d = %d curr = %d\n", line_a_z[i], line_b_z[curr], line_a_z[i] * line_b_z[curr], curr);
			curr--;
		}
		cnt += (line_b_z[0] - curr);
		printf("cnt %d\n", cnt);
	}

	printf("cnt %d\n", cnt);

	/*
	curr = 1;
	for(int i=1; i<=line_a_z[0]; ++i)
	{
		while(line_a_z[i] * line_b_f[curr] >= x && curr <= line_b_f[0])
			curr++;
		cnt += curr-1;
	}
	curr = 1;
	for(int i=1; i<=line_a_f[0]; ++i)
	{
		while(line_a_f[i] * line_b_z[curr] >= x && curr <= line_b_z[0])
			curr++;
		cnt += curr-1;
	}
	curr = line_b_f[0];
	for(int i=line_a_f[0]; i>=1; --i)
	{
		while(line_a_f[i] * line_b_f[curr] >= x && curr >= 1)
			curr--;
		cnt += (line_b_f[0] - curr);
	}
	*/

	return cnt >= k;
}

int main()
{
	freopen("in","r",stdin);
	scanf("%d %d %d", &n, &m, &k);
	for(int i=1; i<=n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		if(temp > 0)
			line_a_z[++line_a_z[0]] = temp, a_max = std::max(a_max, temp);
		else
			line_a_f[++line_a_f[0]] = temp, a_min = std::min(a_min, temp);
	}
	for(int i=1; i<=m; ++i)
	{
		int temp;
		scanf("%d", &temp);
		if(temp > 0)
			line_b_z[++line_b_z[0]] = temp, b_max = std::max(b_max, temp);
		else
			line_b_f[++line_b_f[0]] = temp, b_min = std::min(b_min, temp);
	}

	std::sort(line_a_z + 1, line_a_z + line_a_z[0] + 1, cmp_2);
	std::sort(line_a_f + 1, line_a_f + line_a_f[0] + 1, cmp_2);
	std::sort(line_b_z + 1, line_b_z + line_b_z[0] + 1, cmp_2);
	std::sort(line_b_f + 1, line_b_f + line_b_f[0] + 1, cmp_2);

	long long int l = std::min(a_max * b_min, a_min * b_max);
	long long int r = std::max(a_max * b_max, a_min * b_min);
	long long int ans;
	while( l < r )
	{
		long long int mid = (l + r) >> 1;
		if(check(mid))
			l = mid+1, ans = mid;
		else
			r = mid-1;
	}

	printf("%lld", ans);

	return 0;
}
