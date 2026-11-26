#include<bits/stdc++.h>
using namespace std;
int n,m;long long dp[1000010],dpr=0x3f3f3f3f3f3f,x[100010],y[100010],cnt;bool fl=true;
struct node{
    long long pr,fr;bool fl;
};
bool operator<(node x,node y){return x.pr>y.pr;}
priority_queue<node>pq;
void changeone(){
    m-=pq.top().pr;int t=pq.top().fr;bool fl=!pq.top().fl;
    pq.pop();
    if(fl) pq.push({y[t],t,fl});
    ++cnt;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>x[i]>>y[i],dpr=min(dpr,x[i]+y[i]);if(x[i]<y[i])fl=false;}
    if(m>10000){
        for(int i=1;i<=n;i++)pq.push({x[i],i,0});
    while(pq.top().pr*2<=dpr){
        changeone();
    }
    cnt+=(m/dpr)*2;
    m%=dpr;
    while(pq.top().pr<=m){
        changeone();
    }
    cout<<cnt;
    return 0;
    }

    for(int i=dpr;i<=m;i++)dp[i]=dp[i-dpr]+2;
    for(int i=1;i<=n;i++)for(int j=m;j>=x[i];j--)dp[j]=max(dp[j],dp[j-x[i]]+1);
    cout<<dp[m];
    return 0;
}
