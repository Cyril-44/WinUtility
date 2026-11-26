#include<bits/stdc++.h>
#define N 5005
#define ll long long
using namespace std;
int a[N],w[N],n,m;
ll ans=0;
struct st{
	int p,val,id;
}s[N];
bool cmp(const st&x,const st&y){
	if(x.val*y.p!=y.val*x.p) return x.val*y.p>y.val*x.p;
	return x.p>y.p;
}
int check(){
	for(int i=1;i<=n;i++)
	s[i]={w[i],a[i],i};
	sort(s+1,s+1+n,cmp);
	int mm=m;
	for(int i=1;i<=n;i++){
		if(mm>=2) {mm-=s[i].p;continue;}
		if(mm==0) return 1;
		//mm==1
		if(s[i].p==1) return 1;
		//s[i].p==2
		int val1=0;
		for(int j=i-1;j>=1;j--){
			if(s[j].p==1) {val1=s[j].val;break;} 
		}
		if(val1==0) return 1;
		for(int j=i+1;j<=n;j++){
			if(s[j].p==1) {val1+=s[j].val;break;} 
		}
		if(val1>=s[i].val) return 1;
		return 0;
	}
	return 1;
}
void dfs(int now){
	if(now>n) {ans+=check();return;}
	w[now]=1;
	dfs(now+1);
	w[now]=2;
	dfs(now+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
