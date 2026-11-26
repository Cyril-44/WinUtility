#include<bits/stdc++.h>
#define int long long
#define inf 1145141919810
using namespace std;
const int N=1e5+5;
int m,n,ans;
struct node{
	int x,y,size;
}a[N];
int t[N];
bool A=true,B=true;
int read();
void write(int x);
int prize(int type,int num);
int rp();
int number(int num);
bool check(int cost);
void dfs(int num,int sum,int cost);
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++){
		a[i].x=read();
		a[i].y=read();
		if(a[i].x!=a[i].y)A=false;
		if(a[i].x<a[i].y)B=false;
	}
	if(A){
		for(int i=1;i<=n;i++){
			ans=max(ans,m/a[i].x);
		}
		write(ans);
		return 0;
	}
	if(B){
		double yz=1145141919810;
		for(int i=1;i<=n;i++)yz=min(yz,(a[i].x+a[i].y)/2.00);
		write((int)(m*1.00/yz));
		return 0;
	}
	dfs(1,0,0);
	write(ans);
	return 0;
}
int read(){
    int w=1,x=0;char c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar_unlocked();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar_unlocked();}
    return x*w;
}
void write(int x){
    if(x<0){putchar_unlocked('-');x=-x;}char c[1145];int len=0;while(x){c[++len]=(x%10)+'0';x/=10;}
    for(int i=len;i>=1;i--){putchar_unlocked(c[i]);}
}
int prize(int type,int num){
	if(num%2==0)return (a[type].x+a[type].y)*(num/2);
	return (a[type].x+a[type].y)*((num-1)/2)+a[type].x;
}
int rp(){
	int sum=0;
	for(int i=1;i<=n;i++)sum+=prize(i,t[i]);
	return sum;
}
int number(int num){return (m-rp())/((a[num].x+a[num].y)/2.00);}
bool check(int cost){
	for(int i=1;i<=n;i++){int p=(t[i]%2==0)?a[i].y:a[i].x;if(p+cost<=m)return true;}
	return false;
}
void dfs(int num,int sum,int cost){
	if(num>n||!check(cost)){ans=max(ans,sum);return;}
	for(int i=number(num);i>=0;i--){
		t[num]+=i;
		if(rp()<=m)dfs(num+1,sum+i,cost+prize(num,i));
		t[num]-=i;
	}
}
