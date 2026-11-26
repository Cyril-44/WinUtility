#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,m,i,a[N],b,s=1e15,c,w;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b;
		s=min(a[i]+b,s);
	}
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		if(a[i]*2<=s){
			if(m>=a[i]){m-=a[i];w++;}
			else break;
		}
		else{
			w=w+m/s*2;
			m=m-m/s*s;
			break;
		}
	}
	w=w+m/s*2;
	m=m-m/s*s;
	if(m+a[i-1]>=s)w++;
	cout<<w;
}

