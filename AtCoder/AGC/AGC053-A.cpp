#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
#include<cstdio>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define neinf 0xc0c0c0c0c0c0c0c0ll
#define inf 0x3f3f3f3f3f3f3f3fll
#define uint unsigned int
#define ull unsigned ll
#define ll long long
#define reg register
#define db double
#define il inline
#define gc getchar
#define pc putchar
#define HgS 1000000007
il ll rd()
{
	reg ll res=0,lab=1;
	reg char ch=gc();
	while((ch<'0'||ch>'9')&&ch!=EOF)
	{if(ch=='-')lab=-lab;ch=gc();}
	while(ch>='0'&&ch<='9')
		res=(res<<3)+(res<<1)+(ch&15),ch=gc();
	return res*lab;
}
il void prt(ll x,char t='\n')
{
	char ch[70];int tp=0;
	if(!x){fputs("0",stdout);if(t)pc(t);return;}
	if(x<0)pc('-'),x=-x;
	while(x)ch[++tp]=(x%10)^48,x/=10;
	while(tp)pc(ch[tp--]);
	if(t)pc(t);
}
il ll umax(ll a,ll b){return a>b?a:b;}
il ll umin(ll a,ll b){return a<b?a:b;}
il bool cmp(ll a,ll b,char op){return op=='<'?a<b:a>b;}
ll n,a[105],t[105],k,tmp=0;string s;
/*il bool judge()
{
	for(int i=0;i<=n;++i)if(a[i]<0)return 0;
	for(int i=0;i<n;++i)if(!cmp(a[i],a[i+1],s[i]))return 0;
	return 1;
}*/
il bool work(ll x)
{
	for(int i=0;i<n;++i)
	{
		if(a[i]%x==a[i+1]%x)continue;
		//if(s[i]=='<'&&(a[i]/x+(a[i]%x>0)>=a[i+1]/x+(a[i+1]%x>a[i]%x))||s[i]=='>'&&(a[i+1]/x+(a[i+1]%x>0)>=a[i]/x+(a[i]%x>a[i+1]%x)))return 0;
		if(s[i]=='<')
		{
			if(a[i]%x>a[i+1]%x){if(a[i]/x+1>=a[i+1]/x)return 0;}
			else {if(a[i]/x==a[i+1]/x)return 0;}
		}
		else
		{
			if(a[i]%x<a[i+1]%x){if(a[i]/x<=a[i+1]/x+1)return 0;}
			else {if(a[i]/x==a[i+1]/x)return 0;}
		}
	}
	return 1;
}
int main()
{
	n=rd();cin>>s;for(int i=0;i<=n;++i)a[i]=rd();
	/*for(int i=1;i<=n;++i)
		t[i]=(s[i-1]=='>'?t[i-1]-1:t[i-1]+1),tmp=umin(tmp,t[i]);
	for(int i=0;i<=n;++i)t[i]-=tmp;
	while(judge()){++k;for(int i=0;i<=n;++i)a[i]-=t[i];}
	for(int i=0;i<=n;++i)a[i]+=t[i];
	prt(k);
	for(int i=1;i<k;++i)
	{for(int j=0;j<=n;++j)prt(t[j],' ');puts("");}
	for(int i=0;i<=n;++i)prt(a[i],' ');
	puts("");*/
	reg ll l=1,r=10000,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(work(mid))l=mid+1,k=mid;
		else r=mid-1;
	}
	prt(k);
	for(int i=1;i<=k;++i)
	{
		for(int j=0;j<=n;++j)prt(a[j]/k+(a[j]%k>=i),' ');
		puts("");
	}
	return 0;
}
