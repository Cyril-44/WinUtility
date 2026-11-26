#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
struct candy{
	ll j;
	ll o;
	int d;
}c[100010];
struct can{
	double zhi;
	bool f;
	int d;
}a[200010];
bool ch(can x,can y){
	if(x.zhi==y.zhi){
		return x.f<y.f;
	}
	return x.zhi<y.zhi;
}
bool ch1(int x,int y){
	return x<y;
}
int vis[100010];
int b[100010];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	ll m;
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i].j>>c[i].o;
		c[i].d=i;
		a[++cnt].zhi=c[i].j;
		a[cnt].f=0;
		a[cnt].d=i;
		a[++cnt].zhi=(c[i].j+c[i].o)*1.0/2;
		a[cnt].f=1;
		a[cnt].d=i;
	}
	sort(a+1,a+1+cnt,ch);
	ll ans=0;
	for(int i=1;i<=cnt;i++){
		if(a[i].f==0){
			if(m-a[i].zhi>=0){
				ans++;
				m-=a[i].zhi;
				vis[a[i].d]=1;
			}
		}
		else{
			int t=int(a[i].zhi*2);
			ll h=m/t;
			h*=2;
			ans+=h;
			m%=t;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			b[i]=c[i].j;
		}
		else{
			b[i]=c[i].o;
		}
	}
	sort(b+1,b+1+n,ch1);
	for(int i=1;i<=n;i++){
		if(m-b[i]>=0){
			ans++;
			m-=b[i];
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
