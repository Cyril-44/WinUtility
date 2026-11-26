#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int op,sum,id;
	bool operator < (const node &x) const {
		return 1.0*sum/op<1.0*x.sum/x.op;
	}
};
node a[N];bool vis[N];
int n,bd[N];long long m,ans;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		bd[i]=y;
		a[i]={1,x,i};
		a[n+i]={2,x+y,i};
	}
	sort(a+1,a+2*n+1);
	for(int i=1;i<=2*n;i++){
		if(a[i].sum>m) continue;
		if(a[i].op==1) m-=a[i].sum,ans++,vis[a[i].id]=1;
		if(a[i].op==2) ans+=(m/a[i].sum)*2,m%=a[i].sum;
	}
	sort(bd+1,bd+n+1);
	for(int i=1;i<=n;i++){
		if(vis[i]&&m>=bd[i]) ans++,m-=bd[i];
	}
	cout<<ans;
	return 0;
}
