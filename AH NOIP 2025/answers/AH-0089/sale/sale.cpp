#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5005+5,MOD=998244353;
LL n,m,C,T,ba[N];
struct E{
	LL x,l,id;
}d[N];
struct S{
	LL x,id;
}a[N];
bool cmp2(E x,E y)
{
	if(x.x*y.l!=x.l*y.x)return x.x*y.l<x.l*y.x;
	else if(x.x!=y.x)return x.x<y.x;
	else return x.id<y.id;
}
bool cmp(S x,S y)
{
	if(x.x!=y.x)return x.x<y.x;
	else return x.id<y.id;
}
LL powmod(LL a,LL x)
{
	LL ans=1,tmp=0;
	while(x)
	{
		if(tmp==0)tmp=a;
		else tmp=(tmp*tmp)%MOD;
		if(x&1)ans=(ans*tmp)%MOD;
		x>>=1;
	}
	return ans;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		bool b=1;
		memset(d,0,sizeof(d));memset(a,0,sizeof(a));memset(ba,0,sizeof(ba));//memset(baid,0,sizeof(baid));
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i].x);a[i].id=i;
			if(i>1)
			{
				if(a[i].x!=a[i-1].x)b=0;
			}
		}
		if(b)
		{
			//cout<<"a\n";
			printf("%lld\n",powmod(2,n));
		}
		else if(m==2&&((C>=7&&C<=9)||(C>=14&&C<=15)))
		{
			LL ans=0;
			//cout<<"b\n";
			sort(a+1,a+n+1,cmp);
			for(int ff=n;ff>=1;ff--)
			{
				LL x=a[ff].x,y;
				if(ff==n)
				{
					y=a[n-1].x;
					//if(x==y)continue;
				}
				else
				{
					y=a[n].x;
					if(2*x<=y)
					{
						break;
					}
				}
				for(int i=min(ff-1,int(n-2));i>=1;i--)
				{
					LL p=a[i].x;
					if(x+p<y)
					{
						ans=(ans+powmod(2,i-1))%MOD;
					}
				}
			}printf("%lld\n",(powmod(2,n)+MOD-ans)%MOD);	
		}
		else
		{
			LL ans=0;
			for(int t=0;t<=((1<<n)-1);t++)
			{
				bool tmp=1;
				for(int i=1;i<=n;i++)
				{
					LL g=(1<<(i-1));
					d[i].x=a[i].x;d[i].l=((g&t)?2:1);d[i].id=i;
				}
				sort(d+1,d+n+1,cmp2);
				LL tm=m,pre=0;//preid=0;
				for(int i=1;i<=n;i++)
				{
					//cout<<" "<<t<<" "<<d[i].x<<" "<<d[i].l<<" "<<d[i].id<<endl;
					ba[i]=ba[i-1];
					if(d[i].l==1)ba[i]=d[i].x;
				}
				for(int i=n;i>=1;i--)
				{
					if(tm==0)break;
					if(tm<d[i].l)
					{
						if((pre==0)||((pre+ba[i])>=d[i].x)){//ba[i]==0||(pre==0&&ba[i]==0)||
							//cout<<t<<" "<<i<<" "<<pre<<" "<<ba[i]<<endl;
							break;
						}
						else 
						{tmp=0;break;}
					}
					tm-=d[i].l;
					if(d[i].l==1)pre=d[i].x;//,preid=d[i].id;
				}
				if(!tmp);//cout<<"false:"<<t<<endl;
				else ans++;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
