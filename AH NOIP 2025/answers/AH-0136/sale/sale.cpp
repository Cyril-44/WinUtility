#include<bits/stdc++.h>
#define ll long long
#define N 5010
using namespace std;
ll c,t,n,m,a[N],ans=0;
ll sal[N],f[N];
struct Node{
	ll x,s,id;
}tp[N];
bool cmp1(Node a,Node b){
	if(a.x*b.s!=b.x*a.s) return a.x*b.s>b.x*a.s;
	return a.x>b.x;
	if(a.x!=b.x) return a.x>b.x;
	return a.id>b.id;
}
void work1(int k){
	if(k<=n){
		sal[k]=1;
		work1(k+1);
		sal[k]=2;
		work1(k+1);
	}
	else{
		for(int i=1;i<=n;i++){
			tp[i].x=a[i];
			tp[i].s=sal[i];
			tp[i].id=i;
		}
		sort(tp+1,tp+n+1,cmp1);
		ll m1=m,ans1=0,ans2=0;
		for(int i=1;i<=n&&m1>0;i++){
			if(m1>=tp[i].s){
				m1-=tp[i].s;
				ans1+=tp[i].x;
			}
		}
		for(int i=1;i<=m;i++) f[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				if(j>=sal[i]) f[j]=max(f[j-sal[i]]+a[i],f[j]);
			}
		}
		for(int i=1;i<=m;i++) ans2=max(ans2,f[i]);
		if(ans1==ans2) ans++;
	}
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		work1(1);
		ans%=998244353;
		cout<<ans<<'\n';
	}
	return 0;
}
