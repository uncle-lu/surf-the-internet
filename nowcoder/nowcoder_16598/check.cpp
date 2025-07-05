#include<cstdio>
#include<cstdlib>
#include<algorithm>

int main()
{
	long long int cnt = 0;
	while(true)
	{
		system("./make_data > in");
		system("./H < in > H.out");
		system("./H-BAONI < in > H-BAONI.out");
		if(!system("diff ./H.out ./H-BAONI.out"))
		{
			printf("AC%lld\n", cnt);
			cnt++;
		}
		else
		{
			printf("WA\n");
			break;
		}
	}

	return 0;
}
