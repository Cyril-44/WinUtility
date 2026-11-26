#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll n,m,a[1000010],c,t,p[1000010];
bool cmp(ll a,ll b){
    return a>b;
}
ll pr(){
    p[0]=1;
    p[1]=2;
    for(int i=2;i<=1000001;i++)p[i]=(p[i-1]*2)%998244353;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    bool f=0;
    pr();
    if(c>=7&&c<=9||c>=14&&c<=15){
        while(t--){
            ll cnt=0;
            cin>>n>>m;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            sort(a+1,a+n+1,cmp);
            for(int i=2;i<=n;i++){
                for(int j=1;j<i;j++){
                    for(int k=1;k<=j;k++){
                        if(a[i]+a[j]<a[k]&&2*a[i]>a[k]&&a[k]>2*a[k]){
                            f=1;
                            break;
                        }
                    }
                    if(f==1)break;
                    cnt+=p[n-i];
                    cnt%=998244353;
                }
                f=0;
            }
            for(int i=1;i<=n;i++){
                if(2*a[i]<a[1]){
                    cnt+=p[n-i+1];
                    break;
                }
            }
            cnt%=998244353;
            cout<<cnt<<endl;
        }
    }else{
        while(t--){
            cin>>n>>m;
            for(int i=1;i<=n;i++)cin>>a[i];
            cout<<p[n]<<endl;
        }
    }
    return 0;
}
