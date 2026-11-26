#include<bits/stdc++.h>
using namespace std;
const int Maxn=5e4+5;
const unsigned long long Mod=(1<<(64));
long long a[Maxn], b[Maxn];
struct ST
{
	int len;
	vector<vector<long long>> biao;
	vector<int> lo;
	ST(int n, long long a[])
	{
		len=n;
		biao.resize(20);
		biao[0].resize(len+5);
		lo.resize(len+5);
		for(int i=1;i<=len;i++)
		{
			if(i>1) lo[i]=lo[i/2]+1;
			biao[0][i]=a[i];
		}
		for(int l=1;(1<<l)<=len;l++)
		{
			biao[l].resize(len+5);
			for(int i=1;i+(1<<l)-1<=len;i++)
			{
				biao[l][i]=max(biao[l-1][i],biao[l-1][i+(1<<(l-1))]);
			}
		}
	}
	long long qu(int l,int r)
	{
		if(l>r) swap(l,r);
		int le=lo[r-l+1];
		return max(biao[le][l],biao[le][r-(1<<le)+1]);
	}
};
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=b[i-1]+a[i];
	}
	ST c(n,b);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int L, R;
		scanf("%d%d",&L,&R);
		unsigned long long ans=0;
		for(int i=1;i<=n;i++)
		{
			long long Max=-10000000007;
			for(int j=max(1,i-R+1);j<=i && (j+L-1)<=n;j++)
			{
				//>=j+L <=j+R
				int l=max(j+L-1,i), r=min(j+R-1,n);
				Max=max(Max,c.qu(l,r)-b[j-1]);
			}
			unsigned long long nMax;
			if(Max<0) nMax=(Max*i+Mod);
			else nMax=(Max*i);
			ans^=nMax;
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
4
2 4 -5 1
3
1 2
3 4
1 4
*/
