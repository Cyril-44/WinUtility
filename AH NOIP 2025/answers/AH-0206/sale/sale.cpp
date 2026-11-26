#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int c,t;
int idxx[5005];
long long a[5005];
struct node{
    int yj,dj,idx;
    double xjb;
}x[5005],y[5005];
bool cmp(node u,node v){
    if(u.xjb!=v.xjb){
        return u.xjb>v.xjb;
    }
    else if(u.yj!=v.yj){
        return u.yj>v.yj;
    }
    else return u.idx<v.idx;
}
long long dp[5005][10005];
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        memset(x,0,sizeof(x));
        memset(idxx,0,sizeof(idxx));
        bool book=true;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=a[i-1])book=false;
            y[i].idx=i;
            y[i].yj=a[i];
            idxx[i]=1;
        }
        if(m==2*n-1||book){
            long long cnt=1;
            for(int i=1;i<=n;i++){
                cnt=(cnt*2)%MOD;
            }
            cout<<cnt<<endl;
            continue;
        }
            int cnt=0;
            bool flag=true;
            //背包计算最大总原价，性价比排序算比较
            while(flag){

                memset(dp,0,sizeof(dp));
                for(int i=1;i<=n;i++){
//                    cout<<idxx[i]<<" ";
                    x[i]=y[i];
                }

//                cout<<endl;
                int q=m,sum=0;
                for(int i=1;i<=n;i++){
                    x[i].dj=idxx[i];
                    x[i].xjb=(double)(x[i].yj)/(double)(x[i].dj);
//                    cout<<x[i].yj<<" "<<x[i].xjb<<endl;
                }
                sort(x+1,x+1+n,cmp);
                for(int i=1;i<=n;i++){
//                        cout<<x[i].yj<<" ";
                    if(q>=x[i].dj){
                        q-=x[i].dj;
                        sum+=x[i].yj;
                    }
                    if(q==0)break;
                }
//                cout<<endl;
                for(int i=1;i<=n;i++){
                    for(int j=0;j<=m;j++){
                        if(j<x[i].dj){
                            dp[i][j]=dp[i-1][j];
                            continue;
                        }
                        if(x[i].dj==1){
                            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+x[i].yj);
                        }
                        else if(x[i].dj==2){
                            dp[i][j]=max(dp[i-1][j],dp[i-1][j-2]+x[i].yj);
                        }
                    }
                }
                long long maxn=0;
                for(int i=0;i<=m;i++){
                    maxn=max(maxn,dp[n][i]);
//                    cout<<dp[n][i]<<" ";
                }
//                cout<<endl;

                if(sum==maxn){
                        /*
                    for(int i=1;i<=n;i++){
                        cout<<idxx[i]<<" ";
                    }
                    */
                    cnt=(cnt+1)%MOD;
//                    cout<<sum<<endl;
                }
                idxx[1]++;
                int i=1;
                while(idxx[i]==3){
                    idxx[i]=1;
                    idxx[++i]++;
                    if(i==n+1){
                        flag=false;
                        break;
                    }
                }

            }
            cout<<cnt<<endl;
            continue;

    }
    return 0;
}
