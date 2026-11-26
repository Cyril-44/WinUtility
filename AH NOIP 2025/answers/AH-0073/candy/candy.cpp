#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y;
}a[100010];
bool cmpx(node &x,node &y){
	return x.x<y.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	long long m;
	scanf ("%d%lld",&n,&m);
	long long ll=0x3f3f3f3f3f3f3f3f;
	long long id=0;
	for (int i=1;i<=n;++i){
		scanf ("%lld%lld",&a[i].x,&a[i].y);
		if (ll>a[i].x+a[i].y){
			ll=a[i].x+a[i].y;
			id=a[i].x;
		}
	}
	sort(a+1,a+n+1,cmpx);
	long long ans=0;
	long long ox=-0x3f3f3f3f3f3f3f3f,oy=0;
	for (int i=1;i<=n && m>0;++i){
		if (a[i].x*2>ll)
			break;
		if (m-a[i].x<0)
			break;
		m-=a[i].x;
		if (a[i].x==id)
			id=ll-id;
		ox=a[i].x;
		oy=i;
		swap(a[i].x,a[i].y);
		ans++;
	}
	ans+=(m/ll)*2;
	m-=(m/ll)*ll;
	if ((m+ox)>=ll){
		m=(m+ox)-ll;
		ans++;
		swap(a[oy].x,a[oy].y);
	}
	sort(a+1,a+n+1,cmpx);
	if (ll-id>a[1].x){
		ans--;
		m+=ll-id;
	}
	for (int i=1;i<=n && m>0;++i){
		if (m-a[i].x<0)
			break;
		m-=a[i].x;
		ans++;	
	}
	printf ("%lld",ans);
	return 0;
}
//!noip@Nov29,2025:dream
