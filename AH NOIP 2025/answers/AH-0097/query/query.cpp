#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+9,M=1039;
struct question{
	int lm,rm;
}q[M];
int ls(int x){return (x<<1);}
int rs(int x){return ((x<<1)|1);}
int n,m,a[N],sum[N],ffmax[N][29],ffmin[N][29],lg2[N];
struct bit_tree{
	int maxed=-1e18;
}tr[N*4];
void push_up(int k){
	tr[k].maxed=max(tr[ls(k)].maxed,tr[rs(k)].maxed);
	return;
}
void push_down(int k){
	tr[ls(k)].maxed=max(tr[ls(k)].maxed,tr[k].maxed);
	tr[rs(k)].maxed=max(tr[rs(k)].maxed,tr[k].maxed);
	return;
}
void build(int l,int r,int k){
	if(l>r){
		return;
	}
	if(l==r){
		// cout<<k<<" "<<tr[k].maxed<<endl;
		tr[k].maxed=-1e18;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls(k));
	build(mid+1,r,rs(k));
	push_up(k);
	// cout<<k<<" "<<tr[k].maxed<<endl;
	return;
}
void change(int nl,int nr,int l,int r,int val,int k){
	if((l>r)||(r<nl)||(l>nr)){
		return;
	}
	if(nl<=l&&r<=nr){
		tr[k].maxed=max(tr[k].maxed,val);
		return;
	}
	push_down(k);
	int mid=(l+r)>>1;
	if(mid>=nl){
		change(nl,nr,l,mid,val,ls(k));
	}
	if(mid+1<=nr){
		change(nl,nr,mid+1,r,val,rs(k));
	}
	// push_up(k);
	return;
}
int ask(int nl,int nr,int l,int r,int k){
	if((l>r)||(r<nl)||(l>nr)){
		return -1e18;
	}
	if(nl<=l&&r<=nr){
		return tr[k].maxed;
	}
	push_down(k);
	int mid=(l+r)>>1,res=-1e18;
	if(mid>=nl){
		res=max(res,ask(nl,nr,l,mid,ls(k)));
	}
	if(mid+1<=nr){
		res=max(res,ask(nl,nr,mid+1,r,rs(k)));
	}
	return res;
}
void print(){
	for(int i=1;i<=7;i++){
		cout<<i<<":"<<tr[i].maxed<<endl;
	}
	cout<<endl;
	return;
}
int getmax(int l,int r){
	int len=(r-l+1),tmp=lg2[len];
	if(sum[ffmax[l][tmp]]>sum[ffmax[r-(1<<tmp)+1][tmp]]){
		return ffmax[l][tmp];
	}
	else{
		return ffmax[r-(1<<tmp)+1][tmp];
	}
}
int getmin(int l,int r){
	int len=(r-l+1),tmp=lg2[len];
	if(sum[ffmin[l][tmp]]<sum[ffmin[r-(1<<tmp)+1][tmp]]){
		return ffmin[l][tmp];
	}
	else{
		return ffmin[r-(1<<tmp)+1][tmp];
	}
}
void solve(int Casenum){
	build(1,n,1);
	// for(int i=0;i<=n;i++){
	// 	sl[i]=sr[i]=0;
	// }
	int lm=q[Casenum].lm,rm=q[Casenum].rm;
	/*for(int i=lm;i<=rm;i++){
		change(1,i,1,n,sum[i],1);
	}
	for(int i=n-lm+1;i>=n-rm+1;i--){
		change(i,n,1,n,sum[n]-sum[i-1],1);
	}*/
	deque<int>dq;
	for(int i=lm;i<=n;i++){//i:r deque:l
		while(!dq.empty()&&rm<i-dq.front()+1){
			dq.pop_front();
		}
		while(!dq.empty()&&sum[dq.back()-1]>sum[(i-lm+1)-1]){
			dq.pop_back();
		}
		dq.push_back(i-lm+1);
		// cout<<dq.front()<<" "<<i<<" "<<sum[i]-sum[dq.front()-1]<<endl;
		int len=i-dq.front()+1;
		int tmp=getmax(i,min(n,rm-len+i));
		change(dq.front(),tmp,1,n,sum[tmp]-sum[dq.front()-1],1);
		change(dq.front(),i,1,n,sum[i]-sum[dq.front()-1],1);
		/*tmp=getmin(i,min(n,rm-len+i));
		change(dq.front(),tmp,1,n,sum[tmp]-sum[dq.front()-1],1);*/
		// print();
	}
	dq.clear();
	for(int i=n-lm+1;i>=1;i--){//i:l deque:r
		while(!dq.empty()&&rm<dq.front()-i+1){
			dq.pop_front();
		}
		while(!dq.empty()&&sum[dq.back()]<sum[i+lm-1]){
			dq.pop_back();
		}
		dq.push_back(i+lm-1);
		// cout<<i<<" "<<dq.front()<<" "<<sum[dq.front()]-sum[i-1]<<endl;
		int len=dq.front()-i+1;
		int tmp=getmin(max(1ll,i-(rm-len)),i);
		change(tmp,dq.front(),1,n,sum[dq.front()]-sum[tmp-1],1);
		change(i,dq.front(),1,n,sum[dq.front()]-sum[i-1],1);
		/*tmp=getmax(max(1ll,i-(rm-len)),i);
		change(tmp,dq.front(),1,n,sum[dq.front()]-sum[tmp-1],1);*/
		// print();
	}
	dq.clear();
	unsigned long long ans=0;
	for(int i=1;i<=n;i++){
		int ki=ask(i,i,1,n,1);
		// cout<<ki<<" ";
		ans^=((unsigned long long )(i)*(unsigned long long)(ki));
	}
	// cout<<endl;
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	lg2[1]=0;
	for(int i=2;i<=n+3;i++){
		lg2[i]=lg2[i>>1]+1;
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			ffmax[i][j]=-1e18;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		ffmax[i][0]=ffmin[i][0]=i;
	}
	ffmax[n+1][0]=ffmin[n+1][0]=sum[n+1]=sum[n];
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n+1;i++){
			if(sum[ffmax[i][j-1]]>sum[ffmax[min(i+(1<<(j-1)),n)][j-1]]){
				ffmax[i][j]=ffmax[i][j-1];
			}
			else{
				ffmax[i][j]=ffmax[min(i+(1<<(j-1)),n)][j-1];
			}
			if(sum[ffmin[i][j-1]]<sum[ffmin[min(i+(1<<(j-1)),n)][j-1]]){
				ffmin[i][j]=ffmin[i][j-1];
			}
			else{
				ffmin[i][j]=ffmin[min(i+(1<<(j-1)),n)][j-1];
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<sum[i]<<" ";
	// }
	// cout<<endl<<endl;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>q[i].lm>>q[i].rm;
		solve(i);
	}
	return 0;
}