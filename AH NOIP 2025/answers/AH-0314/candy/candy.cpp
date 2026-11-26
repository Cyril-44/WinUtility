#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
    long long x,y;
}a[100010];
long long num[100010];
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    int n;
    long long c,minn=0x3f3f3f3f3f3f3f3f;
    scanf("%d %lld",&n,&c);
    for(int i=1;i<=n;i++){
        long long x,y;
        scanf("%lld %lld",&x,&y);
        num[i]=x;
        minn=min(minn,x+y);
    }
    sort(num+1,num+n+1);
    long long ans=0;
    for(int cnt_ji=0;cnt_ji<=n;cnt_ji++){
        if(c>=0){
            ans=max(ans,cnt_ji+c/minn*2);
        }
        c-=num[cnt_ji+1];
    }
    printf("%lld",ans);
    return 0;
}