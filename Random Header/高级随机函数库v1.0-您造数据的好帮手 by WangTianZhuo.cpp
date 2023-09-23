#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int u,v;
}edge[1010];
namespace Rand{
	//randInt���ֵ��Χ: 0~2^31-1
	int randInt(){
		return (int)(rand()%32768)*65536+(rand()%65536);
	}
	//randUnInt���ֵ��Χ: 0~2^32-1
	unsigned int randUnInt(){
		return (unsigned int)(rand()%65536)*65536+(rand()%65536);
	}
	//randLong���ֵ��Χ: 0~2^63-1
	long long randLong(){
		return (long long)(randUnInt()%2147483648)*4294967296+(randUnInt()%4294967296);
	}
	//randUnLong���ֵ��Χ: 0~2^64-1
	unsigned long long randUnLong(){
		return (unsigned long long)(randUnInt()%4294967296)*4294967296+(randUnInt()%4294967296);
	}
	//randString����ַ���: len����ַ������� Upper:�Ƿ������д��ĸ Lower:�Ƿ�����Сд��ĸ Digit:�Ƿ��������� Other:�Ƿ����������ɼ��ַ������ո��⣩ Space:�Ƿ�����ո� res:����ַ������ 
	/*
	ʹ��ʾ����
	char str[110];
	randString(10,1,1,1,0,0,str); ����һ�����д�д��ĸ��Сд��ĸ�����ֵ��ַ�����������str�У�ע����������ַ�����0Ϊ���λ�� 
	
	char str2[1010];
	randString(2000,1,1,1,1,1,str2); ����һ�����Ժ�������ɼ��ַ����ַ�����ע�������������Ϊstr2���ȹ�С�����������str2�ĳ���Ӧ��С��len�� 
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
	//randTree�����: n:���Ľڵ���� Root1:�Ƿ���Ҫ��֤������Ĳ������Ϊ1,2,3,...,n Change_Fa_Chi:�Ƿ�����������ĸ��׽ڵ�ͺ��ӽڵ� edge[]:������������  
	//edge[] ����������Ӧ��ΪEdge, Edge��һ���ṹ�壬ÿһ��Edge�ͱ���������������u��v����ʾ��u��v��һ������ߣ�������Change_Fa_ChiΪtrueʱ��ʾ��u��v��һ��˫���
	/*
	ʹ��ʾ����
	Edge a[110];
	randTree(100,0,0,a); ����һ���ڵ���������ң��ҽ���е�uΪ���׽ڵ㣬vΪ���ӽڵ������ע��ߵı���ʱ��1��ʼ����ġ�
	
	Edge b[1000];
	randTree(1000,1,1,b); ����һ���ڵ��ű�֤���򣬵�����е�u��һ���Ǹ��׽ڵ㣬v��һ���Ǻ��ӽڵ������ע�����������Windows���п��ܣ�Linux��һ��������Ϊb���ȹ�С�����������b�ĳ��Ȳ�ӦС��n+1��ע����n+1������ 
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
	//randGraph���ͼ n:ͼ�Ľڵ���� m:ͼ�ı����� Lian:�Ƿ�֤�κε�ֱ�Ӷ�����ͨ�� Repeat:�Ƿ������ر� Directed:�Ƿ�Ϊ����� edge[]:�������ͼ���
	//edge[] ����������Ӧ��ΪEdge, Edge��һ���ṹ�壬ÿһ��Edge�ͱ���������������u��v��������DirectedΪfalseʱ��ʾ��u��v��һ��˫��ߣ������ʾ��u��v��һ������� 
	/*
	������δ��������Ȼ����BUG�������޷��ṩʹ��ʾ�� 
	*/ 
	//Warning: ��ǰrandGraph���ܽ������ã����ܺ��д���BUG�������ʹ�� 
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
using namespace Rand; //��ؼ����������룬������ֻ��ͨ��Rand::������()����������� 
int main(){
	srand((unsigned)time(NULL)); //����ڼ�����������ʹ��Rand��������⣬�����޷����������������
	//��������������Ĵ��� 
	
	// 
	return 0;
}
