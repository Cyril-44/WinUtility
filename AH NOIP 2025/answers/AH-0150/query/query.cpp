#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define MAXN 50005
using namespace std;
int n,m,Q;
typedef unsigned long long LL;
typedef long long ll;
LL mod;
ll a[MAXN],k[MAXN],pre[MAXN];
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    mod=1;
    for(int i=1;i<=63;i++){
        mod*=2;
    }
    mod--;
    mod*=2;
    mod++;
    //cout<<mod<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    cin>>Q;
    while(Q--){
            //cout<<Q<<" ";
        int L,R;
        cin>>L>>R;
        memset(k,-0x3f,sizeof(k));
        for(int i=1;i<=n;i++){
            for(int len=L;len<=R;len++){
                for(int j=i;j<=i+len-1;j++){
                    if(j>n) break;
                    k[j]=max(k[j],pre[i+len-1]-pre[i-1]);
                }
            }
        }
        LL ans=(k[1]*1)%mod;
            //cout<<k[1]<<" ";
        for(int i=2;i<=n;i++){
            //if(k[i]*i==mod) ans^=(k[i]*i);
            ans^=(k[i]*i%mod);
        }
        cout<<ans<<endl;
    }
    return 0;
}
