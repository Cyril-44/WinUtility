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

int n;
int a[3005];
int ans[3005][3005];
int tr[3005][12005];
int maxx[12005];

void update(int p,int l,int r,int g,int k)
{
	if(l==r)
	{
		maxx[p]=k;
		return;
	}
	int mid=(l+r)>>1;
	if(g<=mid) update(p<<1,l,mid,g,k);
	else update(p<<1|1,mid+1,r,g,k);
	maxx[p]=max(maxx[p<<1],maxx[p<<1|1]);
}

int query(int p,int l,int r,int nl,int nr)
{
	if(nl<=l&&nr>=r) return maxx[p];
	int mid=(l+r)>>1;
	int ans=-0x3f3f3f3f;
	if(nl<=mid) ans=max(ans,query(p<<1,l,mid,nl,nr));
	if(nr>=mid+1) ans=max(ans,query(p<<1|1,mid+1,r,nl,nr));
	return ans;
}

void build(int p,int l,int r,int d)
{
	if(l==r)
	{
		tr[d][p]=ans[d][l];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid,d);
	build(p<<1|1,mid+1,r,d);
	tr[d][p]=max(tr[d][p<<1],tr[d][p<<1|1]);
	//cout<<d<<' '<<p<<' '<<tr[d][p]<<endl;
}

int query1(int p,int l,int r,int nl,int nr,int d)
{
	if(nl<=l&&nr>=r) return tr[d][p];
	int mid=(l+r)>>1;
	int ans=-0x3f3f3f3f3f3f3f3f;
	if(nl<=mid) ans=max(ans,query1(p<<1,l,mid,nl,nr,d));
	if(nr>=mid+1) ans=max(ans,query1(p<<1|1,mid+1,r,nl,nr,d));
	return ans;
}

void write(unsigned int t)
{
	if(t>=10) write(t/10);
	putchar(t%10+'0');
}

void work()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		a[i]+=a[i-1];
	}
	for(int le=1;le<=n;le++)
	{
		memset(maxx,-0x3f,sizeof(maxx));
		for(int l=1;l+le-1<=n;l++)
		{
			int u=a[l+le-1]-a[l-1];
			//cout<<l<<' '<<u<<endl;
			update(1,1,n,l,u);
		}
		for(int j=1;j<=n;j++)
		{
			ans[j][le]=query(1,1,n,max((int)1,j-le+1),j);
			//cout<<j<<' '<<le<<' '<<ans[j][le]<<endl;
		}
	}
	for(int i=1;i<=n;i++)
	{
		build(1,1,n,i);
	}
	int q;
	q=read();
	for(int i=1;i<=q;i++)
	{
		int L,R;
		L=read();
		R=read();
		unsigned int ans=0;
		for(int j=1;j<=n;j++)
		{
			unsigned int l=j;
			unsigned int kl=query1(1,1,n,L,R,j);
			l*=kl;
			//cout<<j<<' '<<kl<<endl;
			ans^=l;
		}
		write(ans);
		putchar('\n');
	}
}

signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int c,T=1;
	//T=read();
	while(T--) work();
}
