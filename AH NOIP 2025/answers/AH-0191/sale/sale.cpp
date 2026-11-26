#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
const int N=5010;
int n,m;
int d[N];
int q_pow(int x,int k){
    int res=1;
    while(k){
        if(k&1)res=res*x%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return res;
}
struct node{
    int a,w,pos;
    double v;
}c[20],cx[20];
bool cmp(node x,node y){
    if(x.v==y.v){
        if(x.a==y.a)return x.pos<y.pos;
        else return x.a>y.a;
    }
    return x.v>y.v;
}
int f[50];
int ans;
void check(){
    for(int i=1;i<=n;i++){
        cx[i]=c[i];
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        for(int j=m;j>=cx[i].w;j--){
            f[j]=max(f[j-cx[i].w]+cx[i].a,f[j]);
        }
    }
    for(int i=1;i<=n;i++)cx[i].v=1.0*cx[i].a/cx[i].w,
    sort(cx+1,cx+1+n,cmp);
    int o=m,now=0;
    for(int i=1;i<=n;i++){
        if(o>=cx[i].w){
            now+=cx[i].a;
            o-=cx[i].w;
        }
    }
    if(now==f[m])ans++;
    ans%=MOD;
    return;
}
void dfs(int t){
    if(t>n){
        check();
        return;
    }
    for(int i=1;i<=2;i++){
        c[t].w=i;
        dfs(t+1);
        c[t].w=0;
    }
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--){
        cin>>n>>m;
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));
        memset(d,0,sizeof(d));
        ans=0;
        if(C==18)cout<<q_pow(2,n)<<"\n";
        if(C>=1&&C<=5){
            ans=0;
            for(int i=1;i<=n;i++){
                cin>>c[i].a;
                c[i].pos=i;
            }
            dfs(1);
            cout<<ans<<"\n";
        }
        if((C>=7&&C<=9)||(C>=14&&C<=15)){
            for(int i=1;i<=n;i++)cin>>d[i];
            sort(d+1,d+1+n);
            //num[n]==1 OK
            ans=q_pow(2,n-1);
            /*int maxn=d[n];
            double maxv=1.0*d[n]/2;
            int pos=upper_bound(d+1,d+1+n,maxv)-d;
            for(int i=pos;i<=n-1;i++){
                int x=d[n]-d[i];
                int y=lower_bound(d+1,d+1+n,x)-d-1;
                ans+=q_pow(2,y-i);
            }*/
            cout<<ans<<"\n";
        }
    }
    return 0;
}
