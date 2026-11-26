#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long x,y;
}a[100005];
int n,j;
long long m,k,t,ans;
bool cmp(node x,node y)
{
	return x.x<y.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
		if (k==0) k=a[i].x+a[i].y;
		else if (a[i].x+a[i].y<k)
		{	
			k=a[i].x+a[i].y;
			t=a[i].y;
		}
	}
	sort (a+1,a+n+1,cmp);
	for (int i=1;i<=n && a[i].x*2<=k;i++)
	{
		if (m<a[i].x)
		{
			printf("%lld\n",ans);
			return 0;
		}
		ans++;
		m-=a[i].x;
		j=i;
	}
	ans+=m/k*2;
	m%=k;
	if (j<n && m>=a[j+1].x)
	{
		ans++;
		printf("%lld\n",ans);
		return 0;
	}
	int f=0;
	for (int i=1;i<=j;i++)
	{
		if (m>=a[i].y)
		{
			ans++;
			f=1;
			break;
		}
	}
	if (!f && m+a[j].x>=k) ans++;
	printf("%lld\n",ans);
	return 0;
}
