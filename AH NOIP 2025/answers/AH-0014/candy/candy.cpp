/*

   * Happy Zenith Noises *

         2025.11.29

*/
#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int>P;
const int MAXN=100005;
int n,m,ans;
int c[MAXN],b[MAXN];
struct node{
    int x,y;
}a[MAXN];
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y,c[i]=a[i].x+a[i].y,b[i]=a[i].x;
    sort(c+1,c+1+n);sort(b+1,b+1+n);
    for(int i=1,s=0;i<=n+1;i++){
        s+=b[i-1];
        if(s<=m)ans=max(ans,i-1+(m-s)/c[1]*2);
    }
    cout<<ans;
    return 0;
}

