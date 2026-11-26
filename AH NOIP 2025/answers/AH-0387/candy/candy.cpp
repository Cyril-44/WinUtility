#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m,cnt;
struct node{
    int a,b;
}val[100000+10];
bool cmp(node x,node y){
    return x.a+x.b<y.a+y.b;
}
bool cmp2(node x,node y){
    return x.a<y.a;
}
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>val[i].a>>val[i].b;
    sort(val+1,val+1+n,cmp);
    int tmp=val[1].a+val[1].b;
    sort(val+1,val+1+n,cmp2);
//    cout<<tmp<<endl;
    for(int i=1;i<=n;i++){
//        cout<<val[i].a<<" "<<val[i].b<<endl;
        if(val[i].a*2<=tmp){
            if(m>=val[i].a){
                m-=val[i].a;
                swap(val[i].a,val[i].b);
                cnt++;
            }else{
                cout<<cnt;
                return 0;
            }
        }
    }
//    cout<<m<<" "<<cnt<<endl;
    cnt+=m/tmp*2;
    m-=m/tmp*tmp;
    sort(val+1,val+1+n,cmp2);
//    cout<<val[1].a<<" "<<val[1].b<<endl;
    if(m>=val[1].a){
        m-=val[1].a;
        cnt++;
    }
    cout<<cnt;
    return 0;
}
/*
5 20
6 1
7 8
2 4
7 2
1 5
*/
