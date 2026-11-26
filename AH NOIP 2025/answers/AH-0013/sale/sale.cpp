#include<bits/stdc++.h>
using namespace std;
//发现若最大数w取1那么一定合法且可以将m--
//不合法的条件：存在两个购买的1之和小于一个未购买的2或剩余1元且存在一个购买的1小于一个未购买的2
const int N=5010,mod=998244353;
int tid,T,n,m,a[N],w[N];bool bo[N];
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
struct node{
    int x,y,id;
}b[N];
bool cmp(node A,node B){return A.x*B.y>B.x*A.y||A.x*B.y==B.x*A.y&&A.x>B.x||A.x*B.y==B.x*A.y&&A.x==B.x&&A.id<B.id;}
void init(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
}
void work(){
    if(n<=10){
        int res=0;
        for(int S=0;S<(1<<n);S++){
            for(int i=1;i<=n;i++){
                w[i]=((S>>(i-1))&1)+1;
                b[i]={a[i],w[i],i};
            }
            sort(b+1,b+n+1,cmp);
            for(int i=1;i<=n;i++)bo[i]=0;
            int now=m;
            for(int i=1;i<=n;i++)
                if(now>=b[i].y){
                    bo[b[i].id]=1;
                    now-=b[i].y;
                }
            bool fl=0;
            for(int i=1;i<n&&!fl;i++)
                if(bo[i]&&w[i]==1)
                    for(int j=i+1;j<=n&&!fl;j++)
                        if(bo[j]&&w[j]==1)
                            for(int k=1;k<=n&&!fl;k++)
                                if(!bo[k]&&w[k]==2&&a[i]+a[j]<a[k])fl=1;
            if(now){
                for(int i=1;i<=n;i++)
                    if(bo[i]&&w[i]==1)
                        for(int j=1;j<=n;j++)
                            if(!bo[j]&&a[i]<a[j])fl=1;
            }
            if(!fl)res++;
        }
        printf("%d\n",res);return;
    }
    int res=1;
    for(int i=1;i<=n;i++)add(res,res);
    printf("%d\n",res);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%d%d",&tid,&T);
    while(T--){
        init();
        work();
    }
}
/*
I won't give up,no I won't give in.
Till I reach the end,and then I'll start again.
No I won't leave,I wonna try everything.
I wonna try even though I could fail.
*/