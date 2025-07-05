#include<cstdio>//uncle-lu
#include<cstring>
#include<algorithm>
 
int n, m;
char line_s[200010], line_t[200010];
int left[200010];
int right[200010];
 
int main()
{
	scanf("%d %d", &n, &m);
	scanf("%s\n%s", line_s, line_t);
	
	int sit_s = 0, sit_t = 0;
	while(sit_t < m)
	{
		if(line_s[sit_s] == line_t[sit_t])
		{
			left[sit_t] = sit_s;
			sit_t++;
		}
		sit_s++;
	}
 
	sit_s = n-1; sit_t = m-1;
	while(sit_t >= 0)
	{
		if(line_s[sit_s] == line_t[sit_t])
		{
			right[sit_t] = sit_s;
			sit_t--;
		}
		sit_s--;
	}
 
	int mx = 0;
	for(int i=0; i<m-1; ++i)
	{
		mx = std::max(mx, right[i+1] - left[i]);
	}
 
	printf("%d", mx);
 
	return 0;
}
