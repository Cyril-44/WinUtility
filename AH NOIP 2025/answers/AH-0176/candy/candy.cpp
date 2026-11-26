#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m;
struct node{
	ll x,y,i;
}a[100005];
ll x1=1e18,y2=1e18,cnt=0,f=0;
double s=1e18;
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&a[i].x,&a[i].y);
		a[i].i=i;
		if(a[i].x+a[i].y==s){
			if(max(a[i].x,a[i].y)<max(x1,y2))x1=a[i].x,y2=a[i].y;
		}else if(a[i].x+a[i].y<s){
			x1=a[i].x,y2=a[i].y,s=x1+y2;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n&&m>0;i++){
		if(a[i].x+a[i+1].x<=x1+y2){
			m-=a[i].x;
			cnt++;
			if(m<0){
				cnt--;
				break;
			}
			continue;
		}
		//printf("%lld %lld\n",a[i].x,m);
		if(!f){
			if(x1<y2)swap(x1,y2);
			if(m>=(x1+y2)){
				cnt+=m/(x1+y2)*2;
				//cout<<m/(x1+y2)<<endl;
				m%=(x1+y2);
			}
			f=1;
		}
		if(a[i].x>x1)break;
		if(a[i].x<x1){
			m-=a[i].x;
			if(m>=0)cnt++;
		}else{
			m-=x1;
			if(m>=0)cnt++;
		}
	}
	printf("%lld\n",cnt);
	//printf("%lld %lld\n",x1,y2);
	//for(int i=1;i<=n;i++){
	//	if(a[i].x<300)printf("%lld %lld\n",a[i].x,a[i].y);
	//}
	return 0;
}
