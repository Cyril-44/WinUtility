#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)/2)
int n,a[114514],sum[114514],lazy[114514],q;
bool isl[114514];
inline void pushup(int k)
{
	a[k]=max(a[k*2],a[k*2+1]);
}
inline void pushdown(int k)
{
	if(isl[k]==0)return;
	isl[k]=0;
	if(a[k*2]<lazy[k])a[k*2]=lazy[k];
	if(a[k*2+1]<lazy[k])a[k*2+1]=lazy[k];
	if(isl[k*2]==1)lazy[k*2]=max(lazy[k*2],lazy[k]);
	else lazy[k*2]=lazy[k];
	if(isl[k*2+1]==1)lazy[k*2+1]=max(lazy[k*2+1],lazy[k]);
	else lazy[k*2+1]=lazy[k];
	isl[k*2]=1;
	isl[k*2+1]=1;
}
inline void place(int k,int l,int r,int d,int ad)
{
	if(r<d||l>d)return;
	if(l==d&&r==d)
	{
		a[k]=ad;
		return;
	}
	pushdown(k);
	place(k*2,l,mid,d,ad);
	place(k*2+1,mid+1,r,d,ad);
	pushup(k);
}
inline void change(int k,int l,int r,int ll,int rr,int mx)
{
	if(r<ll||l>rr)return;
	if(ll<=l&&r<=rr)
	{
		a[k]=max(a[k],mx);
		if(isl[k]==1)lazy[k]=max(mx,lazy[k]);
		else lazy[k]=mx;
		isl[k]=1;
		return;
	}
	pushdown(k);
	change(k*2,l,mid,ll,rr,mx);
	change(k*2+1,mid+1,r,ll,rr,mx);
	pushup(k);
}
inline int query(int k,int l,int r,int ll,int rr)
{
	if(r<ll||l>rr)return 0;
	if(ll<=l&&r<=rr)
	{
		return a[k];
	}
	return max(query(k*2,l,mid,ll,rr),query(k*2+1,mid+1,r,ll,rr));
}
inline void write(unsigned long long k)
{
	if(k==0)return;
	write(k/10);
	putchar(k%10+'0');
}
signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		long long t;
		scanf("%lld",&t);
		sum[i]=sum[i-1]+t;
	}
	scanf("%lld",&q);
	for(int i=1;i<=q;++i)
	{
		int l,r;
		scanf("%lld%lld",&l,&r);
		//memset(a,0,sizeof a);
		int ans=0;
		for(int j=1;j<=n;++j)
		{
			int res=LONG_LONG_MIN;
			for(int len=l;len<=r;++len)
			{
				for(int k=1;k<=len;++k)
				{
					if(j-k+1+len-1<=n&&j-k>=0)
					{
						//printf("          %lld:%lld %lld\n",j,j-k+1,j-k+1+len-1);
						res=max(res,sum[j-k+1+len-1]-sum[j-k]);
					}
				}
			}
			//printf("1:%lld\n",res);
			ans=ans^(res*j);
		}
		if(ans<0)
		{
			unsigned long long aans=18446744073709551615;
			aans=aans-(unsigned long long)(-1*ans)+1;
			write(aans);
			puts("");
		}
		else printf("%lld\n",ans);
	}
	/*for(int i=1;i<=q;++i)
	{
		int l,r;
		scanf("%lld%lld",&l,&r);
		for(int i=1;i<=n*4;++i)a[i]=LONG_LONG_MIN;
		for(int i=1;i<=n*4;++i)lazy[i]=LONG_LONG_MIN;
		for(int i=1;i<=n*4;++i)isl[i]=0;
		for(int len=l;len<=r;++len)
		{
			for(int j=1;j<=n-len+1;++j)
			{
				change(1,1,n,j,j+len-1,sum[j+len-1]-sum[j-1]);
			}
			for(int i=1;i<=n;++i)
			{
				printf("%lld ",query(1,1,n,i,i));
			}
			puts("");
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			ans=ans^(i*query(1,1,n,i,i));
		}
		if(ans<0)
		{
			unsigned long long aans=18446744073709551615;
			aans=aans-(unsigned long long)(-1*ans)+1;
			write(aans);
			puts("");
		}
		else printf("%lld\n",ans);
	}*/
	return 0;
}
