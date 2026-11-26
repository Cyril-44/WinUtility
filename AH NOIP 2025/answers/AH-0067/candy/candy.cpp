#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
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

const int N=100010;
struct node{
    int x,y,sum;
}a[N],b[N];
bool cmp1(node A,node B){
    return A.sum<B.sum;
}
bool cmp2(node A,node B){
    return A.x<B.x;
}
int c[N];
int n,m;

signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    double st=clock();
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        int x=read(),y=read();
        a[i]={x,y,x+y};b[i]=a[i];
    }
    int ans=0;
    sort(a+1,a+n+1,cmp1),sort(b+1,b+n+1,cmp2);
    for(int i=1;i<=n;i++){
        c[i]=c[i-1]+b[i].x;
    }
    if(a[1].sum<=c[2]){
        ans+=(m/a[1].sum)*2;
        m%=a[1].sum;
        ans+=upper_bound(c,c+n+1,m)-c-1;
    }else{
        int z=upper_bound(c,c+n+1,a[1].sum)-c-1;
        int x=0,m1=m;
        ans=0;
        while(1){
            int anss=((m/a[1].sum)-x)*2;
            //cout<<anss<<" ";
            if(anss<0) break;
            m1=m%a[1].sum+x*a[1].sum;
            anss+=upper_bound(c,c+n+1,m1)-c-1;
            //cout<<anss<<'\n';
            if(anss>=ans){
                ans=anss,x++;
            }else break;
            if(clock()-st>CLOCKS_PER_SEC*0.9) break;
        }
    }
    cout<<ans;
}