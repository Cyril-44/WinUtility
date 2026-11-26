#include<bits/stdc++.h>
#define int long long
const int p=998244353;
using namespace std;
int a[5005],mi[5005],b[5005],cd[5005],n,m,ca[1005][1005];
struct node
{
	int x,y;
}l[5005],r[5005];
bool cmp(node x,node y)
{
	if(x.x*y.y!=x.y*y.x)
	return x.x*y.y>x.y*y.x;
	return x.y>y.y;
}
int dfs(int x)
{
	if(x==0)
	{
		int ttm=m,i=1,card=0;
		for(int i=1;i<=n;i++)
		r[i]=l[i];
		sort(r+1,r+n+1,cmp);
		for(i=1;i<=n&&ttm>=2;i++)
		{
			ttm-=r[i].y;
			if(r[i].y==1)
			card=r[i].x;
		}
		if(ttm==0)
		return 1;
		if(ttm==1&&r[i].y==1)
		return 1;
		int xx=0;
		for(int j=i+1;j<=n;j++)
		if(r[j].y==1)
		{
			xx=r[j].x;
			break;
		}
		if(ttm==1&&card==0)
		return 1;
		if(xx+card<r[i].x)
		return 0;
		return 1;
	}
	int rt=0;
	l[x].y=1;
	rt+=dfs(x-1);
	l[x].y=2;
	rt+=dfs(x-1);
	return rt;
}
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	mi[0]=1;
	for(int i=1;i<=5002;i++)
	mi[i]=mi[i-1]*2%p;
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ca[1][0]=ca[1][1]=1;;
	    for(int i=2;i<=1001;i++)
	    for(int j=0;j<=i;j++)
	    if(!j)
	    ca[i][j]=0;
	    else
	    ca[i][j]=(ca[i-1][j-1]+ca[i-1][j])%p;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
		if(c==16||c==18)
		{
		    printf("%lld\n",mi[n]);
		    continue;
		}
		else
		if(c==17)
		{
			sort(a+1,a+n+1);
			if(a[1]*2<a[2]||a[1]==a[2])
			printf("%lld\n",mi[n]);
			else
			printf("%lld\n",(mi[n]-1+p)%p);
			continue;
		}
		else
		if((7<=c&&c<=9)||(14<=c&&c<=15))
		{
			sort(a+1,a+n+1);
			int ans=0;
			ans+=mi[n];
			ans%=p;
			int maxn=a[n],bn=0,cm=0;
			for(int i=1;i<=n-1;i++)
			{
				if(a[i]*2<=maxn)
				b[++bn]=a[i];
				else
				cd[++cm]=a[i];
			}
			int js=bn;
			for(int i=1;i<=cm;i++)
			{
				while(cd[i]+b[js]>=maxn)
				js--;
				if(js==bn)
				continue;
				int nump=js;
				ans=(ans-mi[nump]%p+p)%p;
			}
			cout<<ans<<endl;
		}
		else
		if(1<=c&&c<=5)
		{
			memset(l,0,sizeof(l));
			for(int i=1;i<=n;i++)
			l[i].x=a[i];
			cout<<dfs(n)<<endl;
		}
		else
		if((10<=c&&c<=12)||(19<=c&&c<=20))
		{
			int ans=0;
			if(m%2==0)
			{
				for(int i=0;i<=n;i+=2)
				ans+=ca[n][i]-1;
				ans%=p;
			}
			else
			{
				for(int i=1;i<=n;i+=2)
				ans+=ca[n][i]-1;
				ans%=p;
			}
			cout<<ans<<endl;
		}
	}
}
