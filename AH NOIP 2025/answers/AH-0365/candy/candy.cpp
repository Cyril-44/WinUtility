#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fir first
#define sec second
using namespace std;
int n,m,mn=2e18,id;
PII a[100005];
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int minn2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].fir>>a[i].sec;
        mn=min(mn,a[i].fir+a[i].sec);
        minn2=min(minn2,a[i].fir+a[i].sec+a[i].fir);
    }
    sort(a+1,a+1+n);
    int s=0;
    int ans=m/mn*2;
    for(int i=1;i<=n;i++){
        s+=a[i].fir;
        ans=max(ans,(m-s)/mn*2+i);
    }
    cout<<ans;
    return 0;
}
