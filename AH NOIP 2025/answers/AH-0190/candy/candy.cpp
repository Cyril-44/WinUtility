#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int x,y;
}a[100055];
int next(int id,int t){
	if(t==a[id].x) return a[id].y;
	return a[id].y;
}
bool cmp(edge x,edge y){
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}
struct node{
	int u,id;
	bool operator > (const node& a) const{
		return u>a.u;
	}
};
priority_queue<node,vector<node>,greater<node> > q;
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mi=0x3f3f3f3f3f3f3f3f;
	int u1=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		if(mi>a[i].x+a[i].y){
			mi=a[i].x+a[i].y;
			u1=min(a[i].x,a[i].y);
		}
		if(mi==a[i].x+a[i].y){
			u1=min(u1,min(a[i].x,a[i].y));
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		q.push({a[i].x,i});
	}
	int cnt=0;
	while(m>0){
		int t1=q.top().u;
		int id1=q.top().id;
		q.pop();
		int t2=q.top().u;
		int id2=q.top().id;
		q.pop();
		if(m<t1+t2&&m<mi){
			if(next(id1,t1)>next(id2,t2)&&t1==t2){
				swap(id1,id2);
				swap(t1,t2);
			}
			if(m<t1) break;
			m-=t1;
			cnt++;
			q.push({next(id1,t1),id1});
			q.push({t2,id2});
		}
		else if(t1+t2<=mi){
			m-=(t1+t2);
			cnt+=2;
			q.push({next(id1,t1),id1});
			q.push({next(id2,t2),id2});
		}
		else if(mi<t1+t2){
			if(t1<=u1){
				m-=t1;
				cnt++;
				q.push({next(id1,t1),id1});
				q.push({t2,id2});
			}else{
				cnt+=2*(m/mi);
				m%=mi;
				q.push({t1,id1});
				q.push({t2,id2});
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
