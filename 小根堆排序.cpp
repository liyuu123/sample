#include<bits/stdc++.h>
#define ll long long
#define m(a) memset(a,0,sizeof(a))
#define mm(a) memset(a,true,sizeof(a))
#define mmm(a) memset(a,127,sizeof(a))
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
priority_queue<int,vector<int>,greater<int> >q;
//大根堆：priority_queue<int,vector<int>,less<int> >q;
//还可以用结构体（内operator定义）：priority_queue<node>q; 
int x;
int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		x=read();q.push(x);
	}
	int tmp;
	while(!q.empty()){
		tmp=q.top();
		q.pop();
		cout<<tmp<<" ";
	}
}
