#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
struct candy{
	long long x,y,jun;
	bool operator<(const candy& u)const{
		if(jun!=u.jun) return jun<u.jun;
		if(x!=u.x) return x<u.x;
		return y<u.y;
	}
}a[100005];
bool cmp1(candy x,candy y){
	if(x.jun!=y.jun) return x.jun<y.jun;
		if(x.x!=y.x) return x.x<y.x;
		return x.y<y.y;
}
bool cmp2(candy x,candy y){
	return x.x<y.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].x*=2;
		a[i].y*=2;
		a[i].jun=(a[i].x+a[i].y)/2;
	}
	sort(a+1,a+n+1,cmp1);
	m*=2;
	sort(a+2,a+n+1,cmp2);
	for(int i=2;i<=n;i++){
		if(a[i].x<=a[1].jun) m-=a[i].x,ans++,a[i].x=a[i].y;
	}
	ans+=(m/(a[1].jun*2))*2;
	m-=(m/(a[1].jun*2))*a[1].jun*2;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(m>=a[i].x) m-=a[i].x,ans++;
	}
	cout<<ans<<endl;
}
