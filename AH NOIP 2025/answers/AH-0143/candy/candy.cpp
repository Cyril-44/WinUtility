#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

struct node{
    long long x,y;
    bool wei;
}k[100100];

int n;
long long m,ans=0;
long long zzz[100100],duohuode[100100];

bool cmp(node xx,node yy){
    return xx.x+xx.y<yy.x+yy.y || (xx.x+xx.y==yy.x+yy.y && xx.x>yy.x);
}

bool cmp2(node xx,node yy){
    return xx.x<yy.x;
}

bool cmp3(node xx,node yy){
    long long jlx=0,jly=0;
    if(xx.wei){
        jlx=xx.y;
    }else{
        jlx=xx.x;
    }
    if(yy.wei){
        jly=yy.y;
    }else{
        jly=yy.x;
    }
    return jlx<jly;
}

int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int a=1;a<=n;a++){
        cin>>k[a].x>>k[a].y;
        k[a].wei=false;
    }
    sort(k+1,k+n+1,cmp);
    sort(k+2,k+n+1,cmp2);
    int jilu=1;
    long long cnt=1,k1=k[1].x+k[1].y;
    for(int a=2;a<=n;a++){
        zzz[a]=zzz[a-1]+k[a].x;
        if(zzz[a]>k1*cnt){
            cnt+=(zzz[a]-k1*cnt)/k1+1;
        }
        duohuode[a]=a-1-cnt*2;
    }
    long long zuiduo=0;
    for(int a=2;a<=n;a++){
        if(duohuode[a]>zuiduo){
            zuiduo=duohuode[a];
            jilu=a;
        }
    }
    ans+=(jilu-1);
    m-=zzz[jilu];
    for(int a=2;a<=jilu;a++){
        k[a].wei=true;
    }
    long long ttttt=floor(m*1.0/(k[1].x+k[1].y));
    ans+=ttttt*2;
    m-=ttttt*(k[1].x+k[1].y);
    sort(k+1,k+n+1,cmp3);
    for(int a=1;a<=n;a++){
        long long jl;
        if(k[a].wei){
            jl=k[a].y;
        }else{
            jl=k[a].x;
        }
        if(m>=jl){
            ans++;
            m-=jl;
        }else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
