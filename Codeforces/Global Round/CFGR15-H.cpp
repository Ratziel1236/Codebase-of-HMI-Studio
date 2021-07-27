#include<algorithm>
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<bitset>
#include<cstdio>
#include<string>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define file(s) freopen(#s".in","r",stdin),freopen(#s".out","w",stdout)
#define clr(x) memset((x),0,sizeof(x))
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
#define pb push_back
#define gc getchar
#define pc putchar
#define ret return
#define sec second
#define fir first
#define cst const
#define db double
#define il inline
#define maxn 200
il ll rd()
{
	reg ll res=0,lab=1;
	reg char ch=gc();
	while((ch<'0'||ch>'9')&&ch!=EOF){if(ch=='-')lab=-lab;ch=gc();}
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch&15),ch=gc();
	ret res*lab;
}
il db rdf()
{
	db res=0,g=1;int lab=1;char ch=gc();
	while((ch<'0'||ch>'9')&&ch!=EOF)lab=lab^(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9')res=res*10+(ch&15),ch=gc();
	if(ch=='.')
	{
		ch=gc();
		while(ch>='0'&&ch<='9')g*=0.1,res+=g*(ch&15),ch=gc();
	}
	ret lab?res:-res;
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
il ll tomax(ll&a,ll b){ret a>b?a:(a=b);}
il ll tomin(ll&a,ll b){ret a<b?a:(a=b);}
il ll umax(ll a,ll b){return a>b?a:b;}
il ll umin(ll a,ll b){return a<b?a:b;}
il ll uabs(ll x){return x>0?x:-x;}
il ll sqr(ll x){return x*x;}
il ll qpow(ll n,ll e=HgS-2,ll p=HgS){n%=p;reg ll res=1;while(e){if(e&1)res=res*n%p;n=n*n%p;e>>=1;}ret res;}
cst ll ir=HgS-1;
struct cpx
{
	int r,i;
	cpx(ll a=0,ll b=0):r(a%HgS),i(b%HgS){}
	cpx opr+(cst cpx&_)cst{ret cpx(r+_.r,i+_.i);}
	cpx opr-(cst cpx&_)cst{ret cpx(r-_.r+HgS,i-_.i+HgS);}
	cpx opr*(cst cpx&_)cst{ret cpx((1ll*r*_.r+ir*i*_.i)%HgS,(1ll*r*_.i+1ll*i*_.r)%HgS);}
};
il cpx qpow(cpx n,ll e){reg cpx res(1);while(e){if(e&1)res=res*n;n=n*n;e>>=1;}ret res;}
ll query(ll dlt)
{
	vector<pr>v;
	for(int i=1;i<=maxn;++i)for(int j=dlt;j<=maxn;j+=dlt)v.pb(prpr(i,j));
	cout<<"? "<<v.size()<<endl;
	for(int i=0;i<(int)v.size();++i)cout<<v[i].fir<<' '<<v[i].sec<<' ';
	cout<<endl;ll cnt;cin>>cnt;ret cnt;
}
ll f[9];
int main()
{
	ll s=query(1),l=1,r=7,mid,res=0;
	while(l<=r)
	{
		mid=(l+r)>>1;ll t=query(1<<mid);f[mid]=t;
		if((t<<mid)==s)l=mid+1,res=mid;
		else r=mid-1;
	}
	ll h=uabs((f[res+1]<<1)-s/(1<<res));
	cout<<"! "<<((h+s/h-2)<<1)<<endl;
	ret 0;
}
