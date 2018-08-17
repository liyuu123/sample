#include<bits/stdc++.h>
#define iv inline void
using namespace std;
int read(){
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
#define maxn 50005
int tr[maxn];
int T,n,x,y;
char s[15];
int lb(int x){
	return x&(-x);
}
iv update(int x,int w){
	while(x<=n){
		tr[x]+=w;
		x+=lb(x);
	}
}
int query(int x){
	int ans=0;
	while(x>0){
		ans+=tr[x];
		x-=lb(x);
	}
	return ans;
}

int main(){
	T=read();
	for(int t=1;t<=T;t++){
		cout<<"Case "<<t<<":"<<endl;
		memset(tr,0,sizeof(tr));
		n=read();
		for(int i=1;i<=n;i++){
			x=read();update(i,x);
		}
		scanf("%s",s);
		while(s[0]!='E'){
			x=read();y=read();
			if(s[0]=='A'){
				update(x,y);
			}
			else if(s[0]=='S'){
				update(x,-y);
			}
			else {
				cout<<query(y)-query(x-1)<<endl;
			}
			scanf("%s",s);
		}
	}
}
