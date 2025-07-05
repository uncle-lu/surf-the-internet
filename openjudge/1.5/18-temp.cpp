#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
  int a;
  double d,b,c;
  cin>>a;
  cin>>b;
  cin>>c;
  d=c/b;
  for(int i=1;i<=a-1;i=i+1)
  {
      cin>>b;
      cin>>c;
      if(c/b-d>0.05)
      {
        cout<<"better"<<endl;
      }
      else if(d-b/c>0.05)
      {
        cout<<"worse"<<endl;
      }
      else
      {
        cout<<"same"<<endl;
      }
  }
  return 0;
}
