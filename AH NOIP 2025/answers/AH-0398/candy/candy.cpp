#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m;
struct node{
	int x,y;
}a[N];
bool cmp(node a,node b){
	if(a.x!=b.x)return a.x<b.x;
	return a.y<b.y;
}
int dp[1005][10005];
int read(){
	int num=0,fh=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')fh*=-1;
		ch=getchar();
	}while(isdigit(ch)){
		num=num*10+ch-'0';
		ch=getchar();
	}
	return num*fh;
}
int ans;
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10){
		write(x/10);
		putchar((x%10)+'0');
	}else{
		putchar(x+'0');
	}
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	n=read(),m=read();
	bool flag=1;
	int minn=1e9;
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
		if(a[i].x!=a[i].y)flag=0;
		minn=min(minn,a[i].x);
	}
	if(flag){
		cout<<(m/minn);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int k=max(dp[i][j-1],dp[i-1][j]);
			dp[i][j]=max(dp[i][j],k);
			int sum=0,tj=j,maxn=dp[i-1][j];
			while(tj>=a[i].x){
				sum++;
				tj-=a[i].x;
				maxn=max(maxn,dp[i-1][tj]+sum);
				if(tj>=a[i].y){
					sum++;
					tj-=a[i].y;
					maxn=max(maxn,dp[i-1][tj]+sum);
				}else{
					break;
				}
			}
			dp[i][j]=max(dp[i][j],maxn);
			ans=max(ans,dp[i][j]);
		}
	}
	write(ans);
	return 0;
}
