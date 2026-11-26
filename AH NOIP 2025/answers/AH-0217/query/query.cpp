#include <bits/stdc++.h>
using namespace std;
long long n,a[100001],m,L,R,an[100001],s[100001];
unsigned long long ans;
void sol(long long j){
    long long t=1;
    for(long long i=max(t,j-R+1);i<=min(n,j+R-1);i++)
        for(long long k=max(t,j-R+1);k<=min(n,j+R-1);k++)
            if((abs(k-i)+1)>=L&&(abs(k-i)+1)<=R&&min(i,k)<=j&&max(i,k)>=j)
                an[j]=max(an[j],s[max(i,k)]-s[min(i,k)-1]);
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>L>>R;
        for(int j=1;j<=n;j++){
            an[j]=INT_MIN;
            sol(j);
        }
        ans=an[1];
        for(int j=2;j<=n;j++){
            ans=ans^((j*an[j])%(340282366900000000000000000000000000000));
        }
        cout<<ans<<'\n';
    }
}
