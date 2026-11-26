#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=50010;
int n;
int a[N],q,num[N],lst[N],s[N];
unsigned long long ans[N];
pair<pair<int,int>,int>qu[2000];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]+s[i-1];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>qu[i].first.first>>qu[i].first.second;
		qu[i].second=i;
	}
	sort(qu+1,qu+q+1);
	for(int i=1;i<=q;i++){
		int id=qu[i].second,L=qu[i].first.first,R=qu[i].first.second;
		// tie(L,R,id)=qu[i];
		// cout<<id<<":";
		for(int i=1;i<=n;i++){
			// if(lst[i]>R||lst[i]<L){
				num[i]=-1e18;
				for(int len=L;len<=R;len++){
					for(int l=max(i-len+1,1ll);l<=i&&(l+len-1)<=n;l++){
						int r=l+len-1;
						// cout<<s[r]-s[l-1]<<endl;
						if(s[r]-s[l-1]>num[i]){
							num[i]=s[r]-s[l-1];
							lst[i]=len;
						}
					}
				}
			// }
		}
		// for(int i=1;i<=n;i++)
		// 	cout<<num[i]<<" ";
		// cout<<endl;
		for(int i=1;i<=n;i++)
			ans[id]=(ans[id]^((unsigned long long)i*num[i]));
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
	return 0;
}