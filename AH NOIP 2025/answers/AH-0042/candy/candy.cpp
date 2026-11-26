#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const long long mod = 998244353;
const long long inf = 1e18 + 7;
int n , m;
int a[100005] , b[100005];
int c[100005] , d[100005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	freopen("candy.in" , "r" , stdin);
	freopen("candy.out" , "w" , stdout);
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>a[i]>>b[i];

		c[i] = a[i] , d[i] = a[i] + b[i];
	}

	sort(c + 1 , c + 1 + n) , sort(d + 1 , d + 1 + n);
	int ans = 0;
	int l = 1;
	for(l = 1 ; l + 1 <= n ; l += 2)
	{
		if(c[l] + c[l + 1] < d[1] && c[l] + c[l + 1] <= m)ans += 2 , m -= c[l] + c[l + 1];
		else break;
	}


	int k = m / d[1];
	ans += 2 * k;
	m -= k * d[1];
	/*
	cout<<l<<endl;
	for(int i = 1 ; i <= l + 2 ; i++)cout<<i<<':'<<c[i]<<endl;
	cout<<d[1]<<' '<<k<<endl;
	cout<<m<<endl;
	*/
	if(m >= c[l])ans++;
	if(l > 1 && m + c[l - 1] >= d[1])ans++;
	cout<<ans;
	return 0;
}

