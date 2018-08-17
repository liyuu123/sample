#include<bits/stdc++.h>
#define ll long long
#define m(a) memset(a,0,sizeof(a))
using namespace std;
int read(){
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
queue<int> q;
int n,m,s,t;
ll ans;
int tot=1;
int nxt[2005],to[2005],len[2005];
int fst[1005],dep[1005]; 
bool sign,vis[1005];
void inser(int x,int y,int w){
	nxt[++tot]=fst[x];
	fst[x]=tot;
	to[tot]=y;
	len[tot]=w;
}
void bfs(int x){
	vis[x]=1;
	q.push(x);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(int u=fst[t];u;u=nxt[u]){
			if(len[u]&&!vis[to[u]]){
				dep[to[u]]=dep[t]+1;
				vis[to[u]]=1;
				q.push(to[u]);
			}
		}
	}
}
int dfs(int x,int delta){
	if(x==t)return delta;
	int ans=0;
	for(int u=fst[x];u;u=nxt[u]){
		if(len[u]&&dep[to[u]]==dep[x]+1){
			int minn=dfs(to[u],min(len[u],delta));
			len[u]-=minn;
			len[u^1]+=minn;
			ans+=minn;
		}
	}
	if(ans)return ans;
}
void clear(){
	ans=0;m(dep);m(vis);
	while(!q.empty()) q.pop();
}

int main(){
	int x,y,w;
	n=read();m=read();s=read();t=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();w=read();
		inser(x,y,w);inser(y,x,0);
	}
	clear();vis[t]=1;
	while(vis[t]){
		m(vis);
		bfs(s);
		ans+=dfs(s,1e+9);
	}
	cout<<ans<<endl;
}
