#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
    }
    return x;
}
struct suger
{
	int xi,ti;
}a[200005];
bool cmp(suger x,suger y)
{
	return x.xi*y.ti<y.xi*x.ti;
}
signed main()
{
	freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		a[i].xi=x;
		a[i].ti=1;
		a[i+n].xi=x+y;
		a[i+n].ti=2;
	}
	sort(a+1,a+2*n+1,cmp);
	int ans=0;
	for(int i=1;i<=2*n;i++)
	{
		if(m*a[i].ti<a[i].xi)
		break;
		if(a[i].ti==1)
		{
			m-=a[i].xi;
			ans++;
		}
		else
		{
			int q=m/a[i].xi;
			ans+=q*a[i].ti;
			m-=q*a[i].xi;
			if(m+a[i-1].xi>=a[i].xi)
			{
			    ans++;
			    m-=a[i].xi-a[i-1].xi;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
