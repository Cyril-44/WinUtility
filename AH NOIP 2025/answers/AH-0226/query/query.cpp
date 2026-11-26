#include<bits/stdc++.h>
#define _ 50005
using namespace std;
int n,q,l,r;
long long a[_],s[_],ans[_];unsigned long long sum;
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);s[i]=s[i-1]+a[i];
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);memset(ans,0,sizeof(ans));sum=0;
        for(int i=1;i+l<=n;i++){
            int N=min(i+r,n);
            for(int j=i+l;j<=N;j++){
                for(int k=i;k<=j;k++){
                    if(s[j]-s[i]>ans[k])ans[k]=s[j]-s[i];
                }
            }
        }
        for(int i=1;i<=n;i++)sum^=(ans[i]*i);
        printf("%llu",sum);
    }
    return 0;
}
