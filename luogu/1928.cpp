#include<cstdio>
#include<cstring>

char a[20010], b[20010];
int i, last, len;

void f()
{
	int cnt, last1 = last;
	if(a[i+1] <= '9' && a[i+1] >= '0')
	{
		cnt = (a[i] - '0') * 10 + (a[i+1] - '0');
		i = i + 2;
	}
	else
	{
		cnt = (a[i] - '0');
		i = i + 1;
	}
	for(; i<len; ++i)
	{
		if(a[i] == '[')
		{
			i++;
			f();
		}
		else if(a[i] == ']')
			break;
		else
		{
			b[last] = a[i];
			last++;
		}
	}
// last1 ~ last 翻cnt倍
	int begin = last1, end = last-1;
	for(int j=1; j<cnt; ++j)
	{
		for(int curr = begin; curr <= end; curr++)
		{
			b[last] = b[curr];
			last++;
		}
	}
	return ;
}

int main()
{
	scanf("%s", a);
	len = strlen(a);
	for(; i<len; ++i)
	{
		if(a[i] == '[')
		{
			i++;
			f();
		}
		else
		{
			b[last] = a[i];
			last++;
		}
	}

	printf("%s", b);
	return 0;
}
