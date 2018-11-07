//luogu P3372
#include<bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;
ll read(){
	ll x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int write[25];
#define m(a) memset(a,0,sizeof(a))
void wr(ll x){
	m(write);int ctt=0;
	if(x<0)x=-x,putchar('-');
	for(;x;x/=10)write[++ctt]=x%10;
	if(!ctt)write[++ctt]=0;
	while(ctt)putchar(write[ctt--]+'0');
}
#define maxn 100005
int n,k,m,t,x,y,z;
ll a[maxn],sum[maxn],lz[maxn];
void add(int l,int r,int w){
	int ld=(l-1)/k+1,rd=(r-1)/k+1;
	if(ld==rd){
		for(ri i=l;i<=r;i++){
			a[i]+=w;sum[ld]+=w;
		}
		return;
	}
	int srt1=k*(ld-1)+1;
	int srt2=k*(rd-1)+1;
	for(ri i=l;i<=srt1+k-1;i++)a[i]+=w,sum[ld]+=w;
	for(ri i=srt2;i<=r;i++)a[i]+=w,sum[rd]+=w;
	for(ri i=ld+1;i<rd;i++)lz[i]+=w,sum[i]+=w*k;
}
ll query(int l,int r){
	ll ans=0;
	int ld=(l-1)/k+1,rd=(r-1)/k+1;
	if(ld==rd){
		if(lz[ld]){
			for(ri i=(ld-1)*k+1;i<=ld*k;i++){
				a[i]+=lz[ld];
			}lz[ld]=0;
		}
		for(ri i=x;i<=y;i++)ans+=a[i];
		return ans;
	}
	int srt1=k*(ld-1)+1;
	int srt2=k*(rd-1)+1;
	if(lz[ld])
		for(ri i=srt1;i<=srt1+k-1;i++){
			a[i]+=lz[ld];
		}lz[ld]=0;
	if(lz[rd])
		for(ri i=srt2;i<=srt2+k-1;i++){
			a[i]+=lz[rd];
		}lz[rd]=0;
	for(ri i=l;i<=srt1+k-1;i++)ans+=a[i];
	for(ri i=srt2;i<=r;i++)ans+=a[i];
	for(ri i=ld+1;i<rd;i++)ans+=sum[i];
	return ans;
}
int main(){
	n=read();m=read();k=sqrt(n);
	for(ri i=1;i<=n;i++){
		a[i]=read();sum[(i-1)/k+1]+=a[i];
	}
	for(ri i=1;i<=m;i++){
		t=read();x=read();y=read();
		if(t==1)add(x,y,read());
		else {
			wr(query(x,y));putchar('\n');
		}
	}
}
