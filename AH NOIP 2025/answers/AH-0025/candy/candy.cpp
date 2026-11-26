#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[100005],b[100005],cnt[100005],ans;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        a[i]=x,b[i]=x+y;
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    ans=m/b[1]*2;
    for(int i=1;i<=n;i++){
        cnt[i]=cnt[i-1]+a[i];
        if(m<cnt[i]) break;
        ans=max(ans,i+(m-cnt[i])/b[1]*2);
    }
    cout<<ans;
    return 0;
}
/*
3 15
1 7
2 3
3 1
*/
