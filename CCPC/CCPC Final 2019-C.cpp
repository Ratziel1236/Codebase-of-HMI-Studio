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
#define pr pair<ll,ll>
#define prpr make_pair
#define ll long long
#define opr operator
#define reg register
#define gc getchar
#define pc putchar
#define ret return
#define cst const
#define db double
#define il inline
il ll rd()
{
	reg ll res=0,lab=1;
	reg char ch=gc();
	while((ch<'0'||ch>'9')&&ch!=EOF){if(ch=='-')lab=-lab;ch=gc();}
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch&15),ch=gc();
	ret res*lab;
}
il void prt(ll x,char t='\n')
{
	static char ch[70];int tp=0;
	if(!x){fputs("0",stdout);if(t)pc(t);ret;}
	if(x<0)pc('-'),x=-x;
	while(x)ch[++tp]=(x%10)^48,x/=10;
	while(tp)pc(ch[tp--]);
	if(t)pc(t);
}
il ll umax(ll a,ll b){return a>b?a:b;}
il ll umin(ll a,ll b){return a<b?a:b;}
il ll tomax(ll&a,ll b){return a>b?a:(a=b);}
il ll tomin(ll&a,ll b){return a<b?a:(a=b);}
il ll uabs(ll x){return x>0?x:-x;}
il ll qpow(ll n,ll e=HgS-2,ll p=HgS)
{
	n%=p;reg ll res=1;
	while(e){if(e&1)res=res*n%p;n=n*n%p;e>>=1;}
	ret res;
}
ll T,n,x,y,z,s[5005],ls[5005][5005],pre[5005][5005],f[5005][5005];
il ll work()
{
	n=rd();x=rd();y=rd();z=rd();
	memset(ls,0,sizeof(ls));memset(pre,0,sizeof(pre));memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;++i)s[i]=rd();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			ls[i][j]=(s[i]^s[j])?0:ls[i-1][j-1]+1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=i;++j)
			pre[i][umin(i-j,ls[i][j])]=j;
		for(int j=i-1;j>=1;--j)
			tomax(pre[i][j],pre[i][j+1]);
	}
	f[1][0]=x;
	for(int i=2;i<=n;++i)
	{
		tomin(f[i][0],f[i-1][0]+x);
		for(int j=1;j<=i;++j)
		{
			if(!pre[i][j])continue;
			tomin(f[i][j],f[i-j][0]+y+z);
			tomin(f[i][j],f[pre[i][j]][j]+x*(i-j-pre[i][j])+z);
			tomin(f[i][0],f[i][j]);
		}
	}
	ret f[n][0];
}
int main()
{
	T=rd();
	for(int cas=1;cas<=T;++cas)printf("Case #%d: %lld\n",cas,work());
	ret 0;
}
