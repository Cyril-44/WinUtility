#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005],c[100005],sum=0;
int main(void)
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",&a[i],&b[i]);
        c[i]=a[i]+b[i];
    }
    sort(c+1,c+n+1);
    sort(a+1,a+n+1);
    sum=2*(m/c[1]);
    m=m%c[1];
    for(int i=1;i<=n;i++)
    {
        if(m-a[i]>=0)sum++,m-=a[i];
        else break;
    }
    cout<<sum;
    return 0;
}
//5 years OI a void.(I can't speak English well.)
//What's my name?
