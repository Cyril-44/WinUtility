#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9){
        write(x/10);
    }
    putchar(x%10+'0');
}
const int N=1e5+5;
struct Node{
    int x,y;
    bool operator < (const Node &rhs) const {
        if(x+y==rhs.x+rhs.y){
            return x<rhs.x;
        }
        return x+y<rhs.x+rhs.y;
    }
}a[N];
bool flag[N];
int n,m,dp[1005][10005],minx;
//错的，应该用反悔贪心，过会再想
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j>=a[i].x){
                dp[i][j]=max(dp[i-1][j-a[i].x]+1,dp[i-1][j]);
            }
            int maxk=j/(a[i].x+a[i].y);
            for(int k=1;k<=maxk;k++){
                //dp[i][j]=max(dp[i-1][j-(a[i].x+a[i].y)*k+a[i].x]+k+k-1,dp[i][j]);
                dp[i][j]=max(dp[i-1][j-(a[i].x+a[i].y)*k]+k+k,dp[i][j]);
            }
            if(maxk*(a[i].x+a[i].y)+a[i].x<=j){
                dp[i][j]=max(dp[i-1][j-(a[i].x+a[i].y)*maxk-a[i].x]+maxk+maxk+1,dp[i][j]);
            }
        }
    }
    write(dp[n][m]);
}
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    n=read();m=read();
    bool flag=1;
    for(int i=1;i<=n;i++){
        a[i].x=read();
        a[i].y=read();
        if(a[i].x!=a[i].y){
            flag=0;
        }
        minx=min(minx,a[i].x);
    }
    sort(a+1,a+n+1);
    if(n<=1000&&m<=10000){
        solve();
        return 0;
    }
    else if(flag){
        int ans=m/(a[1].x+a[1].y);
        if(ans*(a[1].x+a[1].y)+minx<=m){
            write(ans*2+1);
            return 0;
        }
        write(ans*2);
    }
    else{
        puts("AFO,goodbye OI, I love C++");
        puts("zhu ni wo zai tui yi zhi hou reng bao chi dui suan fa jing sai de re ai");
        puts("bu yao zai bai lan le, wei lai XCPC zai hui");
    }
    return 0;
}
