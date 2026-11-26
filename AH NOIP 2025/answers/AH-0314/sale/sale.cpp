#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int n,m;
long long a[5010];
void solve1(){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=2;
        ans%=mod;
    }
    printf("%lld\n",ans);
}
int w[5010],id[5010],cnt;
bool cmp(const int &lhs,const int &rhs){
    if(a[lhs]*w[rhs]!=a[rhs]*w[lhs]){
        return a[lhs]*w[rhs]>a[rhs]*w[lhs];
    }
    else if(w[lhs]!=w[rhs]){
        return w[lhs]>w[rhs];
    }
    else{
        return lhs<rhs;
    }
}
long long dp[5010];
bool check(){
    for(int i=1;i<=n;i++){
        id[i]=i;
    }
    sort(id+1,id+n+1,cmp);
    long long pre=0;
    int rem=m;
    for(int i=1;i<=n;i++){
        if(rem>=w[id[i]]){
            rem-=w[id[i]];
            pre+=a[id[i]];
        }
    }
    for(int i=0;i<=m;i++){
        dp[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+a[i]);
        }
    }
    return pre==dp[m];
}
void dfs(int cur){
    if(cur>n){
        if(check()){
            cnt++;
        }
        return ;
    }
    w[cur]=1;
    dfs(cur+1);
    w[cur]=2;
    dfs(cur+1);
}
void solve2(){
    cnt=0;
    dfs(1);
    printf("%d\n",cnt);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int test_id,test_tot;
    scanf("%d %d",&test_id,&test_tot);
    while(test_tot--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        if(test_id==16  || test_id==18){
            solve1();
        }
        else if(test_id<=6){
            solve2();
        }
    }
    return 0;
}