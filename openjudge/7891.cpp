#include<cstdio>
#include<algorithm>

double a,b,c,d;
double f(double A){
	double aba=A*A*A*a+A*A*b+A*c+d;
	return aba;
}

int main(){
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

	double x1,x2,xx;
	for(double i=-100;i<=100;++i)
	{
		x1=i;x2=i+1;
		if(f(x1)==0)printf("%.2lf ",x1);
		else if(f(x1)*f(x2)<0)
		{
			while(x2-x1>=0.001)
			{
				xx=(x1+x2)/2;
				if((f(x1)*f(xx))<=0)
					x2=xx;
				else
					x1=xx;
			}
			printf("%.2lf ",x1);
		}
	}
	return 0;
}
