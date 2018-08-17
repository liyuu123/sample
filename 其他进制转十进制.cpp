#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
int n,m;
char s[55];
inline int check(char x){
	if(isdigit(x))return x-'0';
	else return x-55;
}
int main()
{
	n=read();
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		m=check(s[i])+n*m;
	}
	cout<<m;
} 
