#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N=1e5+5,INF=0x3f3f3f3f;
struct candy
{
	int v1,v2,tot,fl;
}v[N];
struct node
{
	int id,sum;
}pri[N];
bool cmp(candy a,candy b)
{
	return a.tot<b.tot;
}
bool pmc(node a,node b)
{
	return a.sum<b.sum;
}
bool cmp2(candy a,candy b)
{
	return a.v1<b.v1;
}
int i,n,m,ans,fl[N],tot;
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>v[i].v1>>v[i].v2;
		v[i].tot=v[i].v1+v[i].v2;
	}
	sort(v+1,v+n+1,cmp);
	//if(m>v[1].v1)ans++,m-=v[1].v1;
	for(i=2;i<=n;i++)
	{
		if(v[i].v1<min(v[1].v1,v[1].v2))pri[++tot]={i,v[i].v1};
	}
	sort(pri+1,pri+tot+1,pmc);
	for(i=1;i<=tot;i++)
	{
		int u=pri[i].id;
		if(m-v[u].v1<0)break;
		ans++,m-=v[u].v1,v[u].fl=1,v[u].v1=v[u].v2;
	}
	//cout<<m<<' '<<ans<<endl;
	//for(i=2;i<=n;i++)
	//{
	//	if(v[i].fl&&v[i].v2<v[1].v2)
	//	{
	//		if(m-v[i].v2<0)break;
	//		ans++,m-=v[i].v2;
	//	}
	//}
	//if(m>v[1].v2)m-=v[1].v2,ans++;
	int sum=m/v[1].tot;
	ans+=sum*2,m-=sum*v[1].tot;
	//cout<<m<<' '<<ans<<endl;
	sort(v+1,v+n+1,cmp2);
	for(i=1;i<=n;i++)
	{
		//cout<<m<<' '<<ans<<endl;
		//if(v[i].fl)continue;
		m-=v[i].v1;
		//cout<<m<<' '<<ans<<endl;
		if(m>=0)ans++;
		else break;
	}
	cout<<ans;
	return 0;
}
