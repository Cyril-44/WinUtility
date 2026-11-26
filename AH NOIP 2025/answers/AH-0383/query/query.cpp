#include<bits/stdc++.h>
using namespace std;
int n,q;
long long a[50005];
unsigned long long b[50005],t=1,ans;
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    for(int i=1;i<=63;i++){
        t*=2;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    cin>>q;
    while(q--){
        int l,r;
        ans=0;
        cin>>l>>r;
        for(int i=1;i<=n;i++){
            if(a[i]<0)
                b[i]=(a[i]+t)*2-a[i];
            else
                b[i]=a[i];
            ans^=b[i];
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
