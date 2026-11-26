#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,m;
double minn=1e9+10,t=2;
bool vis[N];
struct kx{
    double x,y;
    double ave;
}a[N];
bool cmp2(kx g,kx h){
    return g.x<h.x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].ave=(a[i].x+a[i].y)/t;
        minn=min(minn,a[i].ave);
    }
    bool f=0;
    long long ans=0;
    sort(a+1,a+1+n,cmp2);
    for(int i=1;i<=n;i++){
        if(a[i].x>=minn) break;
        if(m<a[i].x) break;
        vis[i]=1;
        ans++;
        m-=a[i].x;
    }
    while(m>=t*minn){
        m-=t*minn;
        ans+=t;
    }
    long long k=m,ans2=ans,maxn=0;
    for(int i=1;i<=n;i++) if(vis[i]&&k+a[i].x>=t*minn){ans2++;break;}
    for(int i=1;i<=n;i++){
        if(vis[i]==1&&a[i].y<=m){
            ans++;
            m-=a[i].y;
        }
        if(!vis[i]&&a[i].x<=m){
            ans++;
            m-=a[i].x;
        }
    }
    cout<<max(ans,ans2)<<endl;
    return 0;
}
