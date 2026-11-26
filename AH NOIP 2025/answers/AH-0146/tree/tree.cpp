#include<bits/stdc++.h>
using namespace std;
int t[8005];
vector<int> son[8005];
int tree(int x){
	int sum=0;
	if(son[x].size()==0){
		return 1;
	}
	for(long unsigned int i=0;i<son[x].size();i++){
		sum+=tree(son[x][i]);
	}
	return sum;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(t,0,sizeof(t));
		int n,m,sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			son[i].clear();
		}
		if(m==1){cout<<1<<endl;continue;}
		if(m==2){cout<<n+1<<endl;continue;}
		for(int i=2;i<=n;i++){
			cin>>t[i];son[t[i]].push_back(i);
		}
		for(int i=2;i<=n;i++){
			sum=sum+tree(i)+1;
		}
		cout<<sum+1+sum<<endl;
	}
	return 0;
}
