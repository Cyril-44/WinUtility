#include<bits/stdc++.h>

#define LL long long

using namespace std;

const int N=5*1e4+10;

int n,q;
LL a[N],s[N];

int main(){

    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    scanf("%d",&q);
    for(int i=1,l,r;i<=q;i++){
        LL ans=0;
        scanf("%d%d",&l,&r);
        for(int tmp=1;tmp<=n;tmp++){
            LL mx=-0x3f3f3f3f;
            for(int len=l;len<=r;len++){
                for(int f=max(tmp-len+1,1);f<=tmp;f++)
                    mx=max(mx,s[f+len-1]-s[f-1]);
            }
            ans^=(tmp*mx);
        }
        printf("%lld\n",ans);
    }
    printf("\n");
    return 0;

    fclose(stdin);
    fclose(stdout);

}
