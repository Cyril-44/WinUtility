#include<bits/stdc++.h>
using namespace std;
long long const N=1e4;
long long a[N],p[N];
long long sum[N];
bool check[N];
long long deep[N];
vector<long long> dp[N],have[N];
long long t,n,m;

void so(long long now){
	if(have[now].size()==0)
		return;
	long long mx=0;
	for(int i=0;i<have[now].size();i++){
		//cout<<now<<" "<<<<"*\n";
		so(have[now][i]);
		sum[now]=max(sum[now],sum[have[now][i]]);
	}
	sum[now]++;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(deep,0,sizeof deep);
		memset(dp,0,sizeof dp);
		memset(sum,0,sizeof sum);
		memset(have,0,sizeof have);
		memset(check,0,sizeof check);
		
		cin>>n>>m;
		deep[1]=1;
		long long num=0;
		for(int i=2;i<=n;i++){
			cin>>p[i];
			have[p[i]].push_back(i);
			deep[i]=deep[p[i]]+1;
			dp[deep[i]].push_back(i);
			//cout<<have[p[i]][have[p[i]].size()-1]<<" ";
		}
		/*
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
			for(int j=0;j<have[i].size();j++)
				cout<<have[i][j]<<" "<<"\n";
			}
			*/
		for(int i=1;i<=n;i++){
			if(have[i].size()==0){
				if(check[p[i]]==0)
					num++,check[p[i]]=1;
				sum[p[i]]++;
			}
		}
		so(1);
		for(int i=1;i<=n;i++){
			//cout<<i<<" "<<sum[i]<<"\n";
			if(have[i].size()!=0){
				num+=sum[i];
			}
		}
		cout<<num<<"\n";
	}
}
