#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
    int f=1,x=0;char c=getchar();
    while(!isdigit(c)){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(isdigit(c)){
        x=x*10+c-'0',c=getchar();
    }
    return f*x;
}

const int N=50005,inf=1e18;
int n,q,a[N],sum[N];

signed main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
    q=read();
    while(q--){
        int L=read(),R=read();
        unsigned long long ans=0;
        for(int i=1;i<=n;i++){
            //cout<<i<<":\n";
            int maxk=-inf;
            for(int k=L;k<=R;k++){
                //cout<<k<<"\n";
                for(int r=i,l=r-k+1;l<=i&&r<=n;r++,l++){
                    if(l<1) continue;
                    maxk=max(maxk,sum[r]-sum[l-1]);
                    //cout<<l<<" "<<r<<" "<<sum[r]-sum[l-1]<<" "<<maxk<<endl;
                }
            }
            ans=(ans^(unsigned long long)(i*(unsigned long long)maxk));
        }
        cout<<ans<<"\n";
    }
}
/*
NOIP2025 Day1
AFO
T1 一开始写的贪心，想了三种策略最后都找到了反例，最后写了一个时间复杂度不正确但是我场上没找出反例的做法，用时1h20min
T3 足够暴力，n^(n+1), 样例1都跑了2s。
T4 qn^3，希望ccf少爷机给点力使我能多过几个特殊性质点
T2 思考了很长时间，但最后并没有研究出来，写了4^n的暴力和一点特殊性质。
预计 [50,100]+28+8+[5,15]=[91,151]
大抵过不了去年的1=线

想来将近7年的oi生涯就此结束，到也没有什么感伤与遗憾，至少我觉得这次的发挥已经对得起自己了。
*/
