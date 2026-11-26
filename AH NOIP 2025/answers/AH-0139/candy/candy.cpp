#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m,v1[100010],v2=1,ans,vcnt;

int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    v2<<=62;
    cin>>n>>m;
    int y=0;
    for(int i=1;i<=n;i++){//最小一组糖果价格
        cin>>v1[i]>>y;
        v2=min(v2,v1[i]+y);
    }
    sort(v1+1,v1+n+1);
   // cout<<v1[1]<<' '<<v2<<endl;
    for(int i=0;i<=n;i++){
        vcnt+=v1[i];
        if(vcnt>m)break;
        ans=max(ans,((m-vcnt)/v2)*2+i);
    }
    cout<<ans<<endl;
    return 0;
}
//9:14 finished
