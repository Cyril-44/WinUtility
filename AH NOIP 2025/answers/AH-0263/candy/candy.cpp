#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,ans;
long long m;
int ji[100001],ou[100001],gr[100001],jp[100001];
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    int minn=2000000000;
    for(int i=1;i<=n;i++)
    {
        cin>>ji[i]>>ou[i];
        jp[i]=ji[i];
        gr[i]=ji[i]+ou[i];
        if(gr[i]<minn)
        {
            minn=gr[i];
            k=i;
        }
    }
    sort(jp+1,jp+n+1);
    int sum=0,mark1=0,mark2=0;
    for(int i=1;i<=n;i++)
    {
        if(jp[i]<min(ji[k],ou[k]))
        {
            mark1=i;
        }
        if(jp[i]<=max(ji[k],ou[k])&&jp[i]>=min(ji[k],ou[k]))
        {
            mark2=i;
        }
        if(jp[i]>max(ji[k],ou[k])) break;
    }
    for(int i=1;i<=mark1;i++)
    {
        m-=jp[i];
        if(m>=0) cnt++;
        else
        {
            cout<<cnt;
            return 0;
        }
    }
    int t=mark1+1;
    for(int i=mark1+1;i<=mark2-1;i+=2)
    {
        if(jp[i]+jp[i+1]<gr[k])
        {
            m-=jp[i];
            if(m>=0) cnt++;
            else
            {
                cout<<cnt;
                return 0;
            }
            m-=jp[i+1];
            if(m>=0) cnt++;
            else
            {
                cout<<cnt;
                return 0;
            }
            t=i+2;
        }
    }
    while(m>=gr[k])
    {
        m-=gr[k];
        cnt+=2;
    }
    for(int i=t;i<=mark2;i++)
    {
        m-=jp[i];
        if(m>=0) cnt++;
        else
        {
            cout<<cnt;
            return 0;
        }
    }
    cout<<cnt;
    return 0;
}
