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
#define uint unsigned int
#define HgS 1000000007
#define reg register
#define opr operator
#define ret return
#define gc getchar
#define pc putchar
#define cst const
#define db double
#define il inline
#define ll int
il ll rd()
{
	reg ll res=0,lab=1;reg char ch=gc();
	while((ch<'0'||ch>'9')&&ch!=EOF){if(ch=='-')lab=-lab;ch=gc();}
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch&15),ch=gc();
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
il db deg(db x,db y){return (!x&&!y)?0:atan2(y,x);}
il db dis(ll x,ll y){return sqrt(x*x+y*y);}
il ll dis2(ll x,ll y){return x*x+y*y;}
struct node
{
	ll x,y;
	bool opr<(cst node&_)cst
	{
		db dg1=deg(x,y),dg2=deg(_.x,_.y);
		ll d1=dis2(x,y),d2=dis2(_.x,_.y);
		return (d1==d2)?(dg1<dg2+1e-5):(d1<d2);
	}
}s[105],t[105],ss[105],tt[105];
il db deg(node x){return deg(x.x,x.y);}
il db dis(node x){return dis(x.x,x.y);}
il ll dis2(reg node x){return dis2(x.x,x.y);}
il bool eq0(reg db x){return x>=-1e-5&&x<=1e-5;}
ll n;
int main()
{
	n=rd();
	for(int i=1;i<=n;++i)s[i].x=rd(),s[i].y=rd();
	for(int i=1;i<=n;++i)t[i].x=rd(),t[i].y=rd();
	for(int j=1;j<=n;++j)
	{
		memcpy(tt,t,sizeof(t));
		for(int k=n;k>=1;--k)
			tt[k].x-=t[j].x,tt[k].y-=t[j].y;
		sort(tt+1,tt+1+n);
		for(int i=1;i<=n;++i)
		{
			memcpy(ss,s,sizeof(s));
			for(int k=n;k>=1;--k)
				ss[k].x-=s[i].x,ss[k].y-=s[i].y;
			for(int g=1;g<=4;++g)
			{
				sort(ss+1,ss+1+n);
				db dg=0;bool f=1,it=1;
				for(int i=1;i<=n;++i)
				{
					if(!dis2(ss[i])&&!dis2(tt[i]))continue;
					if(dis2(ss[i])!=dis2(tt[i])){f=0;break;}
					if(it)it=0,dg=deg(ss[i])-deg(tt[i]);
					else
					{
						db dg2=deg(ss[i])-deg(tt[i]);
						if(!eq0(dg2-dg)){f=0;break;}
					}
				}
				if(f){puts("Yes");return 0;}
				for(int k=1;g!=4&&k<=n;++k)
					swap(ss[k].x,ss[k].y),ss[k].y=-ss[k].y;
			}
		}
	}
	puts("No");
	return 0;
}
/*
3
1 3
4 1
3 0
1 0
0 4
-1 3
*/
