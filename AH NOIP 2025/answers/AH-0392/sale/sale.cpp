#include<bits/stdc++.h>
using namespace std;
    long long c,t,n,m,a[5010],fa,ma,he[5010],ooo,dp1[5010][5010];
    struct stu{
		long long yuan,id;
		double dp;
	}ab[5010];
	bool cmp(const stu &x,const stu &y){
		if(x.dp!=y.dp)return x.dp>y.dp;
		if(x.yuan!=y.yuan)return x.yuan>y.yuan;
		return x.id<y.id;
	}
    long long pow1(int kl,long long x){
    long long ans=1;
    for(int i=1;i<=x;i++){
    ans*=2;
    ans%=998244353;
    }
    return ans;
    }
    int check(){
		long long mm=m;
		for(int i=1;i<=n;i++){
			ab[i].yuan=a[i];
			ab[i].dp=a[i]*1.0/he[i];
			ab[i].id=i;
		}
		sort(ab+1,ab+n+1,cmp);
		long long hj=0;
		for(int i=1;i<=n;i++){
			if(mm>=he[i]){
			mm-=he[i];
			hj+=ab[i].yuan;	
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(he[j]>j)dp1[i][j]=dp1[i-1][j];
				else dp1[i][j]=max(dp1[i-1][j],dp1[i-1][j-he[i]]+ab[i].yuan);
			}
		}
		if(hj==dp1[n][m]){return 1;}
		else return 0;
	}
    void dfs(int cur){
		if(cur>n){
			if(check())ooo++;
			ooo%=998244353;
		}
		he[cur]=2;
		dfs(cur+1);
		he[cur]=1;
		dfs(cur+1);
		he[cur]=0;
	}
    int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
		fa=0;
		ma=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
    ma=max(ma,a[i]);
    if(i>1&&a[i]!=a[i-1])fa=1;
    }
    sort(a+1,a+n+1);
    if(fa==0&&m==2*n-1){
		cout<<pow1(2,n)<<endl;
		continue;
	}
    if(m==2*n-2){
    if(a[2]>=2*a[1]||a[2]==a[1])cout<<pow1(2,n)<<endl;
    else cout<<pow1(2,n)-1<<endl;
    continue;
    }
    if(m==2){
		long long cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]*1.0>ma*1.0/2&&a[i]!=ma)cnt++;
		}
		for(int i=1;i<=n;i++){
			if(a[i]!=ma&&a[i]*1.0>ma*1.0/2){
				for(int j=1;j<i;j++){
					if(a[i]+a[j]<ma){
						cnt+=pow1(1,j-1);
					}
					else break;
				}
			}
		}
		long long pos=pow1(2,n)-cnt;
		while(pos<0)pos+=998244353;
		cout<<pos<<endl;
		continue;
	}
	ooo=0;
	dfs(1);
	cout<<ooo<<endl;
    }
    return 0;
}
