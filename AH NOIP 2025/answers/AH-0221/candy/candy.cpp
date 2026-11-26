#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
struct STU
{
	long long x,y,sum;
}a[100005];
bool cmp(STU b,STU c)
{
	return b.x < c.x;
}
bool cmp1(STU b,STU c)
{
	if(b.sum != c.sum)
		return b.sum < c.sum;
	else
		return b.x < c.x;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool ok = true;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].sum = a[i].x + a[i].y;
		if(a[i].x != a[i].y) ok = false;
	}
	if(ok)
	{
		sort(a + 1,a + n + 1,cmp);
		cout << m / a[1].x;
		return 0;
	}
	sort(a + 1,a + n + 1,cmp1);
	long long k1 = m / a[1].sum,k2 = a[1].sum;
	sort(a + 1,a + n + 1,cmp);
	if(k1 == 0)
	{
		long long num = 0;
		for(int i = 1; i <= n; i++)
		{
			if(m >= a[i].x)
			{
				m -= a[i].x;
				num++;
			}
		}
		cout << num;
		return 0;
	}
	long long num = 0,endnum = 0,nowj = 1,summ = 0;
	for(long long i = k1; i >= 1; i--)
	{
		long long nowyu = m - i * k2;
		num = i * 2;
		for(int j = nowj; j <= n; j++)
		{
			if(summ + a[j].x <= nowyu) 
			{
				summ += a[j].x;
			}
			else
			{
				nowj = j;
				num += j - 1;
				endnum = max(endnum,num);
				break;
			}
		}
	}
	cout << endnum;
	return 0;
}
