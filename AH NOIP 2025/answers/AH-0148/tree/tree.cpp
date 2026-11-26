#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int a[11000],s[11000];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    for(;t;t--){
        cin>>n>>m;
        for(int q=2;q<=n;q++)cin>>a[q];
        if(m==1){
            cout<<1<<"\n";
            continue;
        } else if(m==2){
            int ans=0,tt=0;
            for(int q=2;q<=n;q++){
                if(a[q]!=1){
                    s[a[q]]++;
                } else tt++;
            }
            int maxn=0;
            for(int q=2;q<=n;q++){
                if(s[q])s[q]++,ans+=s[q]+1,tt--;
                maxn=max(maxn,s[q]);
            }
            cout<<ans+maxn+1+tt<<"\n";
            continue;
        }
    }
    return 0;
}
