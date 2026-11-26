#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int n,m;
const int N=1e5+5;
struct node{ int x,y,sum;} a[N];
priority_queue<pii,vector<pii>,greater<pii> > q;
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    int sumx=0,sumy=0;
    int ans=0,minsum=1e18;
    for(int i=1;i<=n;i++) {
        cin>>a[i].x>>a[i].y;
        a[i].sum=a[i].x+a[i].y;
        minsum=min(minsum,a[i].sum);
        sumx+=a[i].x;
        sumy+=a[i].y;
        q.push(make_pair(a[i].x,i));
    }
//    ans=(m/minsum)*2;
//    m%=minsum;
    while(q.size()){
        pii u=q.top(); q.pop();
        int v=u.first,id=u.second;
        if(v>m) break;
        m-=v; ans++;
        if(v==a[id].x) q.push(make_pair(a[id].y,id));
        else q.push(make_pair(a[id].x,id));
    }
    cout<<ans;
    return 0;
}

