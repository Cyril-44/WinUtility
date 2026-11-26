#include<bits/stdc++.h>
#define ffor(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fford(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
#define inf 1e10
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,rest,rest2,ans=0,ans2=0,minid;bool flag=false;
struct it{
    int a,b,sum,id;
    bool operator<(it &other){
        return sum<other.sum;
    }
}v[N];
bool cmp(it &x,it &y){
    return x.a<y.a;
}
signed main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    //n=3;m=1e18;
    ffor(i,1,n) cin>>v[i].a>>v[i].b,v[i].sum=v[i].a+v[i].b,v[i].id=i;
    sort(v+1,v+n+1);
    //ffor(i,1,n) cout<<"---"<<v[i].a<<"$"<<v[i].b<<endl;
    minid=v[1].id;
    //cout<<m/v[1].sum*2<<endl;
    ans+=m/v[1].sum*2;
    rest=m%v[1].sum;
    if(ans>=1){
        flag=true;
        rest2=rest+v[1].b;
        ans2=ans-1;
    }
    sort(v+1,v+n+1,cmp);
    //ffor(i,1,n) cout<<"???"<<v[i].a<<"$"<<v[i].b<<endl;
    //cout<<"---"<<rest<<endl;
    //cout<<"---"<<rest2<<endl;
    //cout<<rest/v[1].a<<endl;
    ffor(i,1,n){
        if(rest>=v[i].a){
            ans++;rest-=v[i].a;
        }else break;
    }
    if(flag){
        ffor(i,1,n){
            if(rest2>=v[i].a){
                if(v[i].id!=minid) ans2++;rest2-=v[i].a;
            }else break;
        }
    }
    cout<<max(ans,ans2);
    return 0;
}
