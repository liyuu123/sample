//SOJ P429 ²İµØÅÅË® 
#include<bits/stdc++.h>
#define ll long long
#define iv inline void
using namespace std;
int read(){
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n,m,x,y,z;
#define maxn 20005
#define maxm 800005
int tot=1;
int nxt[maxm],to[maxm],len[maxm];
int dep[maxn],fst[maxn];
ll ans=0;
iv inser(int x,int y,int z){
	nxt[++tot]=fst[x];
	fst[x]=tot;
	to[tot]=y;
	len[tot]=z;
}
queue<int>q;
bool bfs(){
	memset(dep,0,sizeof(dep));
	while(!q.empty())q.pop();
	q.push(1);dep[1]=1;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int u=fst[x];u;u=nxt[u]){
			int v=to[u];
			if(len[u]&&!dep[v]){
				dep[v]=dep[x]+1;
				q.push(v);
			}
		}
	}
	if(dep[n])return 1;
	return 0;
}
int dfs(int x,int w){
	if(x==n)return w;
	for(int u=fst[x];u;u=nxt[u]){
		int v=to[u];
		if(!len[u]||dep[v]!=dep[x]+1)continue;
		int tmp=dfs(v,min(w,len[u]));
		if(tmp>0){
			len[u]-=tmp;
			len[u^1]+=tmp;
			return tmp;
		}
	}return 0;
}

int main(){
	m=read();n=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();z=read();
		inser(x,y,z);inser(y,x,0);
	}int d;
	while(bfs()){
		while(d=dfs(1,1e9))ans+=d;
	}cout<<ans<<endl;
}
