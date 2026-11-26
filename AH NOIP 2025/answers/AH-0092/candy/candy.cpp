#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pr pair<ll,ll>
using namespace std;
const int N=1e6+10;
ll n,m,ans,tot,used[N];
pr a[N];
struct node{
    ll val,id,w;
};
bool operator <(const node &x,const node &y){
    return  x.val*y.w>y.val*x.w;
}
priority_queue<node> q;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch <='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i].fi=read(),a[i].se=read();
        q.push({a[i].fi,i,1});
        q.push({a[i].fi+a[i].se,i,2});
    }
    
    while(!q.empty()){
        node x=q.top();
        // cout<<x.val<<" "<<x.id<<" "<<x.w<<endl;
        if(x.w==1){
            q.pop();
            if(used[x.id]) continue;
            if(x.val+tot > m) break;
            used[x.id]=1;
            tot+=x.val; ans++;
        }
        if(x.w==2){
            if(used[x.id]==1){
                if(a[x.id].se+tot > m){
                    q.pop();
                    continue;
                }
                used[x.id]=0;
                tot+=a[x.id].se; ans++;
                q.push({a[x.id].fi,x.id,1});
            }else{
                if(x.val+tot > m){
                    q.pop();
                    continue;
                }
                tot+=x.val;
                ans+=2;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}