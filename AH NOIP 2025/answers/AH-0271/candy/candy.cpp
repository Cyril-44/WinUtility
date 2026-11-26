#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010
struct price{
	int type;
	long long x,y;
}p[MAXN];
struct node{
	int num;
	int p;
	int type;
}tmp,heap[MAXN];
int top=0;
long long m;
int n;
void up_fix(int x){
	while((heap[x].p<heap[x/2].p||(heap[x].p==heap[x/2].p&&heap[x].type<heap[x/2].type))&&x>0){
		swap(heap[x],heap[x/2]);
		x/=2;
	}
}
void down_fix(int x){
	if(x*2>top) return ;
	bool f1=heap[x].p>heap[x*2+1].p||(heap[x].p==heap[x*2+1].p&&heap[x].type>heap[x*2+1].type);
	bool f2=heap[x].p>heap[x*2].p||(heap[x].p==heap[x*2].p&&heap[x].type>heap[x*2].type);
	if(x*2+1>top) f1=false;
	int w;
	while(x<=top&&(f1||f2)){
		if(f1&&f2)
			w=heap[x*2].p<heap[x*2+1].p||(heap[x*2].p==heap[x*2+1].p&&heap[x*2].type<heap[x*2+1].type)?x*2:x*2+1;
		else{
			if(f1) w=x*2+1;
			else w=x*2;
		}
		swap(heap[x],heap[w]);
		x=w;
		if(x*2>top) return;
		f1=heap[x].p>heap[x*2+1].p||(heap[x].p==heap[x*2+1].p&&heap[x].type>heap[x*2+1].type);
		if(x*2+1>top) f1=false;
		else f2=heap[x].p>heap[x*2].p||(heap[x].p==heap[x*2].p&&heap[x].type>heap[x*2].type);
	}
}
void insert(node x){
	top++;heap[top]=x;
	up_fix(top);
}
inline node _top(){
	return heap[1];
}
node pop(){
	node tmp=heap[1];
	swap(heap[1],heap[top]);
	top--;
	down_fix(1);
	return tmp;
}
long long ans=0;
bool check(){
	if(m>=_top().p) return true;
	if(_top().type==0){
		tmp=pop();
		int w=tmp.num;
		tmp.type=1;tmp.p=2*(p[w].type?p[w].y:p[w].x);
		insert(tmp);
		return check();
	}
	if(_top().type==1){
		if(m>=_top().p/2) return true;
	}
	return false;
}
void check_err(){
	for(int i=1;i<=top;i++) printf("%d(%d,%d) ",heap[i].p,heap[i].num,heap[i].type);
	printf("  %lld %lld\n\n\n\n\n",m,ans);
}
bool cmp(price a,price b){return a.x<b.x;}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld %lld\n",&p[i].x,&p[i].y);
	for(int i=1;i<=n;i++){
		tmp.num=i;
		if(p[i].x+p[i].y<2*p[i].x) tmp.p=p[i].x+p[i].y,p[i].type=tmp.type=0;
		else tmp.p=p[i].x*2,p[i].type=0,tmp.type=1;
		insert(tmp);
	}
	int w;
	while(check()){
		w=_top().num;
		ans+=_top().type?1:2;
		m-=(_top().type?_top().p/2:_top().p);
		tmp.num=w;
		if(_top().type==0) continue;
		if(p[w].type==0){p[w].type=1;tmp.p=p[w].y*2;}
		else if(p[w].type==1){p[w].type=0;tmp.p=p[w].x*2;}
		tmp.type=1;
		if(p[w].x+p[w].y<=tmp.p*2){
			tmp.p=p[w].x+p[w].y;
			tmp.type=0;p[w].type=p[w].type?0:1;
		}
		pop();
		insert(tmp);
	}
	printf("%lld",ans);
	return 0;
}
