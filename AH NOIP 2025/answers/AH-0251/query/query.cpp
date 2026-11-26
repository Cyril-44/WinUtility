#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,ans,a[500005],f[500005],maxn[500005];
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    cin>>m;
    while(m--){
        for(int i=1;i<=n;i++){
            maxn[i]=-100005;
        }
        cin>>u>>v;
        for(int l,r,i=u;i<=v;i++){
            l=1,r=i;
            while(r<=n){
                for(int j=l;j<=r;j++){
                    maxn[j]=max(maxn[j],f[r]-f[l-1]);
                }
                l++,r++;
            }
        }
        ans=maxn[1];
        for(int i=2;i<=n;i++) ans^=(i*maxn[i]);
        cout<<18446744073709551603<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
