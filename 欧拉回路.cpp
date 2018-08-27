//luogu P1341  ÎÞÐò×ÖÄ¸¶Ô 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n,x,y;
char s[5],ans[1005];
#define maxn 1005
int tot=0,num=0,sgn=0;
int a[maxn][maxn];
int du[maxn];
void dfs(int x){
	for(int i=1;i<=maxn;i++){
		if(a[x][i]){
			a[x][i]=0;a[i][x]=0;
			dfs(i);
		}
	}
	ans[tot--]=x;
}
int main(){
	n=read();tot=n;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		a[s[0]][s[1]]=1;a[s[1]][s[0]]=1;
		du[s[0]]++;du[s[1]]++;
	}
	for(int i=1;i<=maxn;i++){
		if(du[i]&1){
			num++;
			if(!sgn)sgn=i;
		}
	}
	if(num>2){
		cout<<"No Solution"<<endl;return 0;
	}
	if(!num)
		for(int i=1;i<=maxn;i++)
			if(du[i]){
				sgn=i;break;
			}
	dfs(sgn);
	printf("%s\n",ans);
}
