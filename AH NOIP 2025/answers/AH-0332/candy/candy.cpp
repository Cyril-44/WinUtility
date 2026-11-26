#include<bits/stdc++.h>
using namespace std;
const int N=100005,N1=1002,M1=10005,oo=1000000005;
int n,m,x[N],y[N],dp[2][2][M1];
void work1(){
	int p=0,q=1;
    for(int i=1;i<=n;i++,swap(p,q)){
		for(int j=1;j<=m;j++) dp[p][1][j]=max(dp[q][0][j],dp[q][1][j]);
	    for(int j=x[i];j<=m;j++){
		    dp[p][0][j]=dp[p][1][j-x[i]]+1;
		    if(j>=y[i]) dp[p][1][j]=max(dp[p][1][j],dp[p][1][j-y[i]]+2);
		}
	}
	printf("%d",max(dp[q][0][m],dp[q][1][m]));
}
void work2(){
    sort(x+1,x+1+n),sort(y+1,y+1+n); 
    int ans=m/y[1]*2;
    if(x[1]<=m-m/y[1]*y[1]) ans++;
    printf("%d",ans);
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d%d",&n,&m); 
    int xx=1;
    for(int i=1;i<=n;i++){
	    scanf("%d%d",&x[i],&y[i]);
	    if(x[i]<y[i]) xx=0;
	    y[i]+=x[i];
	}
	if(n<=N1&&m<=M1) work1();
	else if(xx==1) work2();
    return 0;
}
