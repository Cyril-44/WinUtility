#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005],b[5005],C,t,n,m,ans;
struct node{
    int x,y;
}c[5005];
int cmp(node a,node b){
    double h1,h2;
    h1 = 1.0*a.x/a.y;
    h2 = 1.0*b.x/b.y;
    if(h1!=h2){
        return h1>h2;
    }
    return a.x>b.x;
}
void dfs(int now){
    if(now>n){
        for(int i = 1;i<=n;i++){
            c[i].x = a[i];
            c[i].y = b[i];
        }
        sort(c+1,c+n+1,cmp);
        int lst,min1,min2,i,x;
        lst = m;
        min1 = 1e18;
        min2 = 1e18;
        x = -1e18;
        for(i = 1;i<=n && lst;i++){
            if(lst>=c[i].y){
                lst = lst-c[i].y;
                if(c[i].y == 1){
                    if(c[i].x<min1){
                        min2 = min1;
                        min1 = c[i].x;
                    }else{
                        min2 = min(min2,c[i].x);
                    }
                }
            }else{
                x = max(x,c[i].x);
            }
        }
        int f;
        f = 1;
        if(x!=-1e18){
            if(lst && min1<x || !lst && min1+min2<x){
                f = 0;
            }
        }else{
            for(;i<=n;i++){
                if(c[i].y == 2){
                    if(lst){
                        if(min1<c[i].x){
                            f = 0;
                        }
                    }else{
                        if(min1+min2<c[i].x){
                            f = 0;
                        }
                    }
                    break;
                }
            }
        }
        ans = ans+f;
        return;
    }
    b[now] = 1;
    dfs(now+1);
    b[now] = 2;
    dfs(now+1);
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 1;i<=n;i++){
            cin>>a[i];
        }
        ans = 0;
        dfs(1);
        cout<<ans<<"\n";
    }
    return 0;
}
