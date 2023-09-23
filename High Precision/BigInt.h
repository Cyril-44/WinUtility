//main codes====================\/
#ifndef BIGINT
#define BIGINT
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
template<class T_queue>
struct Node_queue_for_bigint
{
	T_queue num;
	Node_queue_for_bigint *next;
	Node_queue_for_bigint()
	{
		next=0;
	}
};
template<class a_queue>
struct queue_for_bigint
{
	Node_queue_for_bigint<a_queue> *head,*tail,*L;
	bool isn;
	int SIZE_queue;
	void beginning()
	{
		head=tail=L=0;
		isn=0;
		head=tail=new Node_queue_for_bigint<a_queue>;
		tail->next=head;
		SIZE_queue=0;
		isn=1;
	}
	queue_for_bigint()
	{
		beginning();
	}
	~queue_for_bigint()
	{
		Node_queue_for_bigint<a_queue> *p=head,*tp;
		p=p->next;
		while(p!=head)
		{
			tp=p->next;
			delete p;
			p=tp;
		}
	}
	bool push(a_queue s)
	{
		SIZE_queue++;
		tail->num=s;
		if(tail->next==head)
		{
			tail->next=new Node_queue_for_bigint<a_queue>;
			tail->next->next=head;
			L=tail;
			tail=tail->next;
			return 1;
		}
		L=tail;
		tail=tail->next;
		return 0;
	}
	bool pop()
	{
		if(head==tail) return 1;
		head=head->next;
		SIZE_queue--;
		return 0;
	} 
	a_queue& front()
	{
		return head->num;
	} 
	a_queue& back()
	{
		return L->num;
	}
	int size()
	{
		return SIZE_queue;
	}
	void clear()
	{
		SIZE_queue=0;
		tail=head;
	}
	bool operator=(queue_for_bigint<a_queue>b)
	{
		if(!isn)
		{
			this->beginning();
			isn=1;
		}
		this->clear();
		Node_queue_for_bigint<a_queue> *p=b.head;
		while(p!=b.tail)
		{
			this->push(p->num);
			p=p->next;
		}
	}
};
int CacheSize=10;//try to use the cache
queue_for_bigint<char*> Mems;
queue_for_bigint<int> q;
queue_for_bigint<char> cache;
struct BigInt
{
	char f:4,nAn:4;
	std::vector<int> num;
	static const int base=100000000;
	BigInt()
	{
		f=0;
		nAn=0;
		num.push_back(0);
	}
	void format()
	{
		while(num.size()>1&&num[num.size()-1]==0) num.erase(num.end()-1);
		if(num.size()==1&&num[0]==0) f=0;
		if(num.size()==0) num.push_back(0),f=nAn=0;
	}
	//Input and Output
	char* c_str()
	{
		char *p;
		if(!nAn)
		{
			p=new char[num.size()*8+16];
			memset(p,0,sizeof(p));
			if(f) sprintf(p,"-");
			sprintf(p,"%s%d",p,num[num.size()-1]);
			for(int i=num.size()-2;i>=0;i--) sprintf(p,"%s%08d",p,num[i]);
		}
		else
		{
			p=new char[5];
			sprintf(p,"nan");
		}
		Mems.push(p);
		return p;
	}
	std::string str()
	{
		std::string ss=c_str();
		return ss;
	}
	BigInt operator=(char* s)
	{
		f=0;
		if(s==0) return BigInt();
		if(*s=='-')
		{
			f=1;
			s++;
		}
		int len=strlen(s),add=0,i,t;
		num.resize(len/8+1);
		char *p=s+len-1;
		while(p>=s)
		{
			t=0;
			for(i=-7;i<=0;i++)
				if(p+i>=s) t=t*10+*(p+i)-'0';
			p-=8;
			num[add++]=t;
		}
		while(num.size()>add) num.erase(num.end()-1);
		return *this;
	}
	BigInt operator=(std::string ss)
	{
		char *s=&ss[0];
		f=0;
		if(s==0) return BigInt();
		if(*s=='-')
		{
			f=1;
			s++;
		}
		int len=strlen(s),add=0,i,t;
		num.resize(len/8+1);
		char *p=s+len-1;
		while(p>=s)
		{
			t=0;
			for(i=-7;i<=0;i++)
				if(p+i>=s) t=t*10+*(p+i)-'0';
			p-=8;
			num[add++]=t;
		}
		while(num.size()>add) num.erase(num.end()-1);
		return *this;
	}
	BigInt operator=(int v)
	{
		f=0;
		if(v<0)
		{
			f=1;
			v=-v;
		}
		q.clear();
		if(v==0) q.push(0);
		else
			while(v>0)
			{
				q.push(v%base);
				v/=base;
			}
		num.resize(q.size());
		for(int i=0;q.size()>0;i++)
		{
			num[i]=q.front();
			q.pop();
		}
		return *this;
	}
	BigInt operator=(unsigned int v)
	{
		f=0;
		q.clear();
		if(v==0) q.push(0);
		else
			while(v>0)
			{
				q.push(v%base);
				v/=base;
			}
		num.resize(q.size());
		for(int i=0;q.size()>0;i++)
		{
			num[i]=q.front();
			q.pop();
		}
		return *this;
	}
	BigInt operator=(long long v)
	{
		f=0;
		if(v<0)
		{
			f=1;
			v=-v;
		}
		q.clear();
		if(v==0) q.push(0);
		else
			while(v>0)
			{
				q.push(v%base);
				v/=base;
			}
		num.resize(q.size());
		for(int i=0;q.size()>0;i++)
		{
			num[i]=q.front();
			q.pop();
		}
		return *this;
	}
	BigInt operator=(unsigned long long v)
	{
		f=0;
		q.clear();
		if(v==0) q.push(0);
		else
			while(v>0)
			{
				q.push(v%base);
				v/=base;
			}
		num.resize(q.size());
		for(int i=0;q.size()>0;i++)
		{
			num[i]=q.front();
			q.pop();
		}
		return *this;
	}
	//====================/
	//compare operations
	bool operator<(BigInt &b)
	{
		format();
		b.format();
		if(f!=b.f) return f>b.f;
		if(f==0)
		{
			for(int i=num.size()-1;i>=0;i--)
				if(num[i]<b.num[i]) return 1;
				else if(num[i]>b.num[i]) return 0;
		}
		else
		{
			for(int i=num.size()-1;i>=0;i--)
				if(num[i]>b.num[i]) return 1;
				else if(num[i]<b.num[i]) return 0;
		}
		return 0;
	}
	bool operator==(BigInt &b)
	{
		format();
		b.format();
		if(f!=b.f) return 0;
		if(num.size()!=b.num.size()) return 0;
		for(int i=num.size()-1;i>=0;i--)
			if(num[i]!=b.num[i]) return 0;
		return 1;
	}
	bool operator>(BigInt &b)
	{
		format();
		b.format();
		if(f!=b.f) return f<b.f;
		if(f==0)
		{
			for(int i=num.size()-1;i>=0;i--)
				if(num[i]>b.num[i]) return 1;
				else if(num[i]<b.num[i]) return 0;
		}
		else
		{
			for(int i=num.size()-1;i>=0;i--)
				if(num[i]<b.num[i]) return 1;
				else if(num[i]>b.num[i]) return 0;
		}
		return 0;
	}
	bool operator<=(BigInt &b){return (*this<b||*this==b);}
	bool operator>=(BigInt &b){return (*this>b||*this==b);}
	//=================/
	//maths operations
	BigInt operator+(BigInt& b)
	{
		format();
		b.format();
		BigInt c;
		c.nAn=(nAn==1||b.nAn==1);
		if(c.nAn) return c;
		if(f)
		{
			if(b.f)
			{
				BigInt A=*this,B=b;
				A.f=B.f=0;
				c=A+B;
				c.f=1;
				return c;
			}
			else
			{
				BigInt A=*this;
				A.f=0;
				c=b-A;
				return c;
			}
		}
		else if(b.f)
		{
			BigInt B=b;
			B.f=0;
			c=*this-B;
			return c;
		}
		int t=0,t2=std::max(num.size(),b.num.size())+1;
		c.num.resize(t2);
		memset(&c.num[0],0,t2*4);
		for(int i=0;i<t2;i++)
		{
			if(i<num.size()) t+=num[i];
			if(i<b.num.size()) t+=b.num[i];
			c.num[i]=t%base;
			t/=base;
		}
		c.format();
		return c;
	}
	BigInt operator-(BigInt& b)
	{
		format();
		b.format();
		BigInt c;
		c.nAn=(nAn==1||b.nAn==1);
		if(c.nAn) return c;
		if(*this==b) return BigInt();
		if(f)
		{
			if(b.f)
			{
				BigInt A=*this,B=b;
				A.f=B.f=0;
				c=B-A;
				return c;
			}
			else
			{
				BigInt A=*this,B=b;
				A.f=B.f=0;
				c=A+B;
				c.f=1;
				return c;
			}
		}
		else if(b.f)
		{
			BigInt B=b;
			B.f=0;
			c=*this+B;
			return c;
		}
		if(*this<b)
		{
			c=b-*this;
			c.f=1;
			return c;
		}
		c=*this;
		int z=0,k;
		for(int i=0;i<num.size();i++)
		{
			c.num[i]=c.num[i]-z-b.num[i];
			if(c.num[i]<0)
			{
				c.num[i]+=base;
				z=1;
			}
			else z=0;
			k=i+1;
			while(z)
			{
				c.num[k]--;
				if(c.num[k]<0)
				{
					z=1;
					c.num[k]+=base;
				}
				else z=0;
				k++;
			}
		}
		c.format();
		return c;
	}
	BigInt operator*(BigInt& b)
	{
		format();
		b.format();
		BigInt c;
		c.nAn=(nAn==1||b.nAn==1);
		if(c.nAn) return c;
		c.num.resize(num.size()+b.num.size());
		memset(&c.num[0],0,(num.size()+b.num.size())*4);
		int i,j,k,I,J;
		long long t;
		for(i=0;i*CacheSize<num.size();i++)
			for(j=0;j*CacheSize<b.num.size();j++)
				for(I=i*CacheSize;I<(i+1)*CacheSize&&I<num.size();I++)
					for(J=j*CacheSize;J<(j+1)*CacheSize&&J<b.num.size();J++)
					{
						t=(long long)num[I]*b.num[J];
						t+=c.num[I+J];
						c.num[I+J]=t%base;
						k=I+J+1;
						t/=base;
						while(t>0)
						{
							t+=c.num[k];
							c.num[k++]=t%base;
							t/=base;
						}
					}
		c.f=(f!=b.f);
		c.format();
		return c;
	}
	BigInt operator/(int b)
	{
		BigInt c=*this;
		format();
		if(!b||nAn)
		{
			c.nAn=1;
			return c;
		}
		if(abs(b)>=base)
		{
			BigInt B;
			B=b;
			return *this/B;
		}
		c.f=(c.f!=(b<0));
		b=abs(b);
		int t=0;
		for(int i=c.num.size()-1;i>=0;i--)
		{
			t=t*base+c.num[i];
			c.num[i]=t/b;
			t=t%b;
		}
		c.format();
		return c;
	}
	BigInt operator/(unsigned int b)
	{
		BigInt c=*this;
		format();
		if(!b||nAn)
		{
			c.nAn=1;
			return c;
		}
		if(abs(b)>=base)
		{
			BigInt B;
			B=b;
			return *this/B;
		}
		c.f=(c.f!=(b<0));
		b=abs(b);
		unsigned int t=0;
		for(int i=c.num.size()-1;i>=0;i--)
		{
			t=t*base+c.num[i];
			c.num[i]=t/b;
			t=t%b;
		}
		c.format();
		return c;
	}
	BigInt operator/(long long b)
	{
		BigInt c=*this;
		format();
		if(!b||nAn)
		{
			c.nAn=1;
			return c;
		}
		if(abs(b)>=base)
		{
			BigInt B;
			B=b;
			return *this/B;
		}
		c.f=(c.f!=(b<0));
		b=abs(b);
		long long t=0;
		for(int i=c.num.size()-1;i>=0;i--)
		{
			t=t*base+c.num[i];
			c.num[i]=t/b;
			t=t%b;
		}
		c.format();
		return c;
	}
	BigInt operator/(unsigned long long b)
	{
		BigInt c=*this;
		format();
		if(!b||nAn)
		{
			c.nAn=1;
			return c;
		}
		if(abs(b)>=base)
		{
			BigInt B;
			B=b;
			return *this/B;
		}
		c.f=(c.f!=(b<0));
		b=abs(b);
		unsigned long long t=0;
		for(int i=c.num.size()-1;i>=0;i--)
		{
			t=t*base+c.num[i];
			c.num[i]=t/b;
			t=t%b;
		}
		c.format();
		return c;
	}
	BigInt operator/(BigInt& b)
	{
		format();
		b.format();
		if(*this<b) return BigInt();
		BigInt c;
		c.nAn=(nAn==1||b.nAn==1||(b.num.size()==1&&b.num[0]==0));
		if(c.nAn) return c;
		return c;
	}
	//=====================/
};
void free_pointers()
{
	while(Mems.size()>0)
	{
		delete[] Mems.front();
		Mems.pop();
	}
}
int read(BigInt &n,FILE *stream=stdin)
{
	cache.clear();
	char t;
	while(1)
	{
		fread(&t,1,1,stream);
		if(t=='-'||(t>='0'&&t<='9'))
		{
			ungetc(t,stream);
			break;
		}
	}
	bool flag=0;
	while(1)
	{
		fread(&t,1,1,stream);
		if(t!='-')
		{
			ungetc(t,stream);
			break;
		}
		flag=!flag;
	}
	if(flag) cache.push('-');
	while(1)
	{
		fread(&t,1,1,stream);
		if(t<'0'||t>'9')
		{
			ungetc(t,stream);
			break;
		}
		cache.push(t);
	}
	char *p=new char[cache.size()+1],*tp;
	tp=p;
	while(cache.size()>0) *tp++=cache.front(),cache.pop();
	n=p;
	delete[] p;
}
int write(BigInt &n,FILE *stream=stdout)
{
	n.format();
	if(n.nAn) fprintf(stream,"nan");
	else
	{
		if(n.f) fprintf(stream,"-");
		fprintf(stream,"%d",n.num[n.num.size()-1]);
		for(int i=n.num.size()-2;i>=0;i--)
			fprintf(stream,"%08d",n.num[i]);
	}
}
#endif

//stream input and output
#ifdef _GLIBCXX_OSTREAM
std::ostream& operator<<(std::ostream& str,BigInt&n)
{
	n.format();
	if(n.nAn) str<<"nan";
	else
	{
		if(n.f) str<<'-';
		str<<n.num[n.num.size()-1];
		str.fill('0');
		str.width(8);
		for(int i=n.num.size()-2;i>=0;i--)
			str<<n.num[i];
		str.fill(0);
		str.width(0);
	}
	return str;
}
#endif

#ifdef _GLIBCXX_ISTREAM
std::istream& operator>>(std::istream& str,BigInt &n)
{
	cache.clear();
	while(!str.eof()&&!(str.peek()=='-'||(str.peek()>='0'&&str.peek()<='9'))) str.get();
	bool flag=0;
	while(str.peek()=='-') flag=!flag,str.get();
	if(flag) cache.push('-');
	while(str.peek()>='0'&&str.peek()<='9') cache.push(str.get());
	char *p=new char[cache.size()+1],*t;
	t=p;
	while(cache.size()>0) *t++=cache.front(),cache.pop();
	n=p;
	delete[] p;
	return str;
}
#endif
//======================/
//=========================/\

