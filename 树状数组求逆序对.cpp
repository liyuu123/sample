#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n;
long long ans=0;
int a[100005],num[100005];
inline int lb(int x){
	return x&(-x);
}

int main()
{
	int x;
	n=read();
	for(int i=1;i<=n;i++){
		int tmp=0;
		a[i]=read();
		int j=a[i];
		for(;j<100005;j+=lb(j)){
			num[j]++;
		}
		for(;a[i]>0;a[i]-=lb(a[i]))tmp+=num[a[i]];
		ans+=i-tmp;
	}
	cout<<ans;
}
