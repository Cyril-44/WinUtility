#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long n,m,s,ans,t;
struct node
{
	long long x,y,d;
}a[N];
bool cmp1(node u,node v)
{
	return u.x+u.y<v.x+v.y;
}
bool cmp2(node u,node v)
{
	return u.x<v.x;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].d=i;
	}
	sort(a+1,a+n+1,cmp1);
	s=a[1].x+a[1].y;
	sort(a+1,a+n+1,cmp2);
	for(long long i=1;i<=n;i++){
		if(a[i].x<=floor(s/2.0)&&a[i].x<=m){
			m-=a[i].x;
			ans++;
		}else{
			t=i;
			break;
		}
	}
	ans+=m/s*2;
	m%=s;
	for(long long i=t;i<=n;i++){
		if(a[i].x<=m){
			m-=a[i].x;
			ans++;
		}else break;
	}
	cout<<ans;
	return 0;
}
