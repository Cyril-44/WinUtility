#include<bits/stdc++.h>
using namespace std;
long long cc,t,n,m,a[5005],v[5005];
long long dp[5005],ans;
struct node{
    double num;
    long long yuan,xian,id;
}c[5005];
bool cmp(node x,node y){
    if(x.num!=y.num)  return x.num>y.num;
    else if(x.yuan!=y.yuan) return x.yuan>y.yuan;
    else return x.id<y.id;
}
void dfs(int k){
    if(k==n+1){
        for(int i=1;i<=n;i++){
            c[i].num=a[i]/v[i];
            c[i].yuan=a[i];
            c[i].xian=v[i];
            c[i].id=i;
        }
        sort(c+1,c+n+1,cmp);
        long long mony=m,sum=0;
        for(int i=1;i<=n;i++){
            if(c[i].xian<=mony){
                mony-=c[i].xian;
                sum+=c[i].yuan;
            }
            if(mony==0){
                break;
            }
        }
        for(int i=0;i<=m;i++){
            dp[i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=m;j>=c[i].xian;j--){
                dp[j]=max(dp[j],dp[j-c[i].xian]+c[i].yuan);
            }
        }
        if(dp[m]==sum){
            ans++;
        }
        return;
    }
    v[k]=1;
    dfs(k+1);
    v[k]=2;
    dfs(k+1);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>cc>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        if(cc>=0&&cc<=5){
            ans=0;
            dfs(1);
            cout<<ans<<"\n";
        }else if(m==2){
            long long num=1;
            for(int i=1;i<=n;i++){
                num*=2;
                num%=998244353;
            }
            if(a[n]>=a[n-1]*2){
                cout<<num<<"\n";
            }else{
                long long ans=0;
                for(int i=n-1;i>=1;i--){
                    for(int j=i-1;j>=1;j--){
                        if(a[i]*2<=a[n]){
                            break;
                        }
                        if(a[i]+a[j]<a[n]){
                            long long sum=1;
                            for(int k=j-1;k>=1;k--){
                                sum*=2;
                                sum%=998244353;
                            }
                            ans+=sum;
                            ans%=998244353;
                        }
                    }
                }
                cout<<(num-ans+998244353)%998244353<<"\n";
            }
        }
    }
    return 0;
}
//ll
