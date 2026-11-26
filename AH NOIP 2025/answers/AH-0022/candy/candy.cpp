#include<bits/stdc++.h>
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)

using namespace std;
const int N=1e5+5;
int n,m;
struct node{
    int x,y;
    int id;
}a[1145141];
int bhbh=0;
bool cmp(node x,node y) {
    return x.x+x.y<y.x+y.y;
}
bool cmp2(node x,node y){
    return x.x<y.x;
}
signed main() {
    freopen("candy.in","r",stdin);                                                
    freopen("candy.out","w",stdout);                                              
    cin>>n>>m;
    rep(i,1,n) {
        cin>>a[i].x>>a[i].y; 
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    int ans=0,ans2=0,m22=m;
    int ans3=0,nc=0;
    int ans4=0;
    int m3=m,m4=m;
    int os=a[1].x+a[1].y;
    ans+=(m/(a[1].x+a[1].y))*2;
    m%=(a[1].x+a[1].y);
    bhbh=a[1].id;
    if(os<=m4) {

         ans4+=(m4/(a[1].x+a[1].y)-1)*2;
         m4-=(m4/(a[1].x+a[1].y)-1)*os;

    }
    if(a[1].x<=m4) {
        ans4++;
        m4-=a[1].x;
    }

  //  cout<<ans4<<' '<<m4<<endl<<endl;
    sort(a+1,a+n+1,cmp2);
    rep(i,1,n) {
        if(m>=a[i].x) {
            m-=a[i].x;
            ans++;
        }
        if(m22>=a[i].x){
            m22-=a[i].x;
            ans2++;
        }

        if(m3>=a[i].x) {
            m3-=a[i].x;
            nc++;
            ans3=max(ans3,nc+(m3/os)*2);
        }


        if(m4>=a[i].x&&a[i].id!=bhbh){
            m4-=a[i].x;
            ans4++;
        }//cuode 

    }

    // cout<<ans<<' '<<ans4<<endl;
    cout<<max(max(ans,ans2),max(ans3,ans4));
    return 0;
}
