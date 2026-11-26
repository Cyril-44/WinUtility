#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Maxn=1e4;

int lin[Maxn+10];

struct node
{
    int num,chu;
}a[Maxn+10];
bool cmp(node a,node b)
{
    if(a.num/a.chu!=b.num/b.chu) return a.num/a.chu>b.num/b.chu;
    else
        return a.num>b.num;
}
bool cmp2(int a,int b)
{
    return a>b;
}

int if_2[Maxn+10],top2=0;
int if_1[Maxn+10],top1=0;

signed main()
{
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>lin[i];
        for(int i=0;i<(1<<(n));i++)
        {
            for(int j=1;j<=n;j++) a[j].num=lin[j];
            top1=0,top2=0;
            for(int j=1;j<=n;j++)
            {
                if((1<<(j-1))&i)
                    if_2[++top2]=a[j].num,a[j].chu=2;
                else if_1[++top1]=a[j].num,a[j].chu=1;
            }
            sort(a+1,a+1+n,cmp);

            int tians=0,linm=m;
            for(int j=1;j<=n;j++)
                if(linm>=a[j].chu) tians+=a[j].num,linm-=a[j].chu;
                else continue;
            int mans=0;
            linm=m;
            if(top1>0) sort(if_1+1,if_1+1+top1,cmp2);
            if(top2>0) sort(if_2+1,if_2+1+top2,cmp2);
            while(linm>=2)
            {
                if(top1>=2&&if_2[top2]<if_1[top1]+if_1[top1-1]) mans+=if_1[top1]+if_1[top1-1],top1-=2,linm-=2;
                else if(top1==1&&linm!=2&&if_2[top2]<if_1[top1]*2) mans+=if_1[top1],top1--,linm--;
                else if(top1==1&&linm==2&&if_2[top2]>if_1[top1]) mans+=if_2[top2],top2--,linm-=2;
                else if(top1==1&&linm==2&&if_2[top2]<=if_1[top1]) mans+=if_1[top1],top1--,linm--;
                else if(top2!=0) mans+=if_2[top2],top2--,linm-=2;
                else break;
            }
            if(linm>=1&&top1>0) mans+=if_1[top1];

            if(mans==tians) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
