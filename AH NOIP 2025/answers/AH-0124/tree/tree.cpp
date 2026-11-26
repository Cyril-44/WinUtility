#include<bits/stdc++.h>

using namespace std;
int read()
{
int f=1,sum=0;
char ch;
ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') f=-1;
    ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
    sum=(sum<<1)+(sum<<3)+(ch^48);
    ch=getchar();
    }
    return sum*f;
}
int sum(int n)
{
    if(n==0) return 0;
    return sum(n-1)+n;
}

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int t;
    cin>>t;
    int n,m,p[8005];
    while(t--)
    {
    cin>>n>>m;
        for(int i=1;i<n;i++)
        {
        cin>>p[i];
        }
    cout<<sum(n)<<endl;
    }
    return 0;
}
