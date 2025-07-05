#include<iostream>
using namespace std;
int linea[110],lineb[110],cnta,cntb;
int main(){
	int n,na,nb,a,b;
	cin>>n>>na>>nb;
	for(int i=0;i<na;i++)  cin>>linea[i];
	for(int i=0;i<nb;i++)   cin>>lineb[i];
	for(int i=0;i<n;i++)   {
		a=linea[i%na];
		b=lineb[i%nb];
		if(a==0&&b==2||a==2&&b==5||a==5&&b==0)
			cnta++;
		if(b==0&&a==2||b==2&&a==5||b==5&&a==0)
			cntb++;
	}
	if(cnta>cntb)  cout <<"A";
	if(cnta<cntb)  cout<<"B";
	if(cnta==cntb)cout<<"draw";	
	return 0;
}
