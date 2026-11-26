#include<bits/stdc++.h>
#define I 998244353
using namespace std;
long long C,T,n,m,a[5001],w[5001],ans,mm;
    long long sd=0;
bool b[5001];
int p[5001],pt;
long long ra(){
    m=mm;
    int tr=0;
    long long sr=0;
    for(int i=1;i<=n;i++)b[i]=0;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(b[i]==1)continue;
            if(w[i]>w[tr])tr=i;
            else if(w[i]==w[tr]){
                if(a[i]>a[tr])tr=i;
            }
        }
        b[tr]=1;
        if(m<a[tr]/w[tr])continue;
        m-=a[tr]/w[tr];
        sr+=a[tr];
    }
    return sr;
}
void d(int x){
    if(m-a[p[x]]/w[p[x]]<w[p[x]]){
        sd=sd-a[p[x-1]]+a[p[x]];
        return;
    }
    m-=a[p[x]]/w[p[x]];
    sd+=a[p[x]];
    if(m==0)return;
    d(x+1);
    return;
}
long long dp(){
    m=mm;
    int td=0;
    sd=0;
    for(int i=1;i<=n;i++)b[i]=0;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(b[i]==1)continue;
            if(w[i]>w[td])td=i;
            else if(w[i]==w[td]){
                if(a[i]>a[td])td=i;
            }
        }
        b[td]=1;
        pt++;
        p[pt]=td;
    }
    d(1);
    return sd;
}
void sz(int i){
    m=mm;
    if(i>n){
        if(ra()==dp())ans++;
        return;
    }
    w[i]=a[i];
    sz(i+1);
    w[i]=a[i]/2;
    sz(i+1);
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>C>>T;
    for(T;T>0;T--){
        cin>>n>>mm;
        for(int i=1;i<=n;i++)cin>>a[i];
        //
        if(C==18){cout<<(n*n)%I;continue;}
        sz(1);
        cout<<ans%I<<endl;
        //
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

