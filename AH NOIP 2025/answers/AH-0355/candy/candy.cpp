#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,tmp,ans,cyb,lst;
vector<ll> vec;
struct Node{
	ll x;
	ll y;
	ll z;
}a[100005];
bool cmp(Node x,Node y){
	if(x.z!=y.z)
		return x.z<y.z;
	return x.x<y.x;
}
bool cmp2(Node x,Node y){
	return x.x<y.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].z=a[i].x+a[i].y;
	}
	sort(a+1,a+1+n,cmp);
	if(m<a[1].z){
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++)
			if(m>=a[i].x){
				m-=a[i].x;
				ans++;
			}else
				break;
		cout<<ans<<'\n';
		return 0;
	}
	tmp=a[1].z;
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n;i++)
		if(a[i].x*2<tmp&&m>=a[i].x){
			m-=a[i].x;
			ans++;
			lst=a[i].x;
			swap(a[i].x,a[i].y);
		}else
			break;
	cyb=m/tmp;
	ans+=cyb*2;
	m%=tmp;
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n;i++)
		if(m>=a[i].x){
			m-=a[i].x;
			ans++;
		}else
			break;
	if(m+lst>=tmp)
		ans++;
	cout<<ans<<'\n';
	return 0;
}
