#include<bits/stdc++.h>
using namespace std;
long long int n,m;
struct t
{
	long long int j,o;
};
long long int f;
long long int minn=INT_MAX;
t a[100010];
bool cmp(t a,t b)
{
	return a.j<b.j;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].j>>a[i].o;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].j+a[i].o<minn)
		{
			minn=a[i].j+a[i].o;
			f=i;
		}
	}
	long long int m1=m;
	//long long int p=a[f].o+a[f].j;
	long long int sum=m/minn;
	m-=(sum-1)*minn;
	sum=(sum-1)*2;
		for(int i=1;i<=n;i++)
		{
			//cout<<a[i].j<<" "<<a[i].o<<endl;
			if(m>=a[i].j)
			{
				sum++;
				m-=a[i].j;
			}
		}
	long long int sum1=m1/minn;
	m1-=sum1*minn;
	sum1=sum1*2;
		for(int i=1;i<=n;i++)
		{
			//cout<<a[i].j<<" "<<a[i].o<<endl;
			if(m1>=a[i].j)
			{
				sum1++;
				m1-=a[i].j;
			}
		}
		//if(m>a[f].j)
		{
		//	sum++;
		}
	//	if(m>a[f].o) sum1++;
		cout<<max(sum,sum1);
}
	

