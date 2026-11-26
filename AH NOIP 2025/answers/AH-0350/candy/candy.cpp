#include <bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar_unlocked
int read(){
    int x=0;bool f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c))x=x*10+c-'0',c=gc();
    return f?-x:x;
}
vector<int>a;
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    int n=read(),m=read();int mn=1e18;
    for(int i=1;i<=n;i++){
        int x=read(),y=read();
        mn=min(mn,x+y);
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int ans=(m/mn)*2,pre=0;
    for(int i=0;i<n;i++){
        pre+=a[i];
        if(pre>m)break;
        ans=max(ans,i+1+((m-pre)/mn)*2);
    }
    cout<<ans;
    return 0;
}
