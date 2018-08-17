#include<bits/stdc++.h>
using namespace std;
char s[1000005],l[1000005];
int nxt[1000005];
int n,m;
inline void deal_l(){
	int t=0;
	for(int i=2;i<=m;i++){
		while(t&&l[i]!=l[t+1]){
			t=nxt[t];
		}
		if(l[i]==l[t+1])t++;
		nxt[i]=t;
	} 
}
inline void deal_s(){
	int t=0;
	for(int i=1;i<=n;i++){
		while(t&&s[i]!=l[t+1]){
			t=nxt[t];
		}
		if(s[i]==l[t+1])t++;
		if(t==m){
			cout<<i-m+1<<endl;
		}
	}
}

int main(){
	scanf("%s",s+1);
	scanf("%s",l+1);
	n=strlen(s+1);m=strlen(l+1);
	deal_l();
	deal_s();
	for(int i=1;i<=m;i++){
		cout<<nxt[i]<<" ";
	}
}
