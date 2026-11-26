#include<bits/stdc++.h>
#define PII pair<int,int>
#define LL long long
#define x first
#define y second
using namespace std;
const int N=1e5+10;
int n,a[N][2];LL m;
PII b[N];
struct Node{
	int x,y,s;
};
bool CMP(PII t1,PII t2){
	return t1.x+t1.y<t2.x+t2.y;
}
struct cmp{
	bool operator()(Node &t1,Node &t2)const{
		if(t1.x!=t2.x) return t1.x>t2.x;
		else return a[t1.y][(t1.s+1)%2]>a[t2.y][(t2.s+1)%2];
	}
};
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	priority_queue<Node,vector<Node>,cmp>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
		b[i]={a[i][0],a[i][1]};
		q.push({a[i][0],i,0});
	}
	sort(b+1,b+n+1,CMP);
	int tmp=b[1].x+b[1].y;
	LL cnt=0,v=m/(b[1].x+b[1].y);
	cnt+=v*2;m-=v*(b[1].x+b[1].y);
	LL res=cnt;
	while(true){
		if(clock()/CLOCKS_PER_SEC>0.88) break;
		Node t=q.top();q.pop();
		if(m<t.x){
			cnt-=(t.x-m+tmp-1)/tmp*2ll;
			m+=(t.x-m+tmp-1)/tmp*tmp;
		}
		m-=t.x;cnt++;
		res=max(res,cnt);
		q.push({a[t.y][(t.s+1)%2],t.y,t.s^1});
	}
	cout<<res<<"\n";
	return 0;
}