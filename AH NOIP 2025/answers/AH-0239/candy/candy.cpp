#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll m,ans;
bool jo[N];
int n;
queue <ll> q;
struct node{
	int x,y;
}A[N];
bool cmp(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
void dfs(ll a,ll k){
	if(a==m){
		ans=max(ans,k);
		//exit(0);
		return;
	}
	//sort(A+1,A+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a+A[i].x<=m){
			swap(A[i].x,A[i].y);
			dfs(a+A[i].y,k+1);
		}
	}
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&A[i].x,&A[i].y);
	}
	dfs(0,0);
	cout<<ans;
}
