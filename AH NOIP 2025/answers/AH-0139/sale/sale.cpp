#include<bits/stdc++.h>
using namespace std;
long long c,T,n,m,a[5050],ans,M=998244353;
long long dp[44][121];
struct candy
{
    long long v;
    long long c;
    long long id;
}b[5050];

bool cmp(int x,int y){
    return x>y;
}
bool cmp2(candy x,candy y){
    if(x.v*2/x.c==y.v*2/y.c){
        if(x.v==y.v)return x.id>y.id;
        else return x.v>y.v;
    }
    return x.v*2/x.c>y.v*2/y.c;
}
int qp(int d,int p){
    long long sum=d,dd=1;
    while(p){
	
		
        if(p&1){
		//	cout<<'k';
            dd*=sum;
            dd%=M;
        }
        sum*=sum;sum%=M;
        p/=2;
	
    }
    return dd;
}
int bs(int n,int l,int r){
    int mid =(l+r)/2;
    while(r-l>1){
        mid =(l+r)/2;
        if(a[mid]>n)l=mid;
        else r=mid;
    }
    return l;
}
int jc(int l,int r){
    long long a=1;
    for(int i=l;i>=r;i--){
        a*=i;
        a%=M;
    }
    return a;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        
		if((c>=7&&c<=9)||(c>=14&&c<=15)){
            sort(a+1,a+1+n,cmp);
            int cnt=0;
            for(cnt=1;cnt<=n;cnt++){
                if(a[cnt]*2<a[1]){
                    break;
                }
            }
            cnt--;
            ans+=qp(2,n-cnt);//buy 1
            if(cnt>=2){
                for(int i=2;i<=cnt;i++){
                    ans+=(i*i-i)/2*((qp(2,cnt-i)-1)*qp(2,n-cnt))%M;
                    ans%=M;
                }
            }
            ans%=M;
            for(int i=1;i<=cnt;i++){
                int k=bs(a[1]-a[i],cnt+1,n+1);
          //      cout<<k<<' '<<endl;
                ans+=qp(2,n-k)*(k-cnt)%M;
                ans%=M;
            }
            long long flag=0;
            for(int i=1;i<=bs(a[1]-a[i],1,n);i++){
                for(int j=i+1;j<=bs(a[1]-a[i],1,n);j++){
                    if(a[i]+a[j]<a[1])flag++;
               }
            }
            ans=qp(2,n)-flag%M;
        }
        else{
            for(int i=0;i<qp(2,n);i++){
//                cout<<"s"<<i<<endl;
                for(int j=1;j<=n;j++){
   //                 cout<<"f"<< (((i>>(j-1))&1)+1) ;
                    b[j].v=a[j];b[j].c=(((i>>(j-1))&1)+1);b[j].id=j;
  //                  cout<<"b"<<b[j].v<<endl;
                }
                sort(b+1,b+n+1,cmp2);
                long long pv=0,mm=m;
                for(int j=1;j<=n;j++){
                    if(b[j].c<=mm){
                        pv+=b[j].v;mm-=b[j].c;
  //                      cout<<"p"<<pv<<' '<<mm<<endl;
                    }
                    if(mm<=0)break;
                }
                for(int j=1;j<=n;j++){//bag dp wuping
                    for(int k=1;k<=m;k++){//cost
                        if(k>=b[j].c){
                            dp[j][k]=max(dp[j-1][k],dp[j-1][k-b[j].c]+b[j].v);
                        }
                        else dp[j][k]=dp[j-1][k];
                    }
                }
                if(dp[n][m]==pv)ans++;
   //             cout<<"A"<<pv<<' '<<dp[n][m]<<endl;
                memset(dp,0,sizeof(dp));
            }
        }
        cout<<ans<<endl;
        ans=0;
	}
    return 0;
}
//10:18打部分分
//11:51 1-5ok +=20pts
//混乱邪恶题目
