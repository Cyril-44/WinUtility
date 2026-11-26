#include<bits/stdc++.h>
using namespace std;
long long n,k;
const int N=100005;
long long x[N];
long long y[N];
long long w1[N];
long long w2[N];
long long dp[N];
long long summoney=0,sumcandy=0;
stack <int> s;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
		w1[i]=x[i];
	for(int i=1;i<=n;i++)
		w2[i]=x[i]+y[i];
	sort(w1+1,w1+n+1);
	sort(w2+1,w2+n+1);
	long long bestw2=w2[1];
	for(int i=1;i<=n;i++)
	{
		if(summoney+w1[i]<=k&&w1[i]*2<=bestw2)
		{
			summoney+=w1[i];
			sumcandy++;
		}
		else break;
	}
	while(summoney+bestw2<=k)
	{
		summoney+=bestw2;
		sumcandy+=2;
	}
	cout<<sumcandy<<endl;
	return 0;
}
