#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
struct st{
	ll x,y,sum;
}a[N];
bool cmp(const st&l,const st&r){
	return l.x<r.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	ll minp=1000000005,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].sum=a[i].y+a[i].x;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].sum<minp){
			minp=a[i].sum;
		}
	}
	ll ans=0;int l=1;
	for(l=1;l<=n;l++){
		if(a[l].x>minp/2) break;
		m-=a[l].x;
		if(m<0){
			cout<<ans;
			return 0;
		}
		ans++;
	}
	ans+=(m/minp)*2;
	m-=(m/minp)*minp;
	if((l<=n&&m>=a[l].x)||(l>=2&&m+a[l-1].x>=minp)){
		ans++;
	}
	cout<<ans;
	return 0;
}
