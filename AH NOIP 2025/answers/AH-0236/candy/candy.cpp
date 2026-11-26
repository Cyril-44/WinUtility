#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1005
#define M 100005
ll n,m,x[N],y[N],f[M],d;
struct node{
    ll id,w;
}g[2*N];
bool cmp(node x,node y){
    if(x.w!=y.w)
        return x.w<y.w;
    return x.id<y.id;
}
bool flag;
ll minn=0x3f3f3f3f;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld %lld",&x[i],&y[i]);
        if(x[i]!=y[i])
            flag=1;
        minn=min(minn,x[i]);
        g[i].w=x[i]+y[i];
        g[i].id=i;
    }
    if(!flag){
        cout<<m/minn;
        return 0;
    }
    for(int i=1;i<=n;i++){
        g[n+i].w=x[i];
        g[n+i].id=n+i;
    }
    for(int i=1;i<=n;i++){
        for(ll j=g[i].w;j<=m;j++){
            f[j]=max(f[j],f[j-g[i].w]+2);
        }
    }
    for(int i=n+1;i<=2*n;i++){
        for(ll j=m;j>=g[i].w;j--){
            f[j]=max(f[j],f[j-g[i].w]+1);
        }
    }
    printf("%lld",f[m]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
