#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
const int MOD=998244535;
int a[10000];
int pow2(int x){
    int ans=1;for(int i=1;i<=x;i++)ans=((ans%MOD)*2)%MOD;
    return ans;
}
int ans=0;
int temp[10000];
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        ans=pow2(n);
        for(int i=1;i<=n;i++)temp[n+1]=0;
        for(int i=1;i<n;i++){
            if(a[i]*2>a[i+1]){temp[i]=1;temp[i+1]=1;}
        }
        for(int i=1;i<=n;i++){
            if(temp[i]==1){
                int num=0;
                for(;i<=n;i++){
                    if(temp[i])num++;
                    else break;
                }
                ans-=pow2(num);
                ans+=2;
            }
        }
        cout<<ans<<"\n";
    }
}
