//HDU1754-�߶���ģ��<I hate it>(�������ֵ)������ʤ
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define N 200001
using namespace std;

int num[N];
struct Tree
{
    int l;    //��˵� 
    int r;    //�Ҷ˵� 
    int Max;  //���� 
}tree[N*4];   //���߶γ���ΪN���������飬һ�㿪��N��4�� 

void build(int root,int l,int r)  //�����߶�����rootΪ���ڵ㣬��������Ϊ[l,r] 
{
    tree[root].l=l;
    tree[root].r=r;
    if(tree[root].l==tree[root].r)  //�����Ҷ˵����ʱ����Ҷ�ӽڵ� 
    {
  	    tree[root].Max=num[l];      //����ֵ 
	    return;                     //�ݹ���� 
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);           //root<<1 �൱��root*2 ������������ 
    build(root<<1|1,mid+1,r);       //root<<1|1 �൱��root*2+1 ���������Һ��� 
    tree[root].Max=max(tree[root<<1].Max,tree[root<<1|1].Max);  //���׵�Max=max(���ӵ�Max,�Һ��ӵ�Max)
}

void update(int root,int pos,int val)  //���£�root�Ǹ��ڵ㣬pos��val��ʾ����pos���ֵ����Ϊval 
{
    if(tree[root].l==tree[root].r)     //�����Ҷ�ӽڵ㣬����pos��Ӧ��λ�� 
    {
  	    tree[root].Max=val;            //���²��� 
	    return;                        //�ݹ���� 
    }
    int mid=(tree[root].l+tree[root].r)/2;
    if(pos<=mid)                              //���pos����root��Ӧ������ 
        update(root<<1,pos,val);              //������������ 
    else
        update(root<<1|1,pos,val);            //���Һ���������
    tree[root].Max=max(tree[root<<1].Max,tree[root<<1|1].Max);  //���׵�Max=max(���ӵ�Max,�Һ��ӵ�Max)
}
	
int query(int root,int L,int R)              //��ѯ��rootΪ���ڵ㣬[L,R]��ʾҪ��ѯ������ 
{
    if(L<=tree[root].l && R>=tree[root].r)   //���Ҫ��ѯ������[L,R]����root�ڵ��ʾ������ 
	    return tree[root].Max;               //ֱ�ӷ���root�ڵ��Maxֵ 
    int mid=(tree[root].l+tree[root].r)/2;   
	int ret1=0,ret2=0;
    if(L<=mid) ret1=query(root<<1,L,R);     //��ѯroot�ڵ������ 
    if(R>mid)  ret2=query(root<<1|1,L,R);   //��ѯroot�ڵ���Һ���               
    return max(ret1,ret2);                  //�������������нϴ�ֵ 
}	

int main()
{
    //freopen("hdu1754.in","r",stdin);
    //freopen("hdu1754.out","w",stdout);	
    
    int n,m,a,b;
    char str[2];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
		for(int i=1;i<=n;i++) 
           scanf("%d",&num[i]);    //��ѧ��i�ĳɼ� 
        build(1,1,n);              //�Ӹ��ڵ�1��ʼ�����߶���������[1,n] 
        while(m--)
        {
        	scanf("%s%d%d",str,&a,&b);
        	if(str[0]=='Q')
        	{
        	    if(a>b) swap(a,b);             //��ѯ����[a,b] 
        	    printf("%d\n",query(1,a,b));   //�����ѯ��� 
			}
			else  update(1,a,b);               //����a���ֵΪb
        }
    }     
	return 0;
}
