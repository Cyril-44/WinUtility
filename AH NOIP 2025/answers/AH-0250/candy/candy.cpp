#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+10;
struct node
{
    long long x;
    long long y;
    long long z;
}a[N],b[N],c[N],s1,s2;
bool ch[N];
int u[N];
bool flag1=0,flag2=0;
int ans=0;
void dfs(int v,int sum)
{
    //cout<<v<<" "<<sum<<endl;
    if(v==0)
    {
        ans=max(ans,sum);
        return ;
    }
    else if(v<0)
    {
        ans=max(ans,sum-1);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==0)
        {
            sum+=1;
            ch[i]=1;
            //cout<<i<<" "<<v-a[i].x<<" "<<sum<<endl;;
            dfs(v-a[i].x,sum);
            sum-=1;
            ch[i]=0;
        }
        else if(ch[i]==1)
        {
            sum+=1;
            ch[i]=0;
            //cout<<i<<" "<<v-a[i].y<<" "<<sum<<endl;;
            dfs(v-a[i].y,sum);
            sum-=1;
            ch[i]=1;
        }

    }
}
int cmp1(node a, node b)
{
    return a.x<b.x;
}
int cmp2(node a,node b)
{
    if(a.x==b.x)
    {
        if(a.z>=b.z)return a.x<=b.x;
        else return a.x<=b.x;
    }
    return a.x<=b.x;
}
int main()
{
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        b[i].x=a[i].x,b[i].y=i;
        b[i].z=a[i].y;c[i].z=a[i].x;
        c[i].x=a[i].y,c[i].y=i;
        if(a[i].x!=a[i].y)flag1=1;
        if(a[i].x<a[i].y)flag2=1;
    }


    if(n<=10&&m<=20)dfs(m,0);
    else if(flag1==0)
    {
        sort(a+1,a+n+1,cmp1);
        ans=m/a[1].x;
    }
    else if(flag2==0)
    {

        sort(b+1,b+n+1,cmp2);

        sort(c+1,c+n+1,cmp2);
        s1.x=1e15;
        s2.x=1e15;
        for(int i=1;i<=n;i++)
        {
            ch[i]=0;
        }
        while(1)
        {
            s1.x=1e15;
            s2.x=1e15;
            /*for(int i=1;i<=n;i++)
            {

                cout<<ch[i];
            }
            cout<<endl;*/
            for(int i=1;i<=n;i++)
            {

                if(b[i].x<s1.x&&ch[b[i].y]==0)
                {
                    //cout<<"s1"<<endl;
                    s1.x=b[i].x;
                    s1.y=b[i].y;
                }
                if(c[i].x<s2.x&&ch[c[i].y]==1)
                {
                    //cout<<"s2"<<endl;
                    s2.x=c[i].x;
                    s2.y=c[i].y;
                }
            }
            if(s1.x<s2.x){m-=s1.x,ch[s1.y]=1;}
            else if(s1.x>=s2.x){m-=s2.x,ch[s2.y]=0;}
            //cout<<m<<" "<<s1.x<<" "<<s2.x<<endl;
            ans++;
            if(m==0)break;
            else if(m<0)
            {

                ans-=1;
                break;
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<c[i].x<<" ";
    }
    cout<<endl;*/
    cout<<ans;
    return 0;
}
/*
2 10
4 1
3 3

3 15
1 7
2 3
3 1
*/
