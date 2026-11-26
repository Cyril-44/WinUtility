#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,minn=1000000000000000000;
struct str{
	long long x,y,i;
	bool operator > (const str &rhs) const{
		if(x!=rhs.x) return x>rhs.x;
		return y>rhs.y;
	}
}k;
priority_queue<str,vector<str>,greater<str> > pq;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k.x>>k.y;
		k.i=i;
		pq.push(k);
		minn=min(minn,k.x+k.y);
	}
	while(m>0){
		k=pq.top();
		pq.pop();
		
		if(k.x*2>=minn){
			while(m>=minn){
				m-=minn;
				cnt+=2;
			}
			cout<<m<<endl;
		}
		if(m<k.x) break;
		m-=k.x;
		cnt++;
		long long t=k.x;
		k.x=k.y;
		k.y=t;
		pq.push(k);
	}
	cout<<cnt;
	return 0;
}
