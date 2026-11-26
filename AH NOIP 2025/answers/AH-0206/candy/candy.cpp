#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
int x[100005],y[100005],a[100005];
struct node{
    int cx,cy,ad,id;
}c[100005],d[100005];
bool xA=true;
bool cmp(node u,node v){
    if(u.ad!=v.ad){
        return u.ad<v.ad;
    }
    return u.cx<v.cx;
}
bool cmp2(node u,node v){
    if(u.cx!=v.cx){
        return u.cx<v.cx;
    }
    return u.ad<v.ad;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        c[i].cx=x[i];
        c[i].cy=y[i];
        c[i].ad=x[i]+y[i];
        c[i].id=i;
        d[i].cx=x[i];
        d[i].cy=y[i];
        d[i].ad=x[i]+y[i];
        d[i].id=i;
        if(x[i]!=y[i]){
            xA=false;
        }
    }
    if(xA==true){
        for(int i=1;i<=n;i++){
            a[i]=x[i];
        }
        sort(a+1,a+1+n);
        cout<<m/a[1];
        return 0;
    }
    if(n==1){
        int cnt=(m/(x[1]+y[1]))*2,ans=m%(x[1]+y[1]);
        if(ans>=x[1]){
            cnt++;
        }
        cout<<cnt;
        return 0;
    }
    sort(c+1,c+1+n,cmp);
    sort(d+1,d+1+n,cmp2);
/*
    for(int i=1;i<=n;i++){
            cout<<"c["<<i<<"]:"<<c[i].cx<<" "<<c[i].cy<<"    d["<<i<<"]:"<<d[i].cx<<" "<<d[i].cy<<endl;
    }
*/
    int ansx=c[1].cx,ansy=c[1].cy;
//    int cnt=(m/(c[1].cx+c[1].cy))*2,ans=m%(c[1].cx+c[1].cy);
//    sort(x+1,x+1+n);
    int cnt=0,ans=0,maxn=0;
    for(int i=0;i<=n;i++){
        if(ans+d[i].cx>m)break;
        if(d[i].cx==ansx&&d[i].cy==ansy)break;
//            cout<<"c["<<i<<"]:"<<c[i].cx<<" "<<c[i].cy<<"    d["<<i<<"]:"<<d[i].cx<<" "<<d[i].cy<<endl;
        if(ans+d[i].cx<=m&&i!=0){
            cnt++;
            ans+=d[i].cx;
//            x[d[i].id]=y[d[i].id];
        }
        int anscnt=cnt+((m-ans)/(c[1].cx+c[1].cy))*2,ansans=(m-ans)%(c[1].cx+c[1].cy);
        for(int j=i+1;j<=n;j++){
            if(ansans>=d[j].cx){
                anscnt++;
                ansans-=d[j].cx;
            }
        }
        maxn=max(maxn,anscnt);
    }
    /*
    m-=ans;
    cnt+=(m/(c[1].cx+c[1].cy))*2,ans=m%(c[1].cx+c[1].cy);
    sort(x+1,x+1+n);
    for(int i=1;i<=n;i++){
        if(ans>=x[i]){
            ans-=x[i];
            cnt++;
        }
    }
    */
    cout<<maxn;
    return 0;
}
