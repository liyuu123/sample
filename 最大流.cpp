#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
#define maxn 10005
#define maxm 200005
int nxt[maxm],to[maxm],len[maxm];
int fst[maxn],dep[maxn];
bool vis[maxn];
int n,m,s,t,x,y,z;
ll ans=0;
int tot=1;
inline void inser(int x,int y,int z){
	nxt[++tot]=fst[x];
	fst[x]=tot;
	to[tot]=y;
	len[tot]=z;
}

inline bool bfs(){
	memset(dep,0,sizeof(dep));
	queue<int> q;while(!q.empty())q.pop();
	dep[s]=1;q.push(s);
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
	if(dep[t])return 1;
	return 0;
}
int dfs(int x,int w){
	if(x==t)return w;
	for(int u=fst[x];u;u=nxt[u]){
		int v=to[u];
		if(len[u]&&dep[v]==dep[x]+1){
			int tmp=dfs(v,min(w,len[u]));
			if(tmp<=0)continue;
			len[u]-=tmp;
			len[u^1]+=tmp;
			return tmp;
		}
	}return 0;
}

int main(){
	n=read();m=read();s=read();t=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();z=read();
		inser(x,y,z);inser(y,x,0);
	}dep[s]=1;
	while(bfs()!=0){
		for(int tmp=dfs(s,1e9);tmp;tmp=dfs(s,1e9))
			ans+=tmp;
	}cout<<ans<<endl;
}
