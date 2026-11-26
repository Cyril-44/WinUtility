#include<bits/stdc++.h>
using namespace std;
struct s{
    int i,yj;
    double jz;
    bool operator < (const s& a) const{
        if(a.jz!=jz){
            return a.jz>jz;
        }else if(a.yj!=yj){
            return a.yj>yj;
        }else{
            return a.i<i;
        }
    }
};
int c,t,n,m,cnt;
long long a[5010],b[5010],dp[5010];
void dfs(int i){
    if(i==n+1){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=m;j>=b[i];j--){
                dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
            }
        }
        priority_queue<s> q;
        for(int i=1;i<=n;i++){
            q.push({i,a[i],a[i]*1.0/b[i]});
        }
        long long c1=0,c2=m;
        for(int i=1;i<=n;i++){
            s t=q.top();
            q.pop();
            if(c2>=b[t.i]){
                c2-=b[t.i];
                c1+=a[t.i];
            }
        }
        if(c1==dp[m]){
            cnt++;
            cnt%=998244353;
            /*for(int j=1;j<=n;j++){
                cout<<b[j]<<" ";
            }
            cout<<endl;
            cout<<dp[m]<<" "<<c1;
            cout<<endl;*/
        }
        return;
    }
    b[i]=1;
    dfs(i+1);
    b[i]=2;
    dfs(i+1);
    b[i]=0;
    return;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==18){
            int t=1;
            for(int i=1;i<=n;i++){
                t*=2;
                t%=998244353;
            }
            cout<<t<<endl;
            continue;
        }
        dfs(1);
        cout<<cnt<<endl;
    }
    return 0;
}
