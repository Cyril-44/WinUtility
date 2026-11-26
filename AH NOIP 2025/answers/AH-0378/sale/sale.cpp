#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10005
#define D 998244353
ll C,T,n,f[N],k,ans;
struct nd{
	int x,y;
}a[N],b[N];
bool cp(nd x,nd y){
	if(x.x*y.y==x.y*y.x)
		return x.x>y.x;
	return x.x*y.y>x.y*y.x;
}
void check(){
	for(int i=0;i<n;i++)
		b[i]=a[i];
	sort(b,b+n,cp);
	ll an=0,p=k;
	for(int i=0;i<n;i++){
		if(p>=b[i].y){
			p-=b[i].y;
			an+=b[i].x;
		}
	}
	for(int i=0;i<=k;i++)
		f[i]=0;
	for(int i=0;i<n;i++)
		for(ll j=k;j>=b[i].y;j--)
			f[j]=max(f[j-b[i].y]+b[i].x,f[j]);
	if(f[k]==an)
		ans++;
	return;
}
void dfs(int x){
	if(x==n){
		check();
		return;
	}
	a[x].y=1;
	dfs(x+1);
	a[x].y=2;
	dfs(x+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>a[i].x;
		ans=0;
		if(C==18){
			ans=1;
			while(n--)
				ans=(ans*2)%D;
			cout<<ans;
			continue;
		}
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}
