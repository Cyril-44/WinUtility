#include<bits/stdc++.h>
using namespace std;
struct candy
{
    int x,y;
}a[100005];
int n,cnt;
bool vis[105];//mod2
long long m;
bool cmp(candy a1,candy a2)
{
    return (a1.x+a1.y)<(a2.x+a2.y);
}
bool cmp2(candy a1,candy a2)
{
    return a1.x<a2.x;
}
void dfs(int sum,int k)
{
    if(sum>m)
    {
        cnt=max(cnt,k-1);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
        {
            vis[i]=0;
            dfs(sum+a[i].y,k+1);
            vis[i]=1;
        }
        else
        {
            vis[i]=1;
            dfs(sum+a[i].x,k+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;
    if(n<=10)
    {
        dfs(0,0);
        cout<<cnt;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    long long num1=m/(a[1].x+a[1].y);
    int num2=m%(a[1].x+a[1].y);
    sort(a+1,a+n+1,cmp2);
    //1
    int sum=0,id;
    bool f=1;//if used out
    //cout<<num1<<' '<<num2<<' ';
    for(int i=1;i<=n;i++)
    {
        sum+=a[i].x;
        if(sum>num2)
        {
            f=0;
            id=i-1;
            break;
        }
    }
    long long ans1,ans2;
    if(f) ans1=num1*2+n;
    else ans1=num1*2+id;
    //2
    sort(a+1,a+n+1,cmp);
    num1=m/(a[1].x+a[1].y);
    num2=m%(a[1].x+a[1].y)+a[1].y;
    sort(a+1,a+n+1,cmp2);
    sum=0;
    f=1;//if used out
    //cout<<num1<<' '<<num2<<' ';
    for(int i=1;i<=n;i++)
    {
        sum+=a[i].x;
        if(sum>num2)
        {
            f=0;
            id=i-1;
            break;
        }
    }
    if(f) ans2=(num1-1)*2+1+n;
    else ans2=(num1-1)*2+1+id;
    //cout<<num1<<' '<<num2<<' ';
    cout<<max(ans1,ans2);
    return 0;
}
