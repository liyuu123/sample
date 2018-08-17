#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int f[1000005][23];
int n,k,p,l,r;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",&f[i][0]);

	for(int j=1;j<=log(n)/log(2);++j)
	  for(int i=1;i+(1<<j)-1<=n;++i)
	    f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);

	for(int i=1;i<=k;++i){
		scanf("%d%d",&l,&r);
		p=log(r-l+1)/log(2);
		cout<<max(f[l][p],f[r-(1<<p)+1][p])<<endl;
	}
	
	return 0;
}
