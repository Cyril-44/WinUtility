#include<bits/stdc++.h>
using namespace std;
int nn[1001001],l;
bool chk(int x){
	for(int i=1;i<=l;i++){
		if(x==nn[i]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		l=0;
		int n,m,gs=0,gs2=0,k;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>k;
			if(k==1)gs++;
			else {
				if(chk(k)){
					l++;
					nn[l]=k;
					
				}else{
					gs2++;
				}
			}
		}
		cout<<n+gs+gs2;
	}
	return 0;
}
