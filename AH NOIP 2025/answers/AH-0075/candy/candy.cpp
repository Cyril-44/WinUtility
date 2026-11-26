#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100010;
struct node{
	long long x, y;
}a[N];
bool cmp(node aa,node bb){
	return aa.x < bb.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	long long m, ms = 1e18, mf = 1e18;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		if(a[i].x + a[i].y < ms){
			ms = a[i].x + a[i].y;
		}
	}
	sort(a+1,a+n+1,cmp);
	long long ans = 0,left = 0;
	for(int i=1;i<=n;i++){
		if(a[i].x <= ms/2){
			if(m < a[i].x){
				printf("%lld",ans);
				return 0;
			}
			ans++;
			m -= a[i].x;
			mf = min(mf, a[i].y);
			left = max(left, a[i].x);
		}
		else{
			mf = min(mf, a[i].x);
		}
	}
	ans += (m / ms) * 2;
	m %= ms;
	if(m >= mf) ans++;
	else if(m + left >= ms) ans++;
	printf("%lld",ans);
	return 0;
}
