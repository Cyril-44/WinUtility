#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5;
typedef long long ll;
int n,id;
ll m,ans,mn2=2000000000;
struct node{
	int x,y;
	friend bool operator <(node u,node v){
		return u.x<v.x;
	}
}a[N+5];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		if (a[i].x+a[i].y<mn2){
			mn2=a[i].x+a[i].y;
			id=i;
		}
	}
	//cerr<<id<<' '<<"mn2="<<mn2<<'\n';
	for (int i=0;i<=n;i++){
		if (m<a[i].x) break;
		m-=a[i].x; //cerr<<i<<' '<<a[i].x<<' '<<m<<' ';
		if ((i<id&&a[id].x<=m%mn2)||(i>=id&&a[id].y<=m%mn2)){
			ans=max(ans,i+m/mn2*2+1);
			//cerr<<"fk="<<m/mn2*2<<' '<<i+m/mn2*2+1<<'\n';
		} else {
			ans=max(ans,i+m/mn2*2);
			//cerr<<i+2*m/mn2<<'\n';
		}
		
	}
	printf("%lld",ans);
}
