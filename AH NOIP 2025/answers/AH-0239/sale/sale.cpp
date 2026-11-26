#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+5,mod=998244353;
int n,c,T,u[N],res,dp[N],m,mx,ww,ans,be[N];
struct node{
	int w,st,num,r;
}A[N];
bool cmp(node a,node b){
	if(a.r!=b.r) return a.r>b.r;
	if(a.st!=b.st) return a.st>b.st;
	return a.num<b.num;
}
int DP(){
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(j-u[i]>=0) dp[j]=max(dp[j-u[i]]+be[i],dp[j]);
		}
	}
	//for(int i=1;i<=m;i++) printf("%d ",dp[i]);
	//puts("");
	return dp[m];
}

void dfs(int x,int k){
	if(k>n){
		ww=0,res=0;
		for(int i=1;i<=n;i++){
			A[i].w=u[i];
			A[i].st=be[i];
			A[i].num=i;
			//printf("%d ",A[i].w);
			A[i].r=A[i].st;
			if(A[i].w==1) A[i].r*=2;
		}
		//puts("");
		mx=DP();
		sort(A+1,A+n+1,cmp);
		for(int i=1;i<=n;i++){
			//printf("%d %d %d \n",A[i].st,A[i].w,A[i].r);
			if(res+A[i].w>m) continue;
			res+=A[i].w;
			ww+=A[i].st;
		}
		if(ww==mx) {
			ans++;
			//cout<<'a'<<mx<<' '<<ww<<endl;
		}
		return;
	}
	u[k]=1;
	dfs(1,k+1);
	u[k]=2;
	dfs(2,k+1);
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			be[i]=x;
			A[i].num=i,A[i].st=x;
		}
		dfs(0,0);
		cout<<ans/2%mod;
	}
	
}
/*
3 15
1 7
2 3
3 1
* 
2 10
4 1
3 3
* 
0 1
3 2
1 3 5
*/
