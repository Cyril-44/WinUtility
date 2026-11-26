#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,Mod=998242353;
int n,m,x[N],y[N],w[N],c[N],f[N],a[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	int QwQ=0;
	for(int i=1;i<=n;i++)
		if(x[i]!=y[i])
			QwQ=1;
	if(QwQ==0){
		int Min=1e9+10;
		for(int i=1;i<=n;i++)
			Min=min(Min,x[i]);
		cout<<m/Min;
		return ;
	}
	if(n<=1000&&m<=10000){
		for(int i=1;i<=n;i++){
			w[i+i-1]=1;
			c[i+i-1]=x[i];
			w[i+i]=2;
			c[i+i]=x[i]+y[i];
		}
		for(int i=1;i<=n+n;i++){
			if(i%2==0){
				for(int j=c[i];j<=m;j++)
					f[j]=max(f[j],f[j-c[i]]+w[i]);
			}
			else{
				for(int j=m;j>=c[i];j--)
					f[j]=max(f[j],f[j-c[i]]+w[i]);
			}
		}
		cout<<f[m];
		return ;
	}
	//目前是9：03，期望得分：70
	//直接背包应该有65分吧？
	int Min=2e9+5;
	for(int i=1;i<=n;i++)
		Min=min(Min,x[i]+y[i]);
	int cur=0;
	sort(x+1,x+n+1);
	int sum=-(m%Min);
	//cout<<sum<<" ";
	for(int i=1;i<=n;i++){
		sum+=x[i];
		//cout<<sum<<" ";
		if(sum>0)
			a[i]=(sum-1)/Min+1;
		else
			a[i]=0;
	}
	//cout<<endl;
	//for(int i=1;i<=n;i++)
	//	cout<<x[i]<<" ";
	//cout<<endl;
	//for(int i=1;i<=n;i++)
	//	cout<<a[i]<<" ";
	//cout<<endl;
	int k=m/Min,ans=k*2,r=1,l=0;
	for(int j=0;j<=k;j++){
		int temp=ans,c=0;
		ans-=j+j;
		for(int i=r;i<=n;i++){
			if(a[i]>j)
				break;
			r++;
			c++;
		}
		l+=c;
		cur=max(cur,ans+l);
		//cout<<ans<<" "<<l<<endl;
		if(c<2)
			break;
		ans=temp;
	}
	cout<<cur;
//9：40 只挂了第二个小洋里，破防
//9：43 所有洋里全过，我就当AC了
}
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    while(t--)
		solve();
	return 0;
}
//分越少的部分分一般更好拿
//绿蓝紫紫
