#include<iostream>
#include<cstdio>
using namespace std;
long long a[3010],sum[3010],ans[3010][3010];
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(j-i+1>=l  &&  j-i+1<=r){
                    ans[i][j]=sum[j]-sum[i-1];
                }
                else{
                    ans[i][j]=-0x3f3f3f3f3f3f3f3f;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>1){
                    ans[i][j]=max(ans[i][j],ans[i-1][j]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=n;j>=1;j--){
                if(j<n){
                    ans[i][j]=max(ans[i][j],ans[i][j+1]);
                }
            }
        }
        unsigned long long ansa=0;
        for(int i=1;i<=n;i++){
            unsigned long long t=ans[i][i]*i;
            ansa^=t;
        }
        printf("%llu\n",ansa);
    }
    return 0;
}