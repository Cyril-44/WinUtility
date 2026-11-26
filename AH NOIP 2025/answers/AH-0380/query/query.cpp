#include<bits/stdc++.h>
using namespace std;
long long a[50010],sum[50010];
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int q;
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R;
        unsigned long long ans=0;
        for(int i=1;i<=n;i++){
            long long mx=-0x3f3f3f3f3f3f3f3f;
            for(int l=i;l>=1&&i-l+1<=R;l--){
                for(int r=l+L-1;r<=n&&r-l+1<=R;r++){
                    //cout<<"["<<l<<","<<r<<"]"<<endl;
                    mx=max(mx,sum[r]-sum[l-1]);
                }
            }
            //cout<<mx<<endl;
            ans^=mx*i;
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
