#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,num,zs,bzw,fa,fai;
bool oka=1,okb=1;//oka:a[i].js=a[i].os   okb:js>=os
struct node{
    long long js,os,op=1;//1:js ,0:os
}a[100010];
bool cmp(node p,node q){//js
    return p.js<q.js;
}
bool cmp2(node p,node q){
    if((p.js+p.os)!=(q.os+q.js)){
        return (p.js+p.os)<(q.os+q.js);
    }
    else{
        return p.js<q.js;
    }
}
void dfs(long long now,long long money,long long gs){
    ans=max(gs,ans);
    if(now>n){
        return;
    }
    if(money<a[now].js){
        return;
    }
    dfs(now+1,money,gs);//none
    for(int i=1;num<=money;i++){
        if(i%2==0){
            num=(a[now].js+a[now].os)*(i*1ll/2);
        }
        else{
            num=(a[now].js+a[now].os)*(i*1ll/2)+a[now].js;
        }
        dfs(now+1,money-num,gs+i);
    }
    return;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    zs=0;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&a[i].js,&a[i].os);
        zs=max(zs,a[i].js+a[i].os);
        if(a[i].js!=a[i].os) {
            oka=0;
        }
        if(a[i].js<a[i].os){
            okb=0;
        }
    }
    if(oka==1){
        sort(a+1,a+1+n,cmp);
        ans=m*1ll/a[1].js;
        printf("%lld",ans);
        return 0;
    }
    if(okb==1){
        sort(a+1,a+1+n,cmp2);
        ans=m*1ll/(a[1].js+a[1].os)*2;
        m=m-ans*(a[1].js+a[1].os);
        sort(a+1,a+1+n,cmp);
        long long j=1;
        while(m>=a[j].js){
            m-=a[j].js;
            ans++;
        }
        printf("%lld",ans);
		return 0;
    }
    if(n<=10){
        dfs(1,m,0);
        printf("%lld",ans);
        return 0;
    }
    //tanxin
    while(m){
        long long minn=0x7f7f7f7f7f;
        fa=0x7f7f7f7f;
        fai=0;
        for(int i=1;i<=n;i++){
            if(a[i].op==0){
                bzw=a[i].os;
            }
            else{
                bzw=a[i].js;
            }
            if(bzw==minn&&fa>(a[i].js+a[i].os)){
                a[fai].op=(a[fai].op+1)%2;
				minn=bzw;
                fa=a[i].js+a[i].os;
                a[i].op=(a[i].op+1)%2;
                fai=i;
			}
            else if(bzw<minn){
                a[fai].op=(a[fai].op+1)%2;
                minn=bzw;
                fa=a[i].js+a[i].os;
                a[i].op=(a[i].op+1)%2;
                fai=i;
            }
        }
        if(m<minn){
            break;
        }
        else{
            m-=minn;
            ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
