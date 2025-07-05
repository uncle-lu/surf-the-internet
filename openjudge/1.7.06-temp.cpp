#include<cstdio>
#include<cstring>
using namespace std;
char str[30];
int main(){
  scanf("%s",str);
  int len = strlen(str);
  int flag = 1;
  for(int i = 0;i<len;i++){
    if(str[0]>='0'&&str[0]<='9'){
      flag = 0;
      break;
    }
    if((str[i]>='A'&&str[i]>='Z')||(str[i]>='a'&&str[i]>='z')||(str[i]>='0'&&str[i]<='9')||(str[i] == '_')){
      flag += 0;
      }else{
      flag = 0;
      }
  }
    if(flag == 1){
      cout<<"yes";
      }else{
      cout<<"no";
    }
    return 0;
}
