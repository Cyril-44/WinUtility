#include<bits/stdc++.h>
using namespace std;
long long n,m;
bool f1=1,f2=1;
int x[100010],y[100010];
int a[100010];
int ans=0;
void dfs(int nm,int s){
    ans=max(ans,s);
    for(int i=1;i<=n;i++){
        int t;
        if(a[i]%2==0) t=x[i];
        if(a[i]%2==1) t=y[i];
        if(nm>=t){
            a[i]++;
            dfs(nm-t,s+1);
            a[i]--;
        }
    }
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        if(x[i]!=y[i]) f1=0;
        if(x[i]<y[i]) f2=0;
    }
    if(f1==1){
        sort(x+1,x+n+1);
        cout<<floor(m*1.0/x[1]);
    }else if(n<=10){
        dfs(m,0);
        cout<<ans;
    }else{
        int mn=2000000010,mnid;
        for(int i=1;i<=n;i++){
            if(x[i]+y[i]<mn){
                mn=x[i]+y[i];
                mnid=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(x[i]<=mn/2&&x[i]<=m){
                m-=x[i];
                ans++;
                x[i]=y[i];
            }
        }
        ans=ans+2*floor(m*1.0/mn);
        m-=(floor(m*1.0/mn)*mn);
        sort(x+1,x+n+1);
        for(int i=1;i<=n;i++){
            if(m>=x[i]){
                m-=x[i];
                ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}
