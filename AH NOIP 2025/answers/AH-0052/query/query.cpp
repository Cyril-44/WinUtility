#include<bits/stdc++.h>
using namespace std;
#define int long long 
void read(int &xxx){
    xxx=0;
    bool fll=0;
    char ccc=getchar();
    while(ccc<'0'||ccc>'9'){
        if(ccc=='-')fll=1;
        ccc=getchar();
    }
    while(ccc>='0'&&ccc<='9'){
        xxx=xxx*10+ccc-'0';
        ccc=getchar();
    }
    if(fll)xxx=-xxx;
}
const int N=5e4+5; 
int n;
int d[N];
int ans[N];
int a[N];
signed main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        read(a[i]);
        d[i]=d[i-1]+a[i];
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,y;
        read(x);
        read(y);
        for(int i=1;i<=n;i++)ans[i]=-1e8;
        for(int i=x-1;i<=y-1;i++){
            for(int l=1;l+i<=n;l++){
                int r=i+l;
                int sum=d[r]-d[l-1];
                for(int k=l;k<=r;k++){
                    ans[k]=max(ans[k],sum);
                }
            }
        }
        int ans2=0;
        for(int i=1;i<=n;i++){
            ans2^=ans[i];
        }
        cout<<ans2<<endl;
    }
    return 0;
}