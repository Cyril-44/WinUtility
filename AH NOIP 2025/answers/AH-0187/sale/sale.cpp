#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,sss,mm,s,ss,ans,sum,p;
struct node{
	long long a,c,x,id;
}y[100005];
bool cmp(node l,node r){
	if(l.x!=r.x)return l.x>r.x;
	else if(l.a!=r.a)return l.a>r.a;
	else return l.id<r.id;
}
bool cmp1(node l,node r){
	if(l.a!=r.a)return l.a>r.a;
	else if(l.c!=r.c)return l.c<r.c;
	else return l.id<r.id;
}
bool cmp2(node l,node r){
	return l.a>r.a;
}
int f1[2]={1,2};
int f2[4]={11,12,21,22};
int f3[8]={111,112,121,122,211,212,221,222};
int f4[16]={1111,1112,1121,1122,1211,1212,1221,1222,2111,2112,2121,2122,2211,2212,2221,2222};
int f5[32]{11111,11112,11121,11122,11211,11212,11221,11222,12111,12112,12121,12122,12211,12212,12221,12222,21111,21112,21121,21122,21211,21212,21221,21222,22111,22112,22121,22122,22211,22212,22221,22222};
void ss1(int n,int l,string s12,int ans1,int sum1){
	if(l==n){
		for(int j=1;j<=n;j++){
			y[j].c=s12[j]-'0';
		}
		sort(y+1,y+n+1,cmp);
		mm=m;
		ans1=0;sum1=0;
		for(int j=1;j<=n;j++){
			if(mm>=y[j].c){
				ans+=y[j].a;
				mm-=y[j].c;
			}
		}
		mm=m;
		sort(y+1,y+n+1,cmp1);
		for(int j=1;j<=n;j++){
			if(mm>=y[j].c){
				sum+=y[j].a;
				mm-=y[j].c;
			}
		}
		if(ans1>=sum)s++;
		return;
	}
	ss1(n,l+1,s12+"1",ans1,sum1);
	ss1(n,l+1,s12+"2",ans1,sum1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	p=998244353;
	while(t--){
		s=0;
		ss=1;	
		scanf("%lld%lld",&n,&m);
		scanf("%lld",&y[1].a);
		for(int i=2;i<=n;i++){
			scanf("%lld",&y[i].a);
			if(y[1].a==y[i].a)ss++;
		}
		if(ss==n){
			ss=1;
			for(int i=1;i<=n;i++){
				ss*=2;
				ss%=p;
			}
			printf("%lld\n",ss%p);
		}
		else if(n>5&&n<=10){
			ss1(n,0,"/",0,0);
			printf("%lld\n",s%p);
		}
		else if(n==5){
			for(int i=0;i<32;i++){
				y[1].c=f5[i]/10000%10;y[2].c=f5[i]/1000%10;y[3].c=f5[i]/100%10;y[4].c=f5[i]/10%10;y[5].c=f5[i]%10;
				y[1].x=y[1].a/y[1].c;y[2].x=y[2].a/y[2].c;y[3].x=y[3].a/y[3].c;y[4].x=y[4].a/y[4].c;y[5].x=y[5].a/y[5].c;
				y[1].id=1;y[2].id=2;y[3].id=3;y[4].id=4;y[5].id=5;
				sort(y+1,y+6,cmp);
				mm=m;
				ans=0;sum=0;
				for(int j=1;j<=n;j++){
					if(mm>=y[j].c){
						ans+=y[j].a;
						mm-=y[j].c;
					}
				}
				mm=m;
				sort(y+1,y+6,cmp1);
				for(int j=1;j<=n;j++){
					if(mm>=y[j].c){
						sum+=y[j].a;
						mm-=y[j].c;
					}
				}
				if(ans>=sum)s++;
			}
			printf("%lld\n",s%p);
		}
		else if(n==4){
			for(int i=0;i<16;i++){
				y[1].c=f4[i]/1000%10;y[2].c=f4[i]/100%10;y[3].c=f4[i]/10%10;y[4].c=f4[i]%10;
				y[1].x=y[1].a/y[1].c;y[2].x=y[2].a/y[2].c;y[3].x=y[3].a/y[3].c;y[4].x=y[4].a/y[4].c;
				y[1].id=1;y[2].id=2;y[3].id=3;y[4].id=4;
				sort(y+1,y+5,cmp);
				mm=m;
				ans=0;sum=0;
				for(int j=1;j<=n;j++){
					if(mm>=y[j].c){
						ans+=y[j].a;
						mm-=y[j].c;
					}
				}
				mm=m;
				sort(y+1,y+5,cmp1);
				for(int j=1;j<=n;j++){
					if(mm>=y[j].c){
						sum+=y[j].a;
						mm-=y[j].c;
					}
				}
				if(ans>=sum)s++;
			}
			printf("%lld\n",s%p);
		}
		else if(n==3){
			for(int i=0;i<8;i++){
				y[1].c=f3[i]/100%10;y[2].c=f3[i]/10%10;y[3].c=f3[i]%10;
				y[1].x=y[1].a/y[1].c;y[2].x=y[2].a/y[2].c;y[3].x=y[3].a/y[3].c;
				y[1].id=1;y[2].id=2;y[3].id=3;
				sort(y+1,y+4,cmp);
				mm=m;
				ans=0;sum=0;
				for(int j=1;j<=n;j++){
					if(mm>=y[j].c){
						ans+=y[j].a;
						mm-=y[j].c;
					}
				}
				mm=m;
				sort(y+1,y+4,cmp1);
				for(int j=1;j<=n;j++){
					if(mm>=y[j].c){
						sum+=y[j].a;
						mm-=y[j].c;
					}
				}
				if(ans>=sum)s++;
			}
			printf("%lld\n",s%p);
		}
		else if(n==2){
			for(int i=0;i<4;i++){
				y[1].c=f2[i]/100%10;y[2].c=f2[i]%10;
				y[1].x=y[1].a/y[1].c;y[2].x=y[2].a/y[2].c;
				y[1].id=1;y[2].id=2;
				sort(y+1,y+3,cmp);
				mm=m;
				ans=0;sum=0;
				for(int j=1;j<=n;j++){
					if(mm>=y[j].c){
						ans+=y[j].a;
						mm-=y[j].c;
					}
				}
				mm=m;
				sort(y+1,y+3,cmp1);
				for(int j=1;j<=n;j++){
					if(mm>=y[j].c){
						sum+=y[j].a;
						mm-=y[j].c;
					}
				}
				if(ans>=sum)s++;
			}
			printf("%lld\n",s%p);
		}
		else if(n==1){
			for(int i=0;i<2;i++){
				y[1].c=f1[i]%10;
				y[1].x=y[1].a/y[1].c;
				y[1].id=1;
				mm=m;
				ans=0;sum=0;
				for(int j=1;j<=n;j++){
					if(mm>=y[j].c){
						ans+=y[j].a;
						mm-=y[j].c;
					}
				}
				mm=m;
				for(int j=1;j<=n;j++){
					if(mm>=y[j].c){
						sum+=y[j].a;
						mm-=y[j].c;
					}
				}
				if(ans>=sum)s++;
			}
			printf("%lld\n",s%p);
		}
		else if(m==2){
			sort(y+1,y+n+1,cmp2);
			ss=1;
			for(int i=1;i<=n-3;i++){
				ss*=2;
				ss%=p;
			}
			printf("%lld\n",ss%p);
		}
	}
	return 0;
}
