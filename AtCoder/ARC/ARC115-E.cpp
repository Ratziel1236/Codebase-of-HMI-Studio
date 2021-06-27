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
#define HgS 998244353
#define len 500000
#define lim (len*35)
#define mid ((l+r)>>1)
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
	reg char ch[70];reg int tp=0;
	if(x<=-HgS)pc('-'),x=-x;
	while(x)ch[++tp]=(x%10)^48,x/=10;
	if(!tp)ch[++tp]=48;
	while(tp)pc(ch[tp--]);
	if(t)pc(t);
}
il ll umax(ll a,ll b){return a>b?a:b;}
il ll umin(ll a,ll b){return a<b?a:b;}
ll n,a[len+5],maxa;
int rt,cnt;
int ls[lim+5],rs[lim+5],plz[lim+5],mlz[lim+5];
ll sum[lim+5];
il int newp()
{++cnt;ls[cnt]=rs[cnt]=plz[cnt]=sum[cnt]=0;mlz[cnt]=1;return cnt;}
il void pushup(int i)
{sum[i]=sum[ls[i]]+sum[rs[i]];if(sum[i]>HgS)sum[i]-=HgS;}
il void init(int i,int l,int r)
{
	if(l>r)return;
	sum[i]=plz[i]=0;
	mlz[i]=1;
	++cnt;
	if(l==r){sum[i]=a[l];return;}
	if(l<=mid)init((ls[i]=cnt+1),l,mid);
	if(r>mid)init((rs[i]=cnt+1),mid+1,r);
	pushup(i);
}
il void pushdown(int i,int l,int r)
{
	if(l==r)return;
	if(!ls[i])ls[i]=newp();
	if(!rs[i])rs[i]=newp();
	mlz[ls[i]]*=mlz[i];if(mlz[ls[i]]<=-HgS)mlz[ls[i]]+=HgS;
	mlz[rs[i]]*=mlz[i];if(mlz[rs[i]]<=-HgS)mlz[rs[i]]+=HgS;
	plz[ls[i]]=plz[ls[i]]*mlz[i]+plz[i];
	if(plz[ls[i]]<=-HgS)plz[ls[i]]+=HgS;
	if(plz[ls[i]]>=HgS)plz[ls[i]]-=HgS;
	plz[rs[i]]=plz[rs[i]]*mlz[i]+plz[i];
	if(plz[rs[i]]<=-HgS)plz[rs[i]]+=HgS;
	if(plz[rs[i]]>=HgS)plz[rs[i]]-=HgS;
	sum[ls[i]]=(sum[ls[i]]*mlz[i]+1ll*plz[i]*(mid-l+1))%HgS;
	sum[rs[i]]=(sum[rs[i]]*mlz[i]+1ll*plz[i]*(r-mid))%HgS;
	plz[i]=0;mlz[i]=1;
}
il void add(int i,int l,int r,int lt,int rt,int x)
{
	if(l>r)return;
	if(l>rt||r<lt)return;
	if(l>=lt&&r<=rt)
	{
		sum[i]=(sum[i]+1ll*x*(r-l+1)+HgS)%HgS;
		plz[i]+=x;
		if(plz[i]<=-HgS)plz[i]+=HgS;
		if(plz[i]>=HgS)plz[i]-=HgS;
		return;
	}
	pushdown(i,l,r);
	if(lt<=mid)
	{
		if(!ls[i])ls[i]=newp();
		add(ls[i],l,mid,lt,rt,x);
	}
	if(rt>mid)
	{
		if(!rs[i])rs[i]=newp();
		add(rs[i],mid+1,r,lt,rt,x);
	}
	pushup(i);
}
il void mul(int i,int l,int r,int lt,int rt,int x)
{
	if(l>r)return;
	if(l>rt||r<lt)return;
	if(l>=lt&&r<=rt)
	{
		sum[i]*=x;plz[i]*=x;mlz[i]*=x;
		return;
	}
	pushdown(i,l,r);
	if(lt<=mid)
	{
		if(!ls[i])ls[i]=newp();
		mul(ls[i],l,mid,lt,rt,x);
	}
	if(rt>mid)
	{
		if(!rs[i])rs[i]=newp();
		mul(rs[i],mid+1,r,lt,rt,x);
	}
	pushup(i);
}
il ll query(int i,int l,int r,int lt,int rt)
{
	if(l>r)return 0;
	if(l>rt||r<lt)return 0;
	if(l>=lt&&r<=rt)return sum[i];
	pushdown(i,l,r);
	ll s=0;
	if(lt<=mid)
	{
		if(!ls[i])ls[i]=newp();
		s+=query(ls[i],l,mid,lt,rt);
		if(s>=HgS)s-=HgS;
		if(s<=-HgS)s+=HgS;
	}
	if(rt>mid)
	{
		if(!rs[i])rs[i]=newp();
		s+=query(rs[i],mid+1,r,lt,rt);
		if(s>=HgS)s-=HgS;
		if(s<=-HgS)s+=HgS;
	}
	pushup(i);
	return s;
}
int main()
{
	n=rd();for(int i=1;i<=n;++i)a[i]=rd(),maxa=umax(a[i],maxa);
	rt=newp();
	add(1,1,maxa,1,a[1],1);
	for(int i=2;i<=n;++i)
	{
		if(a[i-1]<a[i])
		{
			int tmp=query(1,1,maxa,1,a[i-1])%HgS;
			mul(1,1,maxa,1,a[i-1],-1);
			add(1,1,maxa,1,a[i],tmp);
		}
		else
		{
			int tmp=query(1,1,maxa,1,a[i-1])%HgS;
			if(a[i-1]>a[i])mul(1,1,maxa,a[i]+1,a[i-1],0);
			mul(1,1,maxa,1,a[i],-1);
			add(1,1,maxa,1,a[i],tmp);
		}
	}
	prt(query(1,1,maxa,1,a[n]));
	return 0;
}
