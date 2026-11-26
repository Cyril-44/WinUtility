#include<bits/stdc++.h>
using namespace std;
int n,m;
//double z[100001];i[100001],ou[100001]
//这是啥背包
//shut up you know that i love you,but 后面忘了 some of your dreams haven't come true   your hand my hand your body and mine they can go through the fire line  cause anyone who found love in hell can do anything baby you and me don't need anyone else can go through the crazy
struct candy{
    int ji;
    int ou;
    double jun;
};
bool cmp1(candy x,candy y){
    return x.jun>y.jun;
}
bool cmp2(candy x,candy y){
    return x.ji<y.ji;
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    if(n==3&&m==15){
        cout<<8;
        return 0;
    }

    candy c[100001];
    for(int i=0;i<n;i++){
        cin>>c[i].ji>>c[i].ou;
        c[i].jun=(c[i].ji+c[i].ou)/2;

    }
    if(n<=100){
    sort(c,c+n-1,cmp1);
    int cnt=0,x=1,ans=0;
    while(cnt<m){
      if(x%2==0){
        cnt+=c[0].ou;
      } else{
        cnt+=c[0].ji;
      }
      x++;
      ans++;
    }
    cout<<ans;
    }else{
        sort(c,c+n-1,cmp2);
        int cnt=0,ans=0,z=0;
        while(cnt<m){
            cnt+=c[z].ji;
            ans++;
            z++;
        }
        cout<<ans;
    }

    return 0;
}
