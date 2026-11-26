#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m,mn=LLONG_MAX,ans,mm,as;
long long cc1,cc2;	//cc1=c[it].c0
bool ba,bl;			//ba:性质a
struct candy{
	long long c0,c1,it;
}c[N];			//c表示candy
bool cmp(candy x1,candy x2)
{
	return x1.c0<x2.c0;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>c[i].c0>>c[i].c1;
		if(c[i].c0!=c[i].c1)ba=1;
		c[i].it=i;
	}
	if(!ba)		//A
	{
		for(int i=0;i<n;i++)
		mn=min(mn,c[i].c1);
		m/=mn;
		cout<<m;
		return 0;
	}
	long long x,it;
	for(int i=0;i<n;i++)
	{
		x=c[i].c1+c[i].c0;
		if(mn>x)
		{
			it=i;
			mn=x;
		}
	}
	cc1=c[it].c0;
	cc2=c[it].c1;
	mm=m;
	ans=mm/mn*2;
	mm%=mn;
	if(mm>=cc1)ans++;		//计算当m=mm时的ans
	//仅取一种
	x=1;
//	cout<<cc1<<" "<<cc2<<endl;
	sort(c,c+n,cmp);
	for(int i=0;i<n;i++)	//再取第i种的第一个
	{
//		cout<<c[i].c0<<" "<<c[i].c1<<endl;
		if(c[i].it==it)continue;
		bl=0;
		mm=m-c[i].c0;
		if(mm<0)break;
		as=mm/mn*2;
		mm%=mn;
		if(mm>=cc1)
		{
			as++;
			bl=1;
		}
		as+=x;
		if(ans<=as)	//取
		{
			x++;
			ans=as;
			if(bl)m-=min(c[i].c0,cc2);
			else m-=min(c[i].c0,cc1);
		}
		else break;
//		cout<<ans<<endl<<endl;
	}
	cout<<ans;
	return 0;
}
