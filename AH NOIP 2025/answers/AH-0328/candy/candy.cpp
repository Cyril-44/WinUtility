#include<bits/stdc++.h>
using namespace std;
struct cd{
    long long x,y,avg,id;
}a[100005];
struct tag{
    long long x,y,id;
}b[100005],c[100005];
bool cmp(cd u,cd v){
    return u.avg<v.avg;
}
bool cmp2(tag u,tag v){
    return u.x<v.x;
}
bool cmp3(tag u,tag v){
    return u.y<v.y;
}
long long n,m,vis[100005],ans,vis2[100005],vis3[100005],s[100005];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    m*=2LL;
    for(int i=1;i<=n;i++){
        a[i].id=b[i].id=i;
        cin>>a[i].x>>a[i].y;
        a[i].x*=2LL;
        a[i].y*=2LL;
        b[i].x=a[i].x;
        b[i].y=a[i].y;
        a[i].avg=(a[i].x+a[i].y)/2LL;
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp2);
    long long mn=a[1].avg,sum=a[1].avg*2LL;
    long long pos=0;
    for(int i=1;i<=n;i++){
        if(b[i].x<mn){
            if(m-b[i].x>=0){
                m-=b[i].x;
                ans++;
                vis[b[i].id]=1;
                pos=i;
            }
            else{
                break;
            }
        }
    }
    long long tmp=m/sum;
    m-=tmp*sum;
    ans+=tmp*2LL;
    long long mm=m;
    for(int i=pos;i;i--){
        s[pos]=s[pos+1]+b[pos].x;
    }
    for(int i=1,j=pos;i<=pos;j--,i++){
        if((mm+s[i])/sum*2>j){
            m+=s[i];
            ans-=j;
        }
    }
    tmp=m/sum;
    m-=tmp*sum;
    ans+=tmp*2LL;
    for(int i=1;i<=n;i++){
        int now=a[i].id;
        c[i].id=now;
        if(vis[now]){
            c[i].x=a[i].y;
            c[i].y=a[i].x;
        }
        else{
            c[i].x=a[i].x;
            c[i].y=a[i].y;
        }
    }
    sort(c+1,c+1+n,cmp2);
    long long m3=m,ans3=0;/*
    for(int i=1;i<=n;i++){
        if(m2-c[i].x>=0){
            m2-=c[i].x;
            ans2++;
            vis2[c[i].id]=1;
        }
        else{
            break;
        }
    }
    sort(c+1,c+1+n,cmp3);
    for(int i=1;i<=n;i++){
        if(!vis[c[i].id]){
            continue;
        }
        if(m2-c[i].y>=0){
            m2-=c[i].y;
            ans2++;
        }
    }*/
    for(int i=1;i<=n;i++){
        if(m3-c[i].x>=0){
            m3-=c[i].x;
            ans3++;
            vis3[c[i].id]=1;
        }
        else{
            break;
        }
    }
    cout<<ans+ans3;
    return 0;
}
