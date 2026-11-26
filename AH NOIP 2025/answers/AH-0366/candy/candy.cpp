#include<bits/stdc++.h>
using namespace std;
long long n,m;
int ans=0;
bool vis[55];
struct node{
	int x,y;
}a[100005];
bool cmp(node a,node b){
	return a.x<b.x;
}
bool cmp2(node a,node b){
	return a.x+a.y<b.x+b.y;
}
void f(){
	sort(a+1,a+1+n,cmp);
	ans=int(floor(m/a[1].x));
}
void dfs(int m,int nowa){
	if(m<0){
		ans=max(ans,nowa-1);
		return;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(m-a[i].x,nowa+1);
			vis[i]=0;
		}
		else {
			vis[i]=0;
			dfs(m-a[i].y,nowa+1);
			vis[i]=1;
		}
	}
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	memset(vis,0,sizeof(vis));
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].x!=a[i].y){
			flag=0;
		}
	}
	if(n<=10){
		dfs(m,0);
		cout<<ans<<endl;
		return 0;
	}
	if(flag==1){
		f();
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+n,cmp2);
	ans=int(floor(m/(a[1].x+a[1].y)))*2;
	m=m-int(floor(m/(a[1].x+a[1].y)))*(a[1].x+a[1].y);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(m>=a[i].x){
			m-=a[i].x;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
