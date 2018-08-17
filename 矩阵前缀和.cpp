#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n,m,r,c;
int ans;
int a[1005][1005],f[1005][1005];
int main(){
	n=read();m=read();
	r=read();c=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=read();
			f[i][j]=a[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
		}
	}
	for(int i=r;i<=n;i++){
		for(int j=c;j<=m;j++){
			ans=max(ans,f[i][j]-f[i-r][j]-f[i][j-c]+f[i-r][j-c]);
		}
	}
	cout<<ans;
}
