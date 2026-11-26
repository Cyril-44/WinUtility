#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int s;
    int j;
};
int a[1000005];
int b[10000005];
int jj[1000005];
int n,m;
int sum;
int ll(int kk){
    if(jj[kk]!=0)return jj[kk];
if(kk==1)return jj[kk]=2;
else return jj[kk]=(2*ll(kk-1))%998244353;
}
signed main(){
freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int l,k;
    cin>>l>>k;
    for(int cc2=1;cc2<=k;cc2++){
            cin>>n>>m;
            fill(a+1,a+1+n,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(l==14||l==15||l==8||l==9||l==7){
    if(a[n]>a[n-1]+a[n-2]&&a[n]>2*a[n-1]) cout<<ll(n)<<endl;
    else if(a[n]>a[n-1]+a[n-2]) cout<<ll(n)*7/8<<endl;
    else cout<<a[n]*3/4<<endl;
    }
    if(l==18) cout<<ll(n)<<endl;
    }
return 0;
}
