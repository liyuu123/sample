#include<bits/stdc++.h>
using namespace std;
char s[205];
int n,m,tot,x=0;
int a[205],b[205],c[500];

int main()
{
	memset(c,0,sizeof(c));
	
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)a[n-i]=s[i]-'0';
	scanf("%s",s);
	m=strlen(s);
	for(int i=0;i<m;i++)b[m-i]=s[i]-'0';
	
	tot=n+m;
	
	for(int i=1;i<=n;i++)
	{
		x=0;
		for(int j=1;j<=m;j++)
		{
			x=x+a[i]*b[j]+c[i+j-1];
         	c[i+j-1]=x%10;
         	x=x/10;
		}
		c[i+m]+=x;
	}
	while(tot>1&&c[tot]==0)tot--;
	for(int i=tot;i>=1;i--)cout<<c[i];
	cout<<endl;
	return 0;
}
