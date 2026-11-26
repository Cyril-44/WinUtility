#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int C,t,n,m,ans=0;
int k[5111],jl[5111],kk[5111],bg[5111];

bool cmp(int x,int y){
return x>y;}

bool ok(){
    int temp[5555],tjl[5555];
    for(int a=1;a<=5000;a++){
            tjl[a]=jl[a];
            temp[a]=k[a];
        bg[a]=0;
    }
    for(int a=1;a<=n;a++){
        kk[a]=k[a];
        kk[a]/=tjl[a];
    }
    for(int a=1;a<=n;a++){
        for(int b=m;b>=tjl[a];b--){
            bg[b]=max(bg[b],bg[b-tjl[a]]+k[a]);
        }
    }
    for(int a=1;a<=n;a++){
        for(int b=1;b<=(n-a+1);b++){
            if(kk[b]<kk[b+1]){
                swap(kk[b],kk[b+1]);
                swap(temp[b],temp[b+1]);
                swap(tjl[b],tjl[b+1]);
            }
        }
    }
    int s=m,sum=0;
    for(int a=1;a<=n;a++){
        if(s>=tjl[a]){
            s-=tjl[a];
            sum+=temp[a];
        }
    }
    if(sum==bg[m]){
        return true;
    }
    return false;
}

void ss(int x){
    if(x>n){
        if(ok()){
            ans++;
        }
        return ;
    }
    for(int a=1;a<=2;a++){
        jl[x]=a;
        ss(x+1);
        jl[x]=0;
    }
}

int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
cin>>C>>t;
while(t--){
    cin>>n>>m;
    ans=0;
    for(int a=1;a<=n;a++){
        cin>>k[a];
        k[a]*=2;
    }
    sort(k+1,k+n+1);
    ss(1);
    cout<<ans<<endl;
}
}
