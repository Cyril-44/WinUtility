#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[100005],ans,f[20],ret;
const long long mod=998244353;
struct node{
    long long w,id;
}now[20];
bool cmp(node x,node y){
    if(x.w!=y.w){
        return x.w>y.w;
    }
    else if(a[x.id]!=a[y.id]){
        return a[x.id]>a[y.id];
    }
    else{
        return x.id<y.id;
    }
}
void check(long long x,long long lft,long long v){
    if(x>n){
        ret=max(ret,v);
        return;
    }
    check(x+1,lft,v);
    if(lft>=f[x]){
        check(x+1,lft-f[x],v+a[x]);
    }
}
void dfs1(long long x){
    if(x>n){
        for(int i=1;i<=n;i++){
            now[i].w=a[i]/f[i];
            now[i].id=i;
        }
        sort(now+1,now+1+n,cmp);
        long long m2=m,sum=0;
        for(int i=1;i<=n;i++){
            long long p=now[i].id;
            if(m2>=f[p]){
                sum+=a[p];
                m2-=f[p];
            }
        }
        ret=0;
        check(1,m,0);
        if(sum==ret){
            ans++;
        }
        return;
    }
    f[x]=1;
    dfs1(x+1);
    f[x]=2;
    dfs1(x+1);
}
long long qpow(long long a,long long b){
    long long ret=1;
    while(b){
        if(b&1){
            ret*=a;
            ret%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]*=2LL;
        }
        if(m==2LL*n-1LL){
            cout<<qpow(2,n)<<'\n';
            continue;
        }
        if(n<=10){
            ans=0;
            dfs1(1);
            cout<<ans<<'\n';
        }
        else{
            cout<<qpow(2,n-1)<<'\n';
        }
    }
    return 0;
}
