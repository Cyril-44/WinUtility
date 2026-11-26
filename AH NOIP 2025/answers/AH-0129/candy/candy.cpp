#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long first[100001],second[100001],minn=9999999999,minf=9999999999,ans,yu,tmp,ans2;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>first[i]>>second[i];
		if(minn>=(first[i]+second[i]))
		{
			if(minn>(first[i]+second[i]))
			{
				minf=first[i];
			}
			else if(minn==(first[i]+second[i]))
			{
				minf=min(minf,first[i]);
			}
			minn=first[i]+second[i];
		}
	}
	sort(first+1,first+n+1);
	int i1=1;
	while(first[i1]<minf)
	{
		ans++;
		m-=first[i1];
		i1++;
	}
	yu=m%minn;
	ans+=(m/minn)*2;
	ans2=ans;
	tmp=yu;
	ans2--;
	tmp+=first[i1-1];
	if(tmp>=minn)
	{
		ans2+=2;
		tmp-=minn;
	}
	
	if(yu>=minf)ans++;
	cout<<max(ans2,ans);
	return 0;
}
