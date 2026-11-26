#include<bits/stdc++.h>
#define int long long
using namespace std;
void in(int &x){
	int f=1;char c=getchar();x=0;
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),f=-1;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=f;
}
int t,n,m,k,x,y,a[100005],b[100005];
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	in(n);in(m);int mn=2e18,ans=0;
	for(int i=1;i<=n;i++)in(a[i]),in(b[i]),mn=min(mn,a[i]+b[i]);
	sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    for(int i=0;i<=n;i++){
    	int r=m-a[i];
    	if(r>=0)ans=max(ans,i+2*(r/mn));
    }
    printf("%lld\n",ans);
}