#include<bits/stdc++.h>
#define ll long long
#define ri register int
using namespace std;
int read(){
    int x=0,f=1;char c;
    for(c=getchar();c<'0'||c>'9';c=getchar())if(c=='-')f=-1;
    for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
    return x*f;
}
int write[25];
#define m(a) memset(a,0,sizeof(a))
void wr(ll x){
    int ctt=0;m(write);
    if(x<0)x=-x,putchar('-');
    for(;x;x/=10)write[++ctt]=x%10;
    if(!ctt)write[++ctt]=0;
    while(ctt)putchar(write[ctt--]+'0');
}
#define maxn 10005
#define maxm 200005
int n,m,s,t,x,y,z,tmp;
int tot=1,ans=0;
int fst[maxn],dep[maxn];
int nxt[maxm],to[maxm],len[maxm];
void inser(int x,int y,int z){
	nxt[++tot]=fst[x];
	fst[x]=tot;
	to[tot]=y;
	len[tot]=z;
}
queue<int> q;
bool bfs(){
	while(!q.empty())q.pop();
	dep[s]=1;q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int u=fst[x];u;u=nxt[u]){
			int v=to[u];
			if(!dep[v]&&len[u]){
				dep[v]=dep[x]+1;
				q.push(v);
			}
		}
	}
	if(dep[t])return 1;
	return 0;
}
int dfs(int x,int w){
	if(x==t)return w;
	for(int u=fst[x];u;u=nxt[u]){
		int v=to[u];
		if(!len[u]||dep[v]!=dep[x]+1)continue;
		int num=dfs(v,min(w,len[u]));
		if(num>0){
			len[u]-=num;
			len[u^1]+=num;
			return num;
		}
	}return 0;
}

int main(){
	n=read();m=read();s=read();t=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();z=read();
		inser(x,y,z);inser(y,x,0);
	}
	while(bfs()){
		while((tmp=dfs(s,1e9+7)))ans+=tmp;
		m(dep);
	}
	wr(ans);
}
