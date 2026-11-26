#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
long long pi[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		long long x,y;
		cin>>x>>y;
		a[i]=x,pi[i]=x+y;
	}
	sort(a+1,a+n+1);
	sort(pi+1,pi+n+1);
	long long w=m,ans=0,i;
	for(i=1;a[i]*2<pi[1]&&i<=n;++i){
		ans+=1;
		w-=a[i];
	}
	long long num=w/pi[1];
	w-=num*pi[1];
	ans+=num*2;
	if(w+a[i-1]>pi[1])
	{
		w=w+a[i-1]-pi[1];
		ans+=1;
		i--;
	}
	for(int j=i;w>=a[j]&&j<=n;j++)
	{
		w-=a[j];
		ans++;
	}
	cout<<ans;
	return 0;
}
