#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+10;
int x[maxn],y[maxn];
int sum[maxn];
int min_sum,ans;
int res,res2,siz;
vector<int> mi;
int pei[maxn];
int n,m;
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	int use_d;
	int flag = 0;
	int min_x = 1000000000;
	min_sum = 10000000000;
	for(int i = 1;i<=n;i++){
		cin>>x[i]>>y[i];
		sum[i] = x[i]+y[i];
		//min_sum = min(min_sum,sum[i]);
		if(sum[i]<min_sum){
			mi.clear();
			min_sum = sum[i];
			mi.push_back(i);
			siz = 1;
		}else if(sum[i]==min_sum){
			mi.push_back(i);
			siz++;
		}
	}
	//sort(sum+1,sum+1+n);
	//int cur = 1;
	/*while(x[cur]<=(sum[1]/2)&&cur<=n){
		//cur++;
		m-=x[cur];
		x[cur] = y[cur];
		ans++;
		cur++;
	}
	*/
	for(int i = 0;i<siz;i++){
		if(x[mi[i]]<=min_x){
			min_x = x[mi[i]];
			use_d = mi[i];
		}
	}
	int cur = 1;
	for(int i = 1;i<=n;i++){
		if(x[i]<=sum[mi[1]]){
			pei[cur] = x[i];
			cur++;
		}
	}
	sort(pei+1,pei+n+1);
	for(int i = cur-1;i>=2;i--){
		if(pei[i-1]+pei[i]>=sum[mi[1]]){
			if(pei[i]==x[use_d]||pei[i-1]==x[use_d]){
				flag = 1;
			}
			m-=sum[mi[1]];
			i-=1;
			ans+=2;
		}else{
			for(int j = i;j>=1;j--){
				m-=pei[j];
				ans++;
			}
			break;
		}
	}
	//for(int i = 0;i<siz;i++){
	res = m%sum[use_d];
	res2 = (m/sum[use_d])*2;
	if(res==0){
		ans+=res2;
		
	}else{
		if(flag==1){
			if(x[use_d]<=res){
				ans = ans+res2+1;
				
			}else{
				ans = ans+res2;
				
			}
		}else{
			if(y[use_d]<=res){
				ans = ans+res2+1;
				
			}else{
				ans = ans+res2;
				
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
