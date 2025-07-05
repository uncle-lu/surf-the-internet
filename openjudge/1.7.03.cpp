#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;
char line1[510], line2[510];
int len,cnt;
double k;
int main()
{
  scanf("%lf%s%s",&k, line1, line2);
  len=strlen(line1);
  for(int i=0;i<len;i++)
  {
    if(line1[i]==line2[i])
    {
      cnt++;
    }
  }
  if((double)cnt/(double)len>=k)
  {
    cout << "yes";
  }
  else
  {
    cout << "no";
  }
  return 0;
}
