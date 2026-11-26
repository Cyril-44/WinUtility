#include<iostream>
using namespace std;
#define ll long long
const int N=1e5+5;
const int M=1e4+5;
const ll inf=1e18+5;
ll n,m,a[N][2],dp[N],lst[N];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][0];
		}
	for(int i=1;i<=N;i++){
		dp[i]=lst[i]=inf;
	}
	dp[0]=lst[0]=0;
	int cnt=0,l=1,r=1,ans=0;
	for(int i=1;i<=n;i++){
		cnt=0;l=r=1;
		for(int j=1;;j++){
			ll t=lst[j-1]+a[i][(cnt+1)%2];
			if(t<=dp[j] && t<=m){
				cnt++;r=j;
				lst[j]=t;
			}
			else
			{
				cnt=0;
				if(r<ans)	l=r=0;
				lst[j]=dp[j];
			}
			if(dp[j-1]+a[i][1]<=dp[j] && dp[j-1]+a[i][1]<=t){
				if(dp[j-1]+a[i][1]<=m){
					l=r=j;cnt=1;
					lst[j]=dp[j-1]+a[i][1];
				}
			}
			if(t>m && dp[j-1]+a[i][1]>m)	break;
		}
		ans=max(ans,r);
		for(int j=l;j<=r;j++){
			if(j>=l && j<=r){
				dp[j]=lst[j];
			}
			else
			{
				dp[j]=inf;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
