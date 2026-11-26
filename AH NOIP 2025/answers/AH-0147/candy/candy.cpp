#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,sum=0;
struct candy{ll x,y;}c[100005],c0[100005],cc[100005];
void merge1(ll l,ll r)
{
	if (l==r) return ;
	merge1(l,(l+r)>>1);
	merge1(((l+r)>>1)+1,r);
	for (ll i=l,j=l,k=((l+r)>>1)+1;i<=r;i++)
		if (j==((l+r)>>1)+1) cc[i]=c[k++];
		else if (k==r+1) cc[i]=c[j++];
		else
		{
			if (c[j].x+c[j].y<c[k].x+c[k].y) cc[i]=c[j++];
			else if (c[j].x+c[j].y>c[k].x+c[k].y) cc[i]=c[k++];
			else cc[i]=(c[j].x<=c[k].x)?c[j++]:c[k++];
		}
	for (ll i=l;i<=r;i++) c[i]=cc[i];
}
void merge2(ll l,ll r)
{
	if (l==r) return ;
	merge2(l,(l+r)>>1);
	merge2(((l+r)>>1)+1,r);
	for (ll i=l,j=l,k=((l+r)>>1)+1;i<=r;i++)
		if (j==((l+r)>>1)+1) cc[i]=c0[k++];
		else if (k==r+1) cc[i]=c0[j++];
		else cc[i]=(c0[j].x<=c0[k].x)?c0[j++]:c0[k++];
	for (ll i=l;i<=r;i++) c0[i]=cc[i];
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for (int i=1;i<=n;i++){scanf("%lld %lld",&c[i].x,&c[i].y);c0[i]=c[i];}
	merge1(1,n);merge2(1,n);
	ans=m/(c[1].x+c[1].y)*2+((m>=(c[1].x+m/(c[1].x+c[1].y)*(c[1].x+c[1].y)))?1ll:0ll);
	for (ll i=1;i<=n;i++)
	{
		if (c0[i].x>=c[1].x+c[1].y) break;
		sum+=c0[i].x;
		ans=max(ans,i+(m-sum)/(c[1].x+c[1].y)*2+((m>=sum+c[1].x+(m-sum)/(c[1].x+c[1].y)*(c[1].x+c[1].y))?1ll:0ll));
	}
	printf("%lld",ans);
	return 0;
}
