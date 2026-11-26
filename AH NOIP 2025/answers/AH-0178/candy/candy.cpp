#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=1e18,id,mony,ans,sum,num,cnt;
struct node{
    long long x,y,id;
}a[100005];
bool cmp(node a,node b){
    return a.x<b.x;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(a[i].x+a[i].y<maxx){
            maxx=a[i].x+a[i].y;
            id=i;
        }
    }
    ans=m/maxx*2;
    if(a[id].x<=m-ans/2*maxx){
        ans++;
    }
    for(int i=1;i<=n;i++){
        if(i!=id){
            cnt++;
            m-=a[i].x;
            num=m/maxx*2;
            if(a[id].x<=m-num/2*maxx){
                num++;
            }
            ans=max(ans,num+cnt);
        }
    }
    cout<<ans;
    return 0;
}
