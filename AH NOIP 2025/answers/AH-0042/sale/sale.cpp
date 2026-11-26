#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long mod = 998244353;
const long long inf = 1e18 + 7;
int n , m;
int a[50005];
int fact[50005];
int fact_inv[50005];
int qpow(int x , int y)
{

	int res = 1;
//	y = 0;
	while(y)
	{
		if(y & 1)res = res * x % mod;
		y = (y >> 1);
		x = x * x % mod;
	}
	return res % mod;

//	if(y <= 0)return 1;
//	return (y & 1) ? qpow(x * x % mod , y >> 1) * x % mod : qpow(x * x % mod , y);
}
void init()
{
	fact[1] = 1;fact_inv[0] = 1 , fact[0] = 1;
	for(int i = 2 ; i <= 50001 ; i++)fact[i] = (fact[i - 1] * i) % mod;
	//fact_inv[50001] = qpow(50001 , mod - 2);
	//for(int i = 50000 ; i >= 1 ; i--)fact_inv[i] = (fact_inv[i + 1] * (i + 1)) % mod;
	for(int i = 1 ; i <= 50001 ; i++)fact_inv[i] = qpow(i , mod - 2);
	return ;
}
bool cmp(int x , int y){return x > y;}
int C(int x , int y){return (fact[x] * ((fact_inv[y] * fact_inv[x - y]) % mod)) % mod;}

struct node{
	int a , id;
}b[50005];

bool cmp2(node x , node y)
{
	return (x.a == y.a) ? x.id < y.id : x.a > y.a;
}

int check(int x , int id)
{
	int l = 1 , r = n , mid;
	while(l < r)
	{
		mid = (l + r + 1) >> 1;
		if(b[mid].a < x) r = mid - 1;
		else if(b[mid].a > x)l = mid + 1;
		else
		{
			if(b[mid].id < id)l = mid;
			else r = mid - 1;
		}
	}
	return l;
}
int check2(int x , int id)
{
	int l = 1 , r = n , mid;
	while(l < r)
	{
		mid = (l + r + 1) >> 1;
		if(b[mid].a * 2 < x) r = mid - 1;
		else if(b[mid].a * 2 > x)l = mid + 1;
		else
		{
			if(b[mid].id < id)l = mid;
			else r = mid - 1;
		}
	}
	return l;
}
int ans[50005];
int f[505][505];
int w[505];
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0) , cout.tie(0);
	freopen("sale.in" , "r" , stdin);
	freopen("sale.out" , "w" , stdout);
//	cin>>n>>m;
	int ____ , ___;
	cin>>____>>___;
	init();
//	int l , r;
	queue<int>q;
	while(___--)
	{
//		cout<<___<<':'<<endl;
		cin>>n>>m;
		for(int i = 1 ; i <= n ; i++)cin>>a[i] , b[i].a = a[i] , b[i].id = i;

		/*
		int cnt1 , cnt2;
		for(int i = 1 ; i <= n ; i++)
		{
			cnt1 = 0;
			for(int j = n ; j > n - i ; j--)
			{
				if(check(b[j].a * 2 , b[j].id) <= n - i)cnt1++;
				cout<<i<<' '<<j<<':'<<cnt1<<' '<<check(b[j].a * 2 , b[j].id)<<endl;
			}
			ans[i] = (qpow(2 , i + 1) - ((qpow(2 , cnt1) - 1) * (qpow(2 , i - cnt1 + 1) - 1) % mod)) % mod;
			cout<<i<<':'<<ans[i]<<endl;
		}
		cnt2 = 0;
		for(int i = 0 ; i <= m - n ; i++)cnt2 += ans[i];

		cnt2 %= mod;
		cout<<cnt2<<endl;
		*/
		if(____ == 18)
		{
			cout<<qpow(2 , n + 1) - 1<<endl;
		}

//		int l = 0;
		else if((____ >= 7 && ____ <= 9) || (____ >= 14 && ____ <= 15))
		{
			sort(b + 1 , b + 1 + n , cmp2);
			sort(a + 1 , a + 1 + n , cmp);
			int cnt = 0;
			for(int i = 2 ; i <= n ; i++)
			{

				for(int j = n ; j >= i + 1 ; j--)
				{
					if(a[i] + a[j] < a[1] && (2 * a[i] > a[1] && 2 * a[j] > a[1]))cnt = (cnt + (qpow(2 , n - j) - 1)) % mod;
					//else break;
				}
			}
			cout<<((qpow(2 , n + 1) - 1 + mod) - cnt) % mod<<endl;
		}
		else{
			int ans = 0;
			for(int i = 0 ; i < (1 << n) ; i++)
			{
				memset(f , 0 , sizeof f);
				for(int j = 1 ; j <= n ; j++)w[j] = 1;
				for(int j = 0 ; (1 << j) <= i ; j++)
				{
					if(((1 << j) & i) != 0)w[j + 1] = 2;
					else w[j + 1] = 1;
				}
				/*
				for(int j = 1 ; j <= n ; j++)cout<<w[j]<<' ';
				cout<<endl;
				*/
				int q = 0;
				for(int j = 1 ; j <= n ; j++)
				{
					for(int k = m ; k >= w[j] ; k--)
					{
						f[j][k] = max(f[j - 1][k] , f[j][k]);
						f[j][k] = max(f[j][k] , f[j - 1][k - w[j]] + a[j]);
					//	cout<<i<<' '<<j<<' '<<k - w[j]<<':'<<f[j - 1][k - w[j]]<<' '<<a[j]<<endl;
						q = max(q , f[j][k]);
					}
				}
				/*
				cout<<"_______________________"<<endl;
				for(int j = 1 ; j <= n ; j++)
				{
					for(int k = 1 ; k <= m ; k++)cout<<f[j][k]<<' ';
					cout<<endl;
				}
				cout<<"_______________________"<<endl;
				*/
				for(int j = 1 ; j <= n ; j++)
				{
					b[j].a = a[j] * 2 / w[j];
					b[j].id = j;
				}
				sort(b + 1 , b + 1 + n , cmp2);
				int q2 = 0;
				int sss = m;
				for(int j = 1 ; j <= n ; j++)
				{
					if(sss <= 0)break;
					if(sss >= w[b[j].id])q2 += b[j].a * w[b[j].id] / 2 , sss -= w[b[j].id];
//					cout<<j<<':'<<q2<<' '<<sss<<endl;
				}
//				cout<<q2<<' '<<q<<endl;
				if(q2 >= q)ans++;
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}
/*
what a beautiful shuju
*/
