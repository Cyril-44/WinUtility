/*个人认为这是一道贪心
* Xi第一次购买价格 Yi第二次购买价格  Si=Xi+Yi
* 首先对于每个糖果两次购买价格的和进行排序
* 找到和最小的糖果为第a颗
* 然后将这颗取出来，对每颗糖果的XiYi进行排序
* 从小到大累加之后反复买第a颗糖果
* （累加条件：
* 先x后y循环加
* 以下以x为例(y同理）
* 若lst + Xi >= Xa || Xi > Ya,则结束累加，开始进一步讨论
* 否则购买第i个糖果
* wc我真的不想nmd讨论了
* 还是跑两遍取最大吧(add:做完了,7个点都能过
* 写完这道题已经11点25了wc
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100005
int x[N],y[N];
int srtx[N],srty[N],srts[N];//间接排序后的序号先后
bool cmpx(const int a,const int b){
	if(x[a]==x[b]) return (y[a]<=y[b]);
	else return (x[a]<x[b]);
}
bool cmpy(const int a,const int b){
	if(y[a]==y[b]) return (x[a]<=x[b]);
	else return (y[a]<y[b]);
}
bool cmps(const int a,const int b){
	if(x[a]+y[a]==x[b]+y[b]){ 
		if(x[a]==x[b]) return y[a]<=y[b];
		else return x[a]<x[b];
	}else return x[a]+y[a]<x[b]+y[b];
}
long long n,m0,m,sumx=0,sumy=0,final_ans=0,ans=0;
long long fun(long long m,long long i){//第i个是S最小的
	long long sum=x[i]+y[i];
	long long pls=m/sum;
	pls*=2;
	m%=sum;
	if(m>=x[i]) pls++;
	return pls;
}//Si最便宜糖果反复加
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m0;
	m=m0;
	for(int i=0;i<n;i++){
		int xi,yi;
		cin>>xi>>yi;
		x[i]=xi;y[i]=yi;srtx[i]=i;srty[i]=i;srts[i]=i;
		sumx+=xi;sumy+=yi;
	}
	sort(srtx,srtx+n,cmpx);
	sort(srty,srty+n,cmpy);
	sort(srts,srts+n,cmps);
	int lst=0,minx=x[srts[0]],miny=y[srts[0]];//和最小糖果的x，y
	bool brk=true;
	if(m>sumx+sumy){
		long long mm=m-sumx-sumy;
		long long plss=2*n*(mm/(sumx+sumy));
		ans+=plss;
		m%=(sumx+sumy);
		m+=(sumx+sumy);
		lst=y[srty[n-1]];
	}else lst=0;
	for(int k=0;(k<n-1)&&brk;k++){	//run
		int i=srtx[k],xi=x[i];
		if(m<xi){
			brk=false;
			int plss=fun(m,srts[0]);
			ans+=plss;
			break;
		}
		if(xi>=(minx-lst) || xi>miny){//两种可能
			int plss=fun(m,srts[0]);//1.不取xi
			final_ans=max(final_ans,ans+plss);
		}
		m-=xi;//2.取xi
		ans++;
		lst=xi;
	}
	lst=x[srtx[n-1]];
	for(int k=0;(k<n-1)&&brk;k++){
		int i=srty[k],yi=y[i];
		if(m<yi){
			brk=false;
			int plss=fun(m,srts[0]);
			ans+=plss;
			break;
		}
		if(yi>=(miny-lst) || yi>miny){//两种可能
			int plss=fun(m,srts[0]);//1.不取yi
			final_ans=max(final_ans,ans+plss);
		}
		m-=yi;//2.取yi
		ans++;
		lst=yi;
	}
	final_ans=max(final_ans,ans);
	cout<<final_ans;
	return 0;
}//完结洒花qwq
