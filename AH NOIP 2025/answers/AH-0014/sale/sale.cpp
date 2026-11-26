/*

   * Happy Zenith Noises *

         2025.11.29

*/
#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int>P;
const int MAXN=1005,inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
int A[MAXN],B[MAXN],cc[MAXN][2];
int C,T,ans;
int bb[MAXN];
int n,m,a[MAXN];
P fs[MAXN];
int c(int x,int y){return A[y]*B[x]%mod*B[y-x]%mod;}
void add(int &x,int y){x=(x+y)%mod;}
int pw(int base,int t){
    int ans=1;
    while(t){
        if(t&1)ans=ans*base%mod;
        base=base*base%mod,t>>=1;
    }
    return ans;
}
int check(){
    if(m==1)return 1;
    for(int i=1;i<=n;i++)fs[i]={(2-bb[i])*a[i],a[i]};
    sort(fs+1,fs+1+n);reverse(fs+1,fs+1+n);
    int tm=m,lst=-1;
    for(int i=1;i<=n;i++){
        int fu=1;
        if(fs[i].fi==fs[i].se)fu=2;
        if(tm<fu){
            if(lst==-1)return 1;
            for(int j=i+1;j<=n;j++)if(fs[j].fi!=fs[j].se){
                if(fs[j].se+lst>=fs[i].se)return 1;
                return 0;
            }
            return 1;
        }
        else{
            tm-=fu;
            if(fu==1)lst=fs[i].se;
        }
        if(tm==0)return 1;
    }
    return 1;
}
void dfs(int x){
    if(x==n+1){
        ans+=check();
        return ;
    }
    bb[x]=0;
    dfs(x+1);
    bb[x]=1;
    dfs(x+1);
}
void solve(){
    cin>>n>>m;ans=0;int fb=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<=500000000)fb=0;
    }
    sort(a+1,a+1+n);reverse(a+1,a+1+n);
    if(n<=10){
        dfs(1);
    }
    else if(C==10||C==11||C==12||C==19||C==20){

    }
    else if(m<=2){
        for(int i=2;i<=n;i++){
            if(a[i]*2<=a[1]){
                add(ans,pw(2,n-i+1));
                break;
            }
        }
        //cout<<ans<<'\n';
        for(int i=2;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[j]*2>a[1]&&a[i]+a[j]>=a[1])add(ans,pw(2,n-j));
            }
        }
        //cout<<ans<<'\n';
        for(int i=2;i<=n;i++)add(ans,pw(2,n-i));
        add(ans,1);
    }
    else if(fb){
        for(int i=0;i<=n;i+=2)add(ans,c(i,n));
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(a[i]!=a[j])break;
                for(int k=j+1;j<=n;k++){
                    if(a[k]!=a[i])break;

                }
            }
        }
    }
    else if(m==2*n-1){

    }
    else if(m==2*n-2){

    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(nullptr);
    A[0]=B[0]=1;
    for(int i=1;i<MAXN;i++)A[i]=A[i-1]*i%mod,B[i]=B[i-1]*pw(i,mod-2)%mod;
    for(int i=0;i<MAXN;i++)for(int j=0;j<=i;j++)add(cc[i][j%2],c(i,j));
    cin>>C>>T;
    while(T--)solve();
    return 0;
}


