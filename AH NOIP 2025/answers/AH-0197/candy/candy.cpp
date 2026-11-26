#include<bits/stdc++.h>
using namespace std;
struct candy{
    long long x,y;
}a[100005];
bool cmp(candy a,candy b){
    return a.x<b.x;
}
long long n,m,sum[100005],ans=0;
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    //n==1;
    if(n==1){
        int p,q;
        cin>>p>>q;
        int t=1,cnt=0,s;
        while(1){
            if(t==1){s=p;t=2;}
            else if(t==2){s=q;t=1;}
            if(m-s<0)break;
            else {cnt++;m-=s;}
        }
        cout<<cnt;
    }
    //n!=1
    else {
        int isa=1;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y;
            if(a[i].x!=a[i].y)isa=0;
            sum[i]=a[i].x+a[i].y;
        }
        //A
        if(isa){
            sort(a+1,a+n+1,cmp);
            cout<<m/a[1].x;
        }
        //B
        else {
            sort(a+1,a+n+1,cmp);
            sort(sum+1,sum+n+1);
            int flag=1,cnt=0;
            while(1){
                if(ans+a[1].x<=m&&flag==1){
                    ans+=a[1].x;
                    cnt++;
                    flag=2;
                }
                else if(ans+a[1].x>m&&flag==1)break;
                if(flag==2&&ans+a[1].y<=m){
                    ans+=a[1].y;
                    cnt++;
                    if(sum[1]<a[1].x+a[1].y){
                        ans=ans-(a[1].x+a[1].y);
                        ans+=sum[1];
                    }
                    flag=1;
                }
                else if(flag==2&&ans+a[1].y>m){
                    if(ans-a[1].x+sum[1]<=m){
                        ans-=a[1].x;
                        ans+=sum[1];
                        cnt++;
                        flag=1;
                    }
                    else break;
                }
            }
            cout<<cnt;
        }
    }
return 0;
}
