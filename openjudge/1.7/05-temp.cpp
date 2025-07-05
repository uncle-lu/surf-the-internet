#include<iostream> 
#include<cstring> 
#include<string>
#include<stdio.h>
using namespace std; 
char str[110], ans[110];
int main () 
{ 
  cin.getline(str,110) ;
  int len=strlen(str);
  char c;
  for(int i = 0; i <= len-1; i++)
  {
      c = str[i] + str[(i+1)%len];
      cout << c;
  }
}
