#include<iostream>
using namespace std;
long long n,a[10100],m,ml,mr,sum[10010],mx[10010],ans;
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum[i]=sum[i-1]+a[i],mx[i]=-0x3f3f3f3f3f3f3f3f;
    cin>>m>>ml>>mr;
    for(int i=ml;i<=mr;i++){
        for(int l=1;l+i-1<=n;l++){
            for(int j=l;j<=l+i-1;j++){
                mx[j]=max(mx[j],sum[l+i-1]-sum[l-1]);
            }
        }
    }
    for(int i=1;i<=n;i++)ans^=((unsigned long long)mx[i]*i);
    cout<<ans;
    return 0;
}
