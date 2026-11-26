#include<iostream>
#include<cmath>
#include<string.h>
#include<algorithm>

#define LL long long

using namespace std;

const int N=1e5+10;

int n;LL m;

struct Node{

    LL x,y;

}a[N];

bool Cmp(Node u,Node v){

    return u.x<v.x;

}

int main(){

    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);

    scanf("%d%lld",&n,&m);
    LL mn=2e9+10;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].x,&a[i].y);
        mn=min(mn,a[i].x+a[i].y);
    }
    sort(a+1,a+1+n,Cmp);
    LL cnt=0,tmp=-1;
    for(int i=1;i<=n;i++)
        if(m>=a[i].x&&a[i].x*2<=mn){
            cnt++;
            m-=a[i].x;
            tmp=a[i].x;
            a[i].x=a[i].y;
        }else
            break;
    cnt+=((LL)(m/mn))*2;
    m%=mn;
    if(m*2<mn||tmp==-1||m+tmp<mn)
        printf("%lld\n",cnt);
    else
        printf("%lld\n",cnt+1);
    return 0;

    fclose(stdin);
    fclose(stdout);

}
