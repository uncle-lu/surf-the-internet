#include<iostream>
#include<cstring>
using namespace std;
char A[501],B[501];
int main()
{
	double x;
	scanf("%lf\n", &x);
	cin.getline(A,501);
	cin.getline(B,501);
	int len = strlen(A),cnt=0;
	for (int i=0;i<len;i++)
	{
		if(A[i]==B[i])cnt++;
	}
	if((double)cnt/len >=x)
		cout<<"yes";
	else
		cout<<"no";
	return 0;
}
