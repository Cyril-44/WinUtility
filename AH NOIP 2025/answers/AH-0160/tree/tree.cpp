#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int cnt[4001],d[4001][4001];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=cnt[i];j++)
            {
                d[i][j]=0;
            }
            cnt[i]=0;
        }
        for(int i=1;i<=n-1;i++)
        {
            int x;
            cin>>x;
            d[i+1][++cnt[i]]=x;
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]!=0)
            {
                int res=0,f=1;
                for(int j=1;j<=cnt[i];j++)
                {
                    if(cnt[d[i][j]]!=0)
                    {
                        f=0;
                        if(res==0)
                        {
                            res+=cnt[d[i][j]]+1;
                        }
                        else
                        {
                            res+=cnt[d[i][j]]-1;
                        }
                    }
                }
                if(f==1)
                {
                    res+=cnt[i]+2;
                }
                ans+=res;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
