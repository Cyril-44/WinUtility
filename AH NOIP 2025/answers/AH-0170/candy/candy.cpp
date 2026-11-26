#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n; long long m;
int b[N];
struct node{
    int xi,yi;	
}a[N];
bool cmp(node x,node y){
	return x.xi<=y.xi;
}
bool pda(){
	for(int i=1;i<=n;i++){
		if(a[i].xi!=a[i].yi) return false;
	}
	return true;
}
bool pdb(){
    if(n==1) return true;
    else return false;	
}
bool pdc(){
    if(n==2) return true;
    else return false;
}
void fa(){
    sort(a+1,a+n+1,cmp);
    long long ans=m/a[1].xi;
    cout<<ans;
    return;
}
void fb(){
    long long ans=(m/(a[1].xi+a[1].yi))*2;
    m%=(a[1].xi+a[1].yi);
    if(m>=a[1].xi) cout<<ans+1;
    else cout<<ans;
    return;	
}
void fc(){
	int x=a[1].xi+a[1].yi;
	int y=a[2].xi+a[2].yi;
	if(x>y) swap(x,y);
	int ans=(m/x)*2;
	m%=x;
	if(a[1].xi>a[2].xi){
		if(m-a[2].xi>=0) ans++,m-=a[2].xi;
		if(m-a[1].xi>=0) ans++;
		cout<<ans;
	}
	else{
		if(m-a[1].xi>=0) ans++,m-=a[1].xi;
		if(m-a[2].xi>=0) ans++;
		cout<<ans;
	}
    return;	
}
void fd(){
	for(int i=1;i<=n;i++) b[i]=a[i].xi+a[i].yi;
	sort(b+1,b+n+1);
	int ans=(m/b[1])*2;
	m%=b[1];
	sort(a+1,a+n+1,cmp);
	if(a[1].xi<=m) cout<<ans+1;
	else cout<<ans;
    return;	
}
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].xi>>a[i].yi;
    if(pda()){
		fa();
		return 0;
	}
	if(pdb()){
	    fb();
	    return 0;	
	}
	if(pdc()){
		fc();
		return 0;
	}
	fd();
    return 0;
}
