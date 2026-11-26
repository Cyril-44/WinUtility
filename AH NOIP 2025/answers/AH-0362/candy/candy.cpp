#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long m,ans;
int a[N],b[N],num;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    m*=2;
    for(int i=1,x,y;i<=n;i++){
        cin>>x>>y;
        a[i]=x*2;
        b[i]=x+y;
    }
    sort(a+1,a+n+1);
    int minn=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        minn=min(minn,b[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i]>m) break;
        if(a[i]<minn){
            m-=a[i];
            ans++;
        }
    }
    ans+=m/minn;
    cout<<ans;
    return 0;
}
