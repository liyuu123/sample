//��չŷ������㷨
#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y)//����gcdֵ����;����x,y 
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int	r=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
//����չŷ����ý�ģ���Է��� ax ��b(modn)
bool modularLinearEquation(int a,int b,int n)
{
	int x,y,x0,i;
	int d=exgcd(a,n,x,y);//ax ��b(modn)�ȼ���ax+ny=b
	
	if(b%d)return false;
	
	x0=x*(b/d)%n;
	for(i=1;i<=d;i++) printf("%d\n",(x0+i*(n/d))%n);
	return true;
}
int main()
{
	int a,n;
	while(cin>>a>>n)
	{
		modularLinearEquation(a,1,n);
	}
	return 0;
}
/*
exgcd��֤���� 
1.gcd(a,b)=gcd(b,a%b);
2.gcd(a,0)=a;
3.ax+by=c=gcd(a,b);
-->
4.ax+by=gcd(a,b)=gcd(b,a%b)=bx'+(a%b)y';
--> 
5.bx'+(a%b)y'=bx'+[a-(a/b)*b]y'=ay'+b[x'-(a/b)y'];
-->
����1��(1)x=y',y=x'-(a/b)y';
	   (2)y'=0ʱ,x'=1; 
*/
