#include<iostream>
using namespace std;
const int mod=1e9+7;
long long f[505][505],g[505][505],nxt[505];
int n,k;
bool x[505][505];
char s[505];
int main(){
	cin>>n>>k;
	scanf("%s",s+1);
	for(int l=1;l<=n;l++){
		if(s[l]!='?'&&s[l]!='*')continue;
		x[l][l]=1;
		for(int r=l+1;r<=n;r++){
			if(s[r]=='?'||s[r]=='*'){
				x[l][r]=1;
			}
			else break;
		}
	}
	
	for(int len=2;len<=n;len++){
		int r;
		for(int l=1;l<=n-len+1;l++){
			r=l+len-1;
			f[l][r]=g[l][r]=0;
			if((s[l]!='('&&s[l]!='?')||(s[r]!=')'&&s[r]!='?'))continue;
			if(l+1==r){
				f[l][r]=(f[l][r]+1)%mod;
				continue;
			}
			if(len-2<=k&&x[l+1][r-1]){
				f[l][r]=(f[l][r]+1)%mod;
			}
			f[l][r]=(f[l][r]+f[l+1][r-1]+g[l+1][r-1])%mod;
			for(int i=l+1;i<=min(r-2,l+k);i++){
				if(x[l+1][i]){
					f[l][r]=(f[l][r]+f[i+1][r-1]+g[i+1][r-1])%mod;
				}
			}
			for(int i=r-1;i>=max(l+2,r-k);i--){
				if(x[i][r-1]){
					f[l][r]=(f[l][r]+f[l+1][i-1]+g[l+1][i-1])%mod;
				}
			}
			int t=0;
			for(int i=l+1;i<=r-2;i++){
				if(t<=i)t=i+1;
				while((s[t]=='*'||s[t]=='?')&&t<r-1)t++;
				nxt[i]=min(i+k+1,t);
			}
			long long temp=0;
			for(int j=l+2;j<=nxt[l+1];j++){
				temp=(temp+f[j][r])%mod;
			}
			g[l][r]=(g[l][r]+(f[l][l+1]+g[l][l+1])*temp)%mod;
			for(int i=l+2;i<=r-2;i++){
				temp=(temp-f[i][r]+mod)%mod;
				for(int j=nxt[i-1]+1;j<=nxt[i];j++){
					temp=(temp+f[j][r])%mod;
				}
				g[l][r]=(g[l][r]+(f[l][i]+g[l][i])%mod*temp)%mod;
			}
		}
	}
	cout<<(f[1][n]+g[1][n])%mod<<endl;
	return 0;
}
