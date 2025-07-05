#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0x7f7f7f7f;
char maps[110][110];
int sum[110][110];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>maps[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(maps[i][j]-'0');

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=i;k<=n;k++){
				for(int l=j;l<=m;l++){
					int t=sum[i-1][j-1]+sum[k][l]-sum[k][j-1]-sum[i-1][l];
					if(t>=k){
                        printf("(%d, %d), (%d, %d)\n", i, j, k, l);
                        ans=min(ans,(k-i+1)*(l-j+1));
                    }
				}
			}
		}
	}
	cout<<(ans==0x7f7f7f7f?0:ans);
	return 0;
}