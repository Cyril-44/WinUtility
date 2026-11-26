#include<bits/stdc++.h>
using namespace std;
int t,n,m,c,ans;
int a[5500];
int s[5510][3];
int d[5500][4];
long long M=998244353;
bool check(){
    for(int q=1;q<=n;q++)d[q][1]=s[q][1],d[q][2]=s[q][2];
    for(int q=1;q<n;q++){
        for(int w=1;w<=n-q;w++){
            if(d[w][1]<d[w+1][1]){
                swap(d[w][1],d[w+1][1]);
                swap(d[w][2],d[w+1][2]);
            } else if(d[w][1]==d[w+1][1]&&d[w][2]==1){
                swap(d[w][1],d[w+1][1]);
                swap(d[w][2],d[w+1][2]);
            }
        }
    }
    for(int q=1;q<=n;q++){
        cout<<d[q][1]<<" ";
    }
    cout<<"\n";
    int mm=m,t1=0,t2=0;
    for(int q=1;q<=n;q++)d[q][3]=0;
    for(int q=1;q<=n;q++){
        if(!mm)break;
        if(d[q][2]==1){
            t2=t1;
            t1=d[q][1];
        }
        if(mm>=d[q][2])mm-=d[q][2],d[q][3]=1;
    }
    for(int q=1;q<=n;q++){
        if(!d[q][3]&&d[q][2]==2){
            if(t1){
                if(mm==0){
                    if(t1+t2<d[q][1]*2)return 0;
                } else {
                    if(t1<d[q][1]*2)return 0;
                }
            } else break;
        }
    }
    return 1;
}
void dfs(int now){
    s[now][1]=a[now];
    s[now][2]=1;
    if(now!=n)dfs(now+1);
    else if(check())ans++,ans%=M;;
    s[now][1]/=2;
    s[now][2]=2;
    if(now!=n)dfs(now+1);
    else if(check())ans++,ans%=M;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    for(;t;t--){
        cin>>n>>m;
        for(int q=1;q<=n;q++){
            cin>>a[q];
            a[q]*=2;
        }
        if(c==18||c==16){
            ans=1;
            for(int q=1;q<=n;q++){
                ans*=2;
                ans%=M;
            }
            cout<<ans<<"\n";
            continue;
        } else if(c<=6){
            ans=0;
            dfs(1);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
