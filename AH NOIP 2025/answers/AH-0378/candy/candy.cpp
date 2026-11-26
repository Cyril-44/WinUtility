#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll n,k,x,y,ans;
struct nd{
	ll s,p;
}a[N],p;
bool cp1(nd x,nd y){
	return x.s<y.s;
}
bool cp2(nd x,nd y){
	return x.p<y.p;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&x,&y);
		a[i].s=x;
		a[i].p=x+y;
	}
	sort(a,a+n,cp2);
	p=a[0];
	ans=k/p.p*2;
	x=k%a[0].p;
	sort(a,a+n,cp1);
	for(int i=0;i<n;i++){
		if(a[i].s<=x){
			ans++;
			x-=a[i].s;
		}
		else if(a[i].s+a[i+1].s<=p.p&&i+1<n){
			x+=p.p-a[i].s-a[i].s;
			i++;
		}
		else break;
	}
	cout<<ans<<endl;
	return 0;
}
