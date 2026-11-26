#include<iostream>
#include<cstdio>
using namespace std;
int n,q,a[50005],sum[50005],k[50005];
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    scanf("%d",&q);
    while(q--){
        int l,r;
        long long ans=0;
        scanf("%d%d",&l,&r);
        for(int i=1;i<=n;i++){
            for(int j=l;j<=r;j++){
                if(i<j)break;
                for(int t=j;t<=r;t++){
                    k[i]=max(k[i],sum[t]-sum[j-1]);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(k[i]==0)continue;
            if(k[i]>0)ans^=(i*k[i]);
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
