#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[50005];
long long pre[50005];
int main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],pre[i]=pre[i-1]+a[i];
    cin>>q;
    while(q--)
    {
        int l,r,L,R;
        unsigned long long k=0;
        long long ans;
        cin>>l>>r;
        for(int i=1;i<=n;i++)
        {
            ans=-1e12;
            int L=max(1,i-r+1);
            int R=max(l,i);
            while(L<=R && R<=n && i>=L && i<=R)
            {
                //if(R-L+1<l) R++;
                cout<<L<<' '<<R<<'\n';
                ans=max(ans,pre[R]-pre[L-1]);
                if(R-L+1==r)
                {
                    L++;
                    continue;
                }
                R++;
            }
            k^=((unsigned long long)(i*ans));
        }
        cout<<k<<'\n';
    }
    return 0;
}
