#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,a[N];
ll ans,sum;
ll m;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ll res;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1,u,v;i<=n;i++){
		cin>>u>>v;
		a[i]=u;
		if(res>u+v)res=u+v;
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++){
		sum+=a[i];
		ans=max(ans,(m-sum)/res*2+i);
	}
	cout<<ans;
	return 0;
}
/*
 * #include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n;
ll ans;
struct node{
	double x;
	bool type;
}a[N];
ll m;
bool cmp(node u,node v){
	if(u.x!=v.x)return u.x<v.x;
	return u.type<v.type;
}
int main(){
	freopen("candy.in","r",stdin);
	//freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1,u,v;i<=n;i++){
		cin>>u>>v;
		a[i].x=(u+v)*1.0/2;
		a[i].type=0;
		a[i+n].x=u;
		a[i+n].type=1;
	}
	sort(a+1,a+n*2+1,cmp);
	for(int i=1;i<=2*n;i++)cout<<a[i].x<<' '<<a[i].type<<'\n';
	cout<<'\n';
	for(int i=1;i<=n*2;i++){
		if(m*1.0<a[i].x)break;
		if(a[i].type==0){
			int u=a[i].x*2,s=m/u;
			ans+=s*2;
			m-=s*u;
		}else{
			ans++;
			m-=a[i].x;
		}
		cout<<a[i].x<<' '<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
*/
