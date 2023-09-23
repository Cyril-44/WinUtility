#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v;
}edge[1010];
namespace Rand{
	//randInt随机值范围: 0~2^31-1
	int randInt(){
		return (int)(rand()%32768)*65536+(rand()%65536);
	}
	//randUnInt随机值范围: 0~2^32-1
	unsigned int randUnInt(){
		return (unsigned int)(rand()%65536)*65536+(rand()%65536);
	}
	//randLong随机值范围: 0~2^63-1
	long long randLong(){
		return (long long)(randUnInt()%2147483648)*4294967296+(randUnInt()%4294967296);
	}
	//randUnLong随机值范围: 0~2^64-1
	unsigned long long randUnLong(){
		return (unsigned long long)(randUnInt()%4294967296)*4294967296+(randUnInt()%4294967296);
	}
	//randString随机字符串: len随机字符串长度 Upper:是否允许大写字母 Lower:是否允许小写字母 Digit:是否允许数字 Other:是否允许其他可见字符（除空格外） Space:是否允许空格 res:随机字符串结果 
	/*
	使用示例：
	char str[110];
	randString(10,1,1,1,0,0,str); 生成一个含有大写字母，小写字母和数字的字符串并保存在str中，注意所有随机字符串以0为起点位置 
	
	char str2[1010];
	randString(2000,1,1,1,1,1,str2); 生成一个可以含有任意可见字符的字符串。注意这个操作会因为str2长度过小而导致溢出，str2的长度应不小于len。 
	*/ 
	void randString(int len,bool Upper,bool Lower,bool Digit,bool Other,bool Space,char res[]){
		memset(res,0,sizeof(res));
		if(!(Upper+Lower+Digit+Other+Space)) return;
		char c;
		for(int i=0;i<len;i++){
			c=rand()%96+32;
			if(isupper(c)&&!Upper) i--;
			else if(islower(c)&&!Lower) i--;
			else if(isdigit(c)&&!Digit) i--;
			else if(c==' '&&!Space) i--;
			else if(!Other) i--;
			else res[i]=c;
		}
	}
	//randTree随机树: n:树的节点个数 Root1:是否需要保证随机树的层序遍历为1,2,3,...,n Change_Fa_Chi:是否允许交换结果的父亲节点和孩子节点 edge[]:保存随机树结果  
	//edge[] 的数据类型应当为Edge, Edge是一个结构体，每一个Edge型变量含有两个参数u和v，表示从u到v的一条单向边，当参数Change_Fa_Chi为true时表示从u到v的一条双向边
	/*
	使用示例：
	Edge a[110];
	randTree(100,0,0,a); 生成一个节点编号随机打乱，且结果中的u为父亲节点，v为孩子节点的树。注意边的保存时从1开始保存的。
	
	Edge b[1000];
	randTree(1000,1,1,b); 生成一个节点编号保证有序，但结果中的u不一定是父亲节点，v不一定是孩子节点的树。注意这个操作（Windows下有可能，Linux下一定）会因为b长度过小而导致溢出，b的长度不应小于n+1，注意是n+1！！！ 
	*/  
	void randTree(int n,bool Root1,bool Change_Fa_Chi,Edge edge[]){
		int BeiFenN=n; 
		queue<pair<int,int>> qu;
		int k=1,b=0,f,t;
		qu.push(make_pair(1,n)); n--;
		while(!qu.empty()){
			t=qu.front().first;
			f=qu.front().second;
			qu.pop();
			f--;
			if(f==0) continue;
			int cha=min(randInt()%(int)log2(f+1)+1,n);
			if(cha==0) continue;
			for(int i=1;i<cha;i++){
				edge[++b].u=t;
				edge[b].v=++k;
				int di=randInt()%(f-(cha-i))+1;
				f-=di;
				qu.push(make_pair(k,di));
				n--;
			}
			edge[++b].u=t;
			edge[b].v=++k;
			qu.push(make_pair(k,f));
			n--;
		}
		if(!Root1){
			vector<int> v;
			for(int i=0;i<=BeiFenN;i++){
				v.push_back(i);
			}
			random_shuffle(v.begin()+1,v.end());
			for(int i=1;i<BeiFenN;i++){
				edge[i].u=v[edge[i].u];
				edge[i].v=v[edge[i].v];
			}
		}
		random_shuffle(edge+1,edge+BeiFenN);
		if(Change_Fa_Chi){
			for(int i=1;i<BeiFenN;i++){
				if(rand()%2) swap(edge[i].u,edge[i].v);
			}
		}
	}
	//randGraph随机图 n:图的节点个数 m:图的边条数 Lian:是否保证任何点直接都是联通的 Repeat:是否允许重边 Directed:是否为有向边 edge[]:保存随机图结果
	//edge[] 的数据类型应当为Edge, Edge是一个结构体，每一个Edge型变量含有两个参数u和v，当参数Directed为false时表示从u到v的一条双向边，否则表示从u到v的一条单向边 
	/*
	由于这段代码可能仍然含有BUG，我们无法提供使用示例 
	*/ 
	//Warning: 当前randGraph功能仅可试用，可能含有大量BUG，请谨慎使用 
	void randGraph(int n,int m,bool Lian,bool Repeat,bool Directed,Edge edge[]){
		map<pair<int,int>,int> mp;
		if(Repeat==false){
			if(Directed==0&&m>(n*(n-1)/2-1)/2){
				randGraph(n,n-m,Lian,Repeat,Directed,edge);
				for(int i=1;i<=n-m;i++) mp[make_pair(edge[i].u,edge[i].v)]=1;
				int tot=0;
				for(int i=1;i<=n;i++)
					for(int j=1;j<i;j++)
						if((mp.count(make_pair(i,j))||mp.count(make_pair(j,i)))==0) 
							if(rand()%2) edge[++tot].u=i,edge[++tot].v=j;
							else edge[++tot].u=j,edge[++tot].v=i;
				return;
			}
			else if(m>(n*(n-1)+1)/2){
				randGraph(n,n-m,Lian,Repeat,Directed,edge);
				for(int i=1;i<=n-m;i++) mp[make_pair(edge[i].u,edge[i].v)]=1;
				int tot=0;
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++)
						if(mp.count(make_pair(i,j))==0&&i!=j)
							if(rand()%2) edge[++tot].u=i,edge[++tot].v=j;
							else edge[++tot].u=j,edge[++tot].v=i;
				return;
			}
		}
		if(Lian){
			randTree(n,0,1,edge);
			for(int i=1;i<n;i++) mp[make_pair(edge[i].u,edge[i].v)]++;
			for(int i=1;i<m-n+1;i++){
				int u=rand()%n+1,v=rand()%n+1;
				while(v==u) v=rand()%n+1;
				if(Repeat==false&&(mp.count(make_pair(u,v))||(Directed==0&&mp.count(make_pair(v,u))))) i--; 
				else edge[n-1+i].u=u,edge[n-1+i].v=v,mp[make_pair(edge[i].u,edge[i].v)]=1;
			}
		}
		else{
			for(int i=1;i<=m;i++){
				int u=rand()%n+1,v=rand()%n+1; 
				while(v==u) v=rand()%n+1;
				if(Repeat==false&&(mp.count(make_pair(u,v))||(Directed==0&&mp.count(make_pair(v,u))))) i--; 
				else edge[i].u=u,edge[i].v=v,mp[make_pair(edge[i].u,edge[i].v)]++;
			}
		}
	} 
};
using namespace Rand; //务必加上这条代码，否则你只能通过Rand::函数名()调用随机函数 
int main(){
	srand((unsigned)time(NULL)); //务必在加上这条代码使用Rand随机函数库，否则将无法正常生成随机内容
	//请在这里输入你的代码 
	
	// 
	return 0;
}
