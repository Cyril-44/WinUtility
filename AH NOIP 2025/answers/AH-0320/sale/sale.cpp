#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353;
int ans,g[5005]={1};
int C,T,n,m,a[5005];
void solveA(){
    sort(a+1,a+n+1);
    int pos=upper_bound(a+1,a+n+1,a[n]/2)-a;
    for(int i=pos;i<n;i++){
        int pos1=lower_bound(a+1,a+n+1,a[n]-a[i])-a-1;
        if(pos1<n)ans=(ans+g[pos1])%P;
    }
    ans=(g[n]-ans+P)%P;
}
void solveB(){
    sort(a+1,a+n+1);
    ans=g[n];
    if(a[1]*2>a[2]&&a[1]<a[2])ans=(ans-1+P)%P;
}
int b[20];
struct p{
    int v,x;
};
bool cmp(p a,p b){
    if(a.v*b.x==a.x*b.v)return a.x>b.x;
    return a.v*1.0/a.x>b.v*1.0/b.x;
}
void dfs(int t){
    if(t==n+1){
        vector<int> g1,g3;
        vector<p> g2;
        int t1=0;
        for(int i=n;i>=1;i--){
            g2.push_back({a[i],b[i]});
            if(b[i]==1){
                if(!t1)t1=a[i];
                else g1.push_back(t1+a[i]),t1=0;
            }else g1.push_back(a[i]);
        }
        sort(g2.begin(),g2.end(),cmp);
        int ans1=0,ans2=0,tmp=m,tmp1=0,sum=0;
        for(int i=0;i<n;i++){
            if(g2[i].x<=tmp){
                ans1+=g2[i].v;
                tmp-=g2[i].x;
            }
        }
        tmp=m;
        sort(g1.begin(),g1.end());
        for(int i=g1.size()-1;i>=0;i--){
            if(tmp>=2){
                tmp-=2;
                ans2+=g1[i];
            }
        }
        if(tmp==1)ans2+=t1;
        if(ans1<ans2)ans++;
        return ;
    }
    b[t]=1;
    dfs(t+1);
    b[t]=2;
    dfs(t+1);
}
void solve(){
    sort(a+1,a+n+1);
    dfs(1);
    ans=(g[n]-ans+P)%P;
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    for(int i=1;i<=5000;i++)g[i]=g[i-1]*2%P;
    cin>>C>>T;
    while(T--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(C>=7&&C<=9||C>=14&&C<=15)solveA();
        else if(C==16||C==18)ans=g[n];
        else if(C==17)solveB();
        else solve();
        if(n==1)ans=1;
        cout<<ans<<endl;
    }
    return 0;
}
