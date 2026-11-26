#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
struct Node{
	int x,y,z;
};
Node a[N];
bool cmp(Node q,Node p)
{
	return q.z<p.z;
}
bool cmp2(Node q,Node p)
{
	return q.x<p.x;
}
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s1=0;
	int num=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].z=a[i].x+a[i].y;
	}
	sort(a+1,a+1+n,cmp);
	int aa=a[1].z;
	int bj=aa/2;
	int maxn=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i].x<=bj)
		{
			s1=s1+a[i].x;
			if(a[i].x>maxn) maxn=a[i].x;
			num++;
		}
	}
	if(m<s1)
	{
		int ans=0;
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(m>=a[i].x)
			{
				ans++;
				m=m-a[i].x;
			}
			else
			{
				break;
			}
		}
		cout<<ans<<endl;
	}
	else
	{
		int ans=num;
		m=m-s1;
		ans=ans+(m/aa)*2;
		m=m%aa;
		if(m>=a[1].x)
			ans++;
		else if((m+maxn)>=aa)
			ans++;
		cout<<ans<<endl;
	}
	return 0;
}
