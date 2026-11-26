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

int n,m;
int cnt[8005];
vector<int> to[8005];
int dp[19][(1<<18)+5];
int siz[19];
int re[(1<<18)+5];

void dfs(int t)
{
	siz[t]=1;
	if(to[t].size()==0)
	{
		dp[t][1]=1;
		for(int j=1;j<n;j++) dp[t][1<<j]=0;
		return;
	}
	dp[t][0]=0;
	for(int i=0;i<to[t].size();i++)
	{
		dfs(to[t][i]);
		siz[t]+=siz[to[t][i]];
		int u=to[t][i];
		for(int j=1;j<(1<<n);j++)
		{
			if(__builtin_popcount(j)>siz[u]) continue;
			for(int l=0;l<(1<<n);l++)
			{
				dp[t][re[l]|j]=max(dp[t][re[l]|j],dp[t][re[l]]+dp[u][j]);
			}
		}
	}
	for(int i=(1<<n)-1;i>=0;i--)
	{
		int kl=re[i];
		for(int j=0;j<n;j++)
		{
			if(kl>>j&1) dp[t][kl]=max(dp[t][kl],dp[t][kl^(1<<j)]);
		}
	}
	for(int i=0;i<(1<<n)-1;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if(i>>j&1) cnt++;
			else break;
		}
		dp[t][i]+=cnt;
		cout<<t<<' '<<i<<' '<<cnt<<' '<<dp[t][i]<<endl;
	}
}

int cmp(int a,int b)
{
	return __builtin_popcount(a)>__builtin_popcount(b);
}

void work()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		memset(dp[i],-0x3f,sizeof(dp[i]));
		to[i].clear();
	}
	for(int i=0;i<(1<<n);i++) re[i]=i;
	sort(re,re+(1<<n),cmp);
	memset(cnt,0,sizeof(cnt));
	m=read();
	for(int i=2;i<=n;i++)
	{
		int t;
		t=read();
		to[t].push_back(i);
	}
	dfs(1);
	int ans=0;
	for(int i=0;i<(1<<n);i++) ans=max(ans,dp[1][i]);
	printf("%lld\n",ans);
}

signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int c,T=1;
	T=read();
	while(T--) work();
}
