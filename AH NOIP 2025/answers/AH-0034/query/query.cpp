#include<bits/stdc++.h>
#define N 10005
using namespace std;
int a[N],L[N],R[N],fon[N];
struct st{
	int l,r,sum;
};
vector<st> v[N];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	cout<<1;
	for(int i=1;i<=n;i++)
	fon[i]=fon[i-1]+a[i];
	cin>>q;
	for(int i=1;i<=q;i++)
	cin>>L[i]>>R[i];
	for(int len=1;len<=n;len++){
		deque<st> dq;
		for(int i=1;i<=n;i++){
			while(!dq.empty()&&dq.front().l+len-1<=i) dq.pop_front();
			if(i+len-1<=n){
				st pre={i,i+len-1,fon[i+len-1]-fon[i-1]};
				while(!dq.empty()&&dq.back().sum<=pre.sum) dq.pop_back();
				dq.push_back(pre);
			}
			v[len][i]=dq.front();
		}
	}
	return 0;
}
