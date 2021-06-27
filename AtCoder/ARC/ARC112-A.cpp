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
#define HgS 1000000007
#define ll long long
#define reg register
#define opr operator
#define ret return
#define gc getchar
#define pc putchar
#define cst const
#define db double
#define il inline
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
	static char ch[40];reg int tp=0;
	if(!x){fputs("0",stdout);if(t)pc(t);return;}
	if(x<0)pc('-'),x=-x;
	while(x)ch[++tp]=(x%10)^48,x/=10;
	while(tp)pc(ch[tp--]);
	if(t)pc(t);
}
il ll umax(ll a,ll b){return a>b?a:b;}
il ll umin(ll a,ll b){return a<b?a:b;}
il ll uabs(ll x){return x>0?x:-x;}
il ll qpow(ll n,ll e=HgS-2,ll p=HgS)
{
	reg ll res=1;
	while(e){if(e&1)res=res*n%p;n=n*n%p;e>>=1;}
	return res;
}
ll T,L,R;
int main()
{
	T=rd();
	while(T --> 0)
	{
		L=rd();R=rd();
		if(2*L>R)prt(0);
		else prt((R-2*L+1)*(R-2*L+2)/2);
	}
	return 0;
}
