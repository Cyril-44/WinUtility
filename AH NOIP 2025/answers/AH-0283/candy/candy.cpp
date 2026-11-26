#include<bits/stdc++.h>
#define forr(i,a,b) for(int i=a;i<=b;++i)
#define forl(i,a,b) for(int i=a;i>=b;--i)
using namespace std;

int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    int n;cin>>n;
    long long m,ans=0;cin>>m;
    int xy,x[n+1],y;
    int bxy=INT_MAX,bx=INT_MAX;

    forr(i,1,n)
    {
        cin>>x[i]>>y;
        xy=x[i]+y;
        bxy=min(bxy,xy);
        bx=min(bx,x[i]);
    }
    if(bxy<bx*2){
        ans+=(m/bxy)*2;
        if((m%bxy)>bx)ans++;
        cout<<ans;
        return 0;
    }
    vector<int> bxs;
    forr(i,1,n)
        if(x[i]*2<=bxy)bxs.push_back(x[i]);
    sort(bxs.begin(),bxs.end());
    int more;
    forr(i,0,bxs.size()-1)
    {
        if(m>=bxs[i])m-=bxs[i],ans++;
        more=bxs[i];
    }
    ans+=(m/bxy)*2;
    m%=bxy;
    if((m+more)>bxy)ans++;
    cout<<ans;
    return 0;
}


