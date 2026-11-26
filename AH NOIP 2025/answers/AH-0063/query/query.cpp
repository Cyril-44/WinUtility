#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50005],s[50005];
ll num[55005][18];
ll lg[50005];
int cal(int x,int y)
{
    return s[x]>s[y]?x:y;
}
struct node{
    int cal,i,l,r,r0;
    bool operator<(const node &s) const{
        return cal<s.cal;
    }
    bool operator>(const node &s) const{
        return cal>s.cal;
    }
};
int cal2(int x,int y)
{
    int xx=lg[y-x+1];
    return cal(num[x][xx],num[y-(1<<xx)+1][xx]);
}
priority_queue<node> q;
int n,Q;
int main()
{
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s[i]=s[i-1]+a[i];
        num[i][0]=i;
    }
    for(int j=1;j<=16;j++)
        for(int i=1;i<=n-(1<<(j-1))+1;i++)
            num[i][j]=cal(num[i][j-1],num[i+(1<<(j-1))][j-1]);
    for(int i=2;i<=n;i++)
        lg[i]=lg[i/2]+1;
    __int128 x1=1;
    for(int i=1;i<=64;i++)
        x1*=2;
    cin>>Q;
    while(Q--)
    {
        int L,R;
        cin>>L>>R;
        //if(L==R)
        //{
        //    for(int i=1;i<=n;i++)
        //
        //}
        if(R<=32||L==R)
        {
            __int128 x3=0;
            for(int i=1;i<=n;i++)
            {
                ll mx=LONG_LONG_MIN;
                for(int j=max(i-R+1,1);j<=i;j++)
                {
                    int x=cal2(max(i,j+L-1),min(n,j+R-1));
                    mx=max(mx,s[x]-s[j-1]);
                }
                __int128 x2=mx*i;
                x2%=x1;
                x3=x2^x3;
            }
            unsigned long long xxx=x3;
            cout<<xxx<<"\n";
        }
        for(int i=1;i<=n-L+1;i++)//一定含i?
        {
            int x=cal2(i+L-1,min(n,i+R-1));
            q.push({s[x]-s[i-1],i,i+L-1,min(n,i+R-1),x});
        }
    }
}
