#include<bits/stdc++.h>
#define N 5005
using namespace std;
int n,c,t,m,ans;
long long a[N],dp[N];
struct C{
    int v,w,id;
}b[N];
short w[N];
void dfs(int k){
    if(k==n+1){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=m;j>=w[i];j--)
                dp[j]=max(dp[j],dp[j-w[i]]+a[i]);
        long long mx=0;
        for(int i=1;i<=m;i++)
            mx=max(mx,dp[i]);
        for(int i=1;i<=n;i++)
            b[i].v=a[i],b[i].w=w[i],b[i].id=i;
        sort(b+1,b+1+n,[](C x,C y){
            if(x.v/x.w!=y.v/y.w)
                return x.v/x.w>y.v/y.w;
            if(x.v!=y.v)
                return x.v>y.v;
            return x.id<y.id;
        });
        int res=m;
        long long tmp=0;
        for(int i=1;i<=n;i++)
            if(res>=b[i].w){
                res-=b[i].w;
                tmp+=b[i].v;
            }
        ans+=(tmp==mx);
        return;
    }
    w[k]=1;
    dfs(k+1);
    w[k]=2;
    dfs(k+1);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(register int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            a[i]<<=1;
        }
        ans=0;
        dfs(1);
        printf("%d\n",ans%998244353);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
