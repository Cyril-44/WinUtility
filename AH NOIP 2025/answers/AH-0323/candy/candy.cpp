#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long xi[100005],yi[100005];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>xi[i]>>yi[i];
        yi[i]+=xi[i];
    }
    sort(xi+1,xi+n+1);
    sort(yi+1,yi+n+1);
    long long maxx=m/yi[1]*2;
    for(int i=1;i<=n;i++)
    {
        m-=xi[i];
        maxx=max(maxx,m/yi[1]*2+i);
    }
    cout<<maxx;
    return 0;
}
