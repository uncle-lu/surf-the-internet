#include<cstdio>

int main()
{
	int n;
	double mx, mi, temp;
	scanf("%d", &n);
	scanf("%lf", &temp);
	mx = temp;
	mi = temp;

	for(int i=1; i<n; ++i)
	{
		scanf("%lf", &temp);
		if(temp > mx)
			mx = temp;
		if(temp < mi)
			mi = temp;
	}

	printf("%.0lf", mx - mi);
	return 0;
}
