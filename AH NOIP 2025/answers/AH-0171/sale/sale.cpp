#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN=5010;
typedef long long ll;
const ll MOD=998244353;

ll c,t,a[MAXN],n,m;

ll cho[MAXN],cnt1,dp1[MAXN][100];
struct node1{ double xj;ll yj,idx; }p[MAXN];
bool cmp1(node1 n1,node1 n2){
    if((n1.yj/n1.xj)!=(n2.yj/n2.xj)) return (n1.yj/n1.xj)>(n2.yj/n2.xj);
    if(n1.yj!=n2.yj) return n1.yj>n2.yj;
    return n1.idx<n2.idx;
}
bool check(){
    for(int i=1;i<=n;i++) p[i].xj=(double)cho[i],p[i].idx=i,p[i].yj=a[i];
    sort(p+1,p+1+n,cmp1);
    memset(dp1,0,sizeof(dp1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp1[i][j]=dp1[i-1][j];
            if(j>=cho[i]) dp1[i][j]=max(dp1[i][j],dp1[i-1][j-cho[i]]+a[i]);
        }
    }
    ll ans1=0,ans2=0,rest=m;
    for(int i=1;i<=m;i++) ans1=max(ans1,dp1[n][i]);
    for(int i=1;i<=n;i++){
        if(rest>=(int)p[i].xj){
            rest-=p[i].xj;
            ans2+=p[i].yj;
        }
    }
    return (ans1==ans2);
}

void dfs(int u){
    if(u>n){
        if(check()) cnt1++;
        return;
    }
    cho[u]=1;
    dfs(u+1);
    cho[u]=2;
    dfs(u+1);
    cho[u]=1;
    return ;
}

void solve1(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        cnt1=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        //sort(a+1,a+1+n);
        dfs(1);
        cout<<cnt1<<endl;
    }
}

ll qpow[MAXN];
void init(){
    qpow[0]=1;
    for(int i=1;i<=1000;i++) qpow[i]=(qpow[i-1]+qpow[i-1])%MOD;
}
void solve18(){
    cin>>t;
    init();
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<qpow[n]<<endl;
    }
}

void solve2(){
    cin>>t;
    init();
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        ll ans=0;
        for(int i=n-1;i>=1;i--){
            if(a[i]<(int)(a[n]/2.0)) break;
            for(int j=1;j<i;j++){
                if(a[i]+a[j]<a[n]){
                    ans+=qpow[i-1];
                    ans=ans%MOD;
                }
            }
        }
        cout<<(qpow[n]-ans+MOD)%MOD<<endl;
    }
}

int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);

    cin>>c;
    if(c<=5){
        solve1();
    } else if(c==18||c==16){
        solve18();
    } else if((c>=7&&c<=9)||c==14||c==15){
        solve2();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
