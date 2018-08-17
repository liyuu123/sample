#include<bits/stdc++.h>
using namespace std;
int n,m;
int tot=0,num=0,ans=0;
struct node{
	int len,to,en;
	bool operator< (const node& a) const{
		return len<a.len;
	}
}ed[200005];
int f[200005];
int get_f(int x){
	return x==f[x]?x:f[x]=get_f(f[x]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		tot++;
		cin>>ed[tot].en>>ed[tot].to>>ed[tot].len;
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(ed+1,ed+m+1);
	for(int i=1;i<=m;i++){
		int px=get_f(ed[i].en);
		int py=get_f(ed[i].to);
		if(px!=py){
			f[px]=py;
			num++;ans+=ed[i].len;
		}
		if(num==n-1)break;
	}
	cout<<ans<<endl;
}
