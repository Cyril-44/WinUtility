#include<bits/stdc++.h>
using namespace std;
const int N=5010,M=998244353;
int c,t,n,m,a[N],tp,sum=1,cnt;
double d[N];
bool flag;
void p(int di,int zhi){
    while(zhi--) sum=(sum*di)%M;
    cout<<sum;
}
bool cmp(double u,double v){
    return u>v;
}
void dfs(int num){
    if(num==n){
        sort(d+1,d+1+n,cmp);

    }
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--){
        cin>>n>>m;
        if(n==1&&m>=1){
            cout<<2;
            return 0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==1) tp=a[i];
            if(tp!=a[i]) flag=1;
        }
        if(flag==0){
            p(2,n);
            return 0;
        }
        dfs(1);
	}
	return 0;
}
