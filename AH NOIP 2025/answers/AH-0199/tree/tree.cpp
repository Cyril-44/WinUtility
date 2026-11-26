#include<bits/stdc++.h>
using namespace std;
struct tree
{
    int fa;
    int num;
    int num1;
    int h;
};
struct tree T[10000];
int ans=0;
void creat(int b,int n)
{
    for(int i=2;i<=n;i++)
    {
        if(T[i].fa==b)
        {
            T[i].h=T[b].h+1;
            T[b].num1=T[b].num1+1+T[i].num1;
            creat(i,n);
        }
    }
}
void dfs(int n,int s)
{
    for(int i=2;i<=n;i++)
    {
        if(T[i].fa==s && T[i].num!=0)
        {
            dfs(n,i);
            ans=ans+T[i].num1+1;
        }
    }
}
int main()
{
    freopen("tree1.in","r",stdin);
    freopen("tree1.out","w",stdout);
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        int n,m,i;
        ans=0;
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            T[i].num=0;
            T[i].h=0;
            T[i].num1=0;
        }
        for(i=2;i<=n;i++)
        {
            cin>>T[i].fa;
            T[T[i].fa].num++;
        }
        creat(1,n);
        int m1=1;
        for(i=2;i<=n;i++)
        {
            if(T[i].fa==1) m1=max(m1,T[i].num1);
        }
        ans=ans+m1+2;
/*        for(i=1;i<=m-1;i++)
        {
            for(int j=2;j<=n;j++)
            {
                if(T[j].h==i) ans=ans+T[j].num1+1;
                if(T[j].num==0) ans++;
            }
        }
        cout<<ans<<endl;
        */
        dfs(n,1);
        int a[n+1];
        for(i=0;i<=n;i++)
        {
            a[i]=0;
        }
        int b=1;
        for(i=2;i<=n;i++)
        {
            if(T[i].num==0)
            {
                int br=0;
                for(int j=1;j<=b;j++)
                    if(a[j]==T[i].fa)
                    {
                        br=1;

                    }
                if(br==1) continue;
                else
                {
                    ans++;
                    b++;
                    a[b]=T[i].fa;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
