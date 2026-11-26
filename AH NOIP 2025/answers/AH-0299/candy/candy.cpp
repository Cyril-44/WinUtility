#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m,minn=5000000000,sum,k,num;
struct fx{
	ll x,y;
}a[110000];
bool cmp(fx xx,fx yy){
	return xx.x<yy.x;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin >>n>>m;k=m;
	for (ll i=1;i<=n;i++){
		cin >>a[i].x>>a[i].y;
		minn=min(minn,a[i].x+a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	sum=0;
	bool jin=true;
	for (int i=1;i<=n;i++){
		if (jin&&minn/2<a[i].x){
			sum+=m/minn*2;
			m%=minn;
			i--;
			jin=false;
		}
		else if(m>=a[i].x){
			m-=a[i].x;
			sum++;
			num=i;
		}
	}
	if (a[num].x+m>=minn)	sum++;
	cout <<sum<<endl;
	return 0;
}
