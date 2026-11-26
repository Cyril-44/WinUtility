#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
int x;
int y;
};
int comp(node e,node h){
      if(e.x<h.x) return 1;
      else return 0;
}

node a[100005];
int b[100005];
int n,m;
int sum;
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        b[i]=a[i].x+a[i].y;
    }
    sort(a+1,a+1+n,comp);
    sort(b+1,b+1+n);
    int l=1;
    int k;
    while(m!=0){
            if(2*a[l].x<b[1]) {
                if(m>=a[l].x){
                    sum++;
                    m-=a[l].x;
                    k+=a[l].x;
                    a[l].x=a[l].y;
                }
            }
            else{
                sum+=(m/b[1])*2;
                m=m%b[1];
                break;
            }
    l++;
    }
    sort(a+1,a+1+n,comp);
    l=1;
    while(m!=0){
        if(m>=a[l].x){
            sum++;
            m-=a[l].x;
        }
        else break;
        l++;
    }
    cout<<sum;
return 0;
}
