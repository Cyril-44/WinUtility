#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+5;
const long long oo=1000000000000;
int n;
long long m,mi=oo;
struct node{
	long long x,y,z;
}a[N],b[N];
bool cmp(node x,node y){
	return x.z<y.z;
}
bool cmp2(node x,node y){
	return x.x<y.x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].z=a[i].x+a[i].y;
		mi=min(mi,a[i].z);
		b[i]=a[i];
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp2);
	long long ans=m/mi;
	ans*=2ll;
	for(int i=1;i<=n;i++){
		m-=b[i].x;
		ans=max(ans,2ll*(m/mi)+1ll*i);
	}
	cout<<ans;
	return 0;
}
