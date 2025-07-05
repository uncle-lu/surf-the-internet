#include<cstdio>

int line_a[110], line_b[110];

int main()
{
	int n, na, nb;
	scanf("%d %d %d", &n, &na, &nb);
	for (int i = 0; i < na; ++i) {
		scanf("%d", &line_a[i]);
	}
	for (int i = 0; i < nb; ++i) {
		scanf("%d", &line_b[i]);
	}

	int sum_a = 0, sum_b = 0;
	for (int i = 0; i < n; ++i) {
		int a = line_a[i%na], b = line_b[i%nb];
		if(a == b)
		{
			sum_a++; sum_b++;
		}
		else if((a==0 && b==2) || (a==2 && b==5) || (a==5 && b==0))
			sum_a++;
		else
			sum_b++;
	}

	if(sum_a > sum_b)
		printf("A");
	else if(sum_a < sum_b)
		printf("B");
	else
		printf("draw");

	return 0;
}
