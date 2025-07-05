#include<cstdio>

int main(){
	int n,cut=0,mx=0,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		if(x>=90&&x<=140&&y>=60&&y<=90){
			cut++;
			if(mx<cut){
				mx=cut;
			}
		}
		else{
			cut=0;
		}
	} 
	printf("%d",mx);
	return 0;
}
