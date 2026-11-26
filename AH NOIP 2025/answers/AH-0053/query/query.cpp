#include <bits/stdc++.h>
#define int long long 
#define ull unsigned long long
using namespace std;
const int maxn = 50010;
const int INF = 1e16;
class SegmentTree
{
	vector<int> v;
	int n;
	void update(int p,int l,int r,int ul,int ur,int k)
	{
		if(ul>r || ur<l) return;
		if(ul<=l && ur>=r)
		{
			v[p] = max(v[p],k);
			return;
		}
		int mid = (l+r)/2, lch = p*2, rch = p*2+1;
		update(lch,l,mid,ul,ur,k);
		update(rch,mid+1,r,ul,ur,k);
	}
	int query(int p,int l,int r,int u)
	{
		if(u>r || u<l) return -INF;
		if(l==r) return v[p];
		int mid = (l+r)/2, lch = p*2, rch = p*2+1;
		return max(v[p], max(query(lch,l,mid,u),query(rch,mid+1,r,u)));
	}
	public:
		SegmentTree(int n)
		{
			this->n = n;
			v.resize(n*4,-INF);
		}
		void update(int l,int r,int k)
		{
			update(1,1,n,l,r,k);
		}
		int query(int u)
		{
			return query(1,1,n,u);
		}
};
int n, q, a[maxn], dis[3010][3010];
int read()
{
	int res = 0, f = 1;
	char c = getchar();
	if(c<'0' || c>'9')
	{
		if(c=='-') f = -1;
		c = getchar();
	}
	while(c>='0' && c<='9')
	{
		res = res*10 + c-'0';
		c = getchar();
	}
	return res*f;
}
void write(ull x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
signed main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	n = read();
	for(int i=1;i<=n;i++)
		a[i] = read();
	q = read();
	if(n<=3000 && q<=50)
	{
		__int128 mod = 1;
		for(int i=1;i<=64;i++)
			mod *= 2;
		for(int i=1;i<=n;i++)
		{
			SegmentTree tree(n);
			int sum = 0;
			for(int j=1;j<=i;j++)
				sum += a[j];
			tree.update(1,i,sum);
			for(int j=i+1;j<=n;j++)
			{
				 sum += a[j]-a[j-i];
				 tree.update(j-i+1,j,sum);
			}
			for(int j=1;j<=n;j++)
				dis[j][i] = tree.query(j);
		}
		while(q--)
		{
			int L, R;
			L = read();R = read();
			ull ans = 0;
			for(int i=1;i<=n;i++)
			{
				__int128 res = -INF;
				for(int j=L;j<=R;j++)
					res = max(res, (__int128)(dis[i][j]));
				res *= i;
				while(res<0) res += mod;
				ull tmp = res;
				ans ^= tmp;
			}
			write(ans);
			puts("");
		}
	}
	else
	{
		__int128 mod = 1;
		for(int i=1;i<=64;i++)
			mod *= 2;
		while(q--)
		{
			ull ans = 0;
			int L, R;
			L = read();R = read();
			SegmentTree tree(n);
			for(int i=L;i<=R;i++)
			{
				int sum = 0;
				for(int j=1;j<=i;j++)
					sum += a[j];
				tree.update(1,i,sum);
				for(int j=i+1;j<=n;j++)
				{
					sum += a[j]-a[j-i];
					tree.update(j-i+1,j,sum);
				}
			}
			for(int i=1;i<=n;i++)
			{
				__int128 sum = tree.query(i);
				sum *= i;
				while(sum<0) sum += mod;
				ull res = sum;
				ans ^= res;
			}
			write(ans);
			puts("");
		}
	}
	return 0;
}
