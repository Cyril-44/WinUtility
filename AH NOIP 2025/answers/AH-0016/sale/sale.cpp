#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int> 
#define mkp make_pair()

inline int read()
{
	int x=0,r=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') r=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*r;
}

const int mo=998244353;

int n,m;
struct node
{
	double cos;
	int t,typ;
	int num;
} a[10005];
int re[5005][3];
int cnt1[10005],cnt2[10005];
int s[5005];
int p[5005];
int pre[5005];
int nxt[5005];

int qpow(int t,int x)
{
	int ans=1;
	while(x)
	{
		if(x%2) ans=ans*t%mo;
		t=t*t%mo;
		x/=2;
	}
	return ans;
}

int ni(int t)
{
	return qpow(t,mo-2);
}

int cmp(node a,node b)
{
	if(a.cos==b.cos)
	{
		if(s[a.t]==s[b.t]) return a.num<b.num;
		return s[a.t]>s[b.t];
	}
	return a.cos>b.cos;
}

int C(int x,int y)
{
	if(y>x) return 0;
	return pre[x]*nxt[y]%mo*nxt[x-y]%mo;
}

void work()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		int d=read();
		double u=d/2.0;
		a[i*2-1].cos=d;
		a[i*2-1].t=i;
		a[i*2-1].typ=1;
		a[i*2].cos=u;
		a[i*2].t=i;
		a[i*2].typ=2;
		a[i*2].num=i;
		a[i*2-1].num=i;
		s[i]=d;
		p[i]=d;
	}
	sort(p+1,p+n+1,greater<int>());
	sort(a+1,a+n*2+1,cmp);
	for(int i=1;i<=2*n;i++)
	{
		cnt1[i]=cnt1[i-1];
		cnt2[i]=cnt2[i-1];
		if(a[i].typ==1) cnt1[i]++;
		else
		{
			cnt1[i]--;
			cnt2[i]++;
		}
		re[a[i].t][a[i].typ]=i;
		//cout<<a[i].t<<' '<<a[i].typ<<' '<<a[i].cos<<endl;
	}
	int ans=0;
	//cout<<p[n]<<endl;
	for(int i=1;i<=n;i++)
	{
		int d=re[i][2];
		//cout<<d<<endl;
		int u=s[i];
		int d1=cnt1[d],d2=cnt2[d],d3=0;
		d2--;
		if(d1+d2+d2<m-1) continue;
		int dll=1;
		for(int j=d-1;j>=1;j--)
		{
			if(a[j].typ==2)
			{
				continue;
			}
			if(a[j].typ==1)
			{
				//cout<<i<<' '<<j<<endl;
				if(a[j].cos>=u) break;
				int u1=u-a[j].cos-1;
				int gt=0;
				d1--;
				if(u1>=p[n]) 
				{
					
					while(dll<=n&&p[dll]>u1) dll++;
					gt=n-dll+1;
					gt=qpow(2,gt);
					//cout<<i<<' '<<j<<' '<<gt<<endl;
				}
				else gt=1;
				//cout<<i<<' '<<j<<' '<<"GT:"<<gt<<endl;
				int s1=m-2-d3;
				if(s1<d2) break;
				//cout<<s1<<endl;
				int uy=s1-d2;
				//cout<<d2<<' '<<uy<<endl;
				//cout<<C(d2,uy)<<endl;
				gt=gt*C(d2+d1,uy)%mo;
				//cout<<gt<<endl;
				ans=(ans+gt)%mo;
				//cout<<i<<' '<<j<<' '<<gt<<' '<<ans<<endl;
			}
		}
		//cout<<endl;
	}
	ans=(-ans+mo)%mo;
	ans=(ans+qpow(2,n))%mo;
	printf("%lld\n",ans);
}

signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	pre[0]=1;
	for(int i=1;i<=5000;i++) pre[i]=pre[i-1]*i%mo;
	nxt[5000]=ni(pre[5000]);
	for(int i=4999;i>=0;i--) nxt[i]=nxt[i+1]*(i+1)%mo;
	int c,T=1;
	c=read();
	T=read();
	while(T--) work();
}
