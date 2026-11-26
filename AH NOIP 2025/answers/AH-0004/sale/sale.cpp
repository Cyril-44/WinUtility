#include<bits/stdc++.h>
#define M 998244353
using namespace std;
void in(int &x){
	int f=1;char c=getchar();x=0;
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),f=-1;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=f;
}
int t,tid,n,m,k,x,y,a[100005],b[100005],pw[100005],nxt[100005],c[5005][5005];
void solve(){
	in(n);in(m);
	pw[0]=1;for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%M;
	for(int i=1;i<=n;i++)in(a[i]);
	sort(a+1,a+1+n);reverse(a+1,a+1+n);
    a[n+1]=-1;
    for(int i=n,j=n+1;i>=1;i--){
    	while(j-1>i&&a[j-1]*2<=a[i])j--;
    	b[i]=j;
    	if(a[i]==a[i+1])nxt[i]=nxt[i+1];
    	else nxt[i]=i+1;
    }
    int ans=0;
    for(int i=1;i<=n&&i<=m-1;i++){
    	for(int j=nxt[i],k=n+1;j<=b[i]-1;j++){
    		int r=m-1-i;
    		while(a[k-1]<a[i]-a[j])k--;
    		if(r<=j-2){
    			int s=1ll*c[j-2][r]*pw[n-k+1]%M;
    			ans=(ans+s)%M;
    		}
    	}
    }
    ans=(pw[n]-ans+M)%M;
    printf("%d\n",ans);
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	in(tid);in(t);
	for(int i=0;i<=5000;i++){c[i][0]=1;for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;}
	while(t--)solve();
}