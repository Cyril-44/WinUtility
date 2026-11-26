#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e4+5;
const long long mod = 998244353;

long long T,c;
long long ans=0;
long long n,m,rm=0;
struct node{
    long long a=0;
    long long w=0;
    long long b=0;
    bool operator<(node o){
        return w<o.w;
    }
};
node z[maxn];
long long nb[maxn];

bool mycmp(node x,node y){
    if(x.w>y.w)
        return 1;
    if(x.w==y.w&&x.a>y.a)
        return 1;
    return 0;
}

long long tong[maxn];
long long f[maxn];
long long cnt = 0;
long long cnt2 = 0;

void pd(){
    memset(f,0,sizeof(f));
    cnt=0;
    cnt2=0;
    m=rm;
    for(long long i=1;i<=n;i++){
        z[i].a=nb[i];
        z[i].w=z[i].a*2;
        z[i].w=z[i].w/tong[i];
        z[i].b=tong[i];
    }
    sort(z+1,z+n+1,mycmp);
    for(long long i=1;i<=n;i++){
        if(m-z[i].b>=0){
            cnt+=z[i].a;
            cnt=cnt%mod;
            m=m-z[i].b;
        }
    }
    // cout << cnt << endl;
    m=rm;
    for(long long i=1;i<=n;i++){
        for(long long j=m;j>=z[i].b;j--){
            if(f[j]<f[j-z[i].b] + z[i].a)
                f[j]=f[j-z[i].b] + z[i].a;
        }
    }
    f[m]=f[m]%mod;
    // cout << cnt << " " << f[m] << endl;
    if(cnt==f[m]){
        ans++;
        // cout << "1" << endl;
    }
    // else{
    //     // for(long long i=1;i<=n;i++){
    //     //     cout << tong[i] << " ";
    //     // }
    //     // cout << endl;
    // }
}

void dfs(long long dep){
    if( dep > n ){
        // for(long long i=1;i<=n;i++){
        //     cout << tong[i] << " ";
        // }
        // cout << endl;
        pd();
        return;
    }
    for(long long i=1;i<=2;i++){
        tong[dep]=i;
        dfs(dep+1);
    } 
}

int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while(T--){
        ans=0;
        cnt=0;
        memset(tong,0,sizeof(tong));
        cin >> n >> m;
        rm=m;
        for(long long i=1;i<=n;i++){
            z[i].a=0;
            z[i].w=0;
            z[i].b=0;
        }
        for(long long i=1;i<=n;i++){
            cin >> nb[i];
        }
        dfs(1);
        cout << ans << endl;
    }
    return 0;
}