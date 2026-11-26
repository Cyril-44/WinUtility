#include<bits/stdc++.h>
using namespace std;
struct node{
    double s,p;
    long long di,id;
}b[15];
struct node1{
    long long s,id;
}q[5005];
long long n,m,c,T,ans;
long long f[15][25];
long long a[5005];
bool cmp(long long x,long long y){
    return x>y;
}
bool cmp1(node x,node y){
    if(x.p!=y.p)
        return x.p>y.p;
    if(x.s!=y.s)
        return x.s>y.s;
    return x.id<y.id;
}
bool cmp2(node1 x,node1 y){
    if(x.s!=y.s)
        return x.s>y.s;
    return x.id<y.id;
}
int path[15];
void dfs(int cur){
    if(cur>n){
        for(int i=1;i<=n;i++){
            b[i].s=a[i];
            b[i].p=b[i].s/path[i];
            b[i].di=path[i];
            b[i].id=i;
        }
        long long u=m,sum=0;
        sort(b+1,b+1+n,cmp1);
        for(int i=1;i<=n;i++){
            if(u<b[i].di)
                continue;
            u-=b[i].di;
            sum+=b[i].s;
        }
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                f[i][j]=f[i-1][j];
                if(j>=b[i].di){
                    f[i][j]=max(f[i][j],f[i-1][j-b[i].di]+(long long)b[i].s);
                }
            }
        }
        if(sum==f[n][m]){
            ans++;
            ans%=998244353;
        }
        return ;
    }
    path[cur]=1;
    dfs(cur+1);
    path[cur]=2;
    dfs(cur+1);
    return ;
}
void solve(){
    sort(q+1,q+1+n,cmp2);
    ans=1;
    for(int i=2;i<=n;i++){
        ans*=2;
        ans%=998244353;
    }
    for(int i=2;i<=n;i++){
        if(q[i].s*2<=q[1].s){
            long long ta=1;
            for(int j=i;j<=n;j++){
                ta*=2;
                ta%=998244353;
            }
            ans+=ta;
            ans%=998244353;
            return ;
        }
        long long tmp=q[1].s-q[i].s,l=0;
        for(int j=i+1;j<=n+1;j++){
            if(a[j]<tmp){
                l=j-1;
                break;
            }
        }
        long long ta=1;
        for(int j=i+1;j<=l;j++){
            ta*=2;
            ta%=998244353;
        }
        ta--;
        for(int j=l+1;j<=n;j++){
            ta*=2;
            ta%=998244353;
        }
        ans+=ta;
        ans%=998244353;
    }
    return ;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>T;
    while(T--){
        memset(a,0,sizeof(a));
        ans=0;
        cin>>n>>m;
        bool fu=1;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            if(i>=2){
                if(a[i]!=a[i-1])
                    fu=0;
            }
            q[i].s=a[i],q[i].id=i;
        }
        sort(a+1,a+1+n,cmp);
        if(n<=10){
            dfs(1);
            cout<<ans<<endl;
            continue;
        }
        if(m==2*n-1||fu==1){
            ans=1;
            for(int i=1;i<=n;i++){
                ans*=2;
                ans%=998244353;
            }
            cout<<ans<<endl;
            continue;
        }
        if(m==2){
            solve();
            cout<<ans<<endl;
            continue;
        }
        if(m==2*n-2){
            ans=1;
            for(int i=1;i<=n;i++){
                ans*=2;
                ans%=998244353;
            }
            if(a[n]*2>a[n-1]&&a[n]!=a[n-1]){
                ans--;
                ans%=998244353;
            }
            cout<<ans<<endl;
            continue;
        }
        if(m!=2*n-1&&m!=2*n-2&&m!=2&&fu==0&&n>10){
            ans=1;
            for(int i=1;i<=n;i++){
                ans*=2;
                ans%=998244353;
            }
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
