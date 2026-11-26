#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int p,t,n,m,a[N],b[N],ans;
long long f[2*N];
struct can{
    int x,y,id;
}c[N];
bool cmp(can s,can t){
    if(s.x*t.y!=t.x*s.y) return s.x*t.y>t.x*s.y;
    if(s.x!=t.x) return s.x>t.x;
    return s.id<t.id;
}
void dfs(int x){
    if(x==n+1){
        for(int i=1;i<=n;i++){
            c[i]={a[i],b[i],i};
        }
        sort(c+1,c+n+1,cmp);
        long long s=0,sum=0;
        for(int i=1;i<=n;i++){
            if(s+c[i].y<=m){
                s+=c[i].y;
                sum+=c[i].x;
            }
        }
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            for(int j=m;j>=c[i].y;j--){
                f[j]=max(f[j],f[j-c[i].y]+c[i].x);
            }
        }
        if(f[m]==sum){
            //for(int i=1;i<=n;i++) cout<<b[i]<<" ";
            //cout<<"\n";
            ans=(ans+1)%mod;
        }
        return ;
    }
    b[x]=1;
    dfs(x+1);
    b[x]=2;
    dfs(x+1);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>p>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=0;
        dfs(1);
        cout<<ans<<"\n";
    }
    return 0;
}
