#ifndef _INC_HS_BIGNUM
#define _INC_HS_BIGNUM
/*
 * High accuracy class named "bigNum".
 * Defined class in namespace "hs".
 * Code by Hardsoft Corp. (Cyril Zhang)
 * Built on 18th Feb. 2022.
 * Powered by Microsoft Visual Stutio Code.
 * Formatted by Clang-Style Formatter.
 */
#include <iostream>
#include <vector>
#include <string>
class bigNum
{
	/*
	 * High accuracy class:
	 * (only support integer)
	 * push(=): (bigNum)=(char*) ,
				(bigNum)=(long long)
	 * add(+,+=): (bigNum)/(long long)/(char[])	+	(bigNum)/(long long)/(char[]) ,
				  (bigNum)						+=	(bigNum)/(long long)/(char[])
	 * sub(-,-=): (bigNum)(long long)/(char[])	-	(bigNum)/(long long)/(char[]) ,
				  (bigNum)						-=	(bigNum)/(long long)/(char[])
	 * mul(*,*=): (bigNum)/(long long)/(char[])	*	(bigNum)/(long long)/(char[]) ,
				  (bigNum)						*=	(bigNum)/(long long)/(char[])
	 * div(/,/=): (bigNum)/(long long)/(char[])	/	(bigNum)/(long long)/(char[]) ,
				  (bigNum)						/=	(bigNum)/(long long)/(char[])
	 * mod(%,%=): (bigNum)/(long long)/(char[])	%	(bigNum)/(long long)/(char[]) ,
				  (bigNum)						%=	(bigNum)/(long long)/(char[])
	 * bool operator: ==,!=,<,<=,>,>=
	 * input system: std::cin >> (bigNum);
	 * output system: std::cout << (bigNum);
	 * getStr function: (bigNum).opStr();
	 */

private:
	std::vector<short> num;
	std::string str;
	short sign;

	inline bool okstr(const std::string &s) const
	{
		int i = 0;
		if (*s.cbegin() == '-')
			i++;
		if (i == s.size())
			return 0;
		for (; i < s.size(); i++)
			if (s[i] < '0' || s[i] > '9')
				return 0;
		return 1;
	}

	inline int numLen(int n) const
	{
		int len = 1;
		while (n /= 10)
			len++;
		return len;
	}

	inline void numToStr()
	{
		int tp = *num.crbegin();
		str.clear();
		if (sign == -1)
			str += '-';
		char buf[1 << 3] = {0};
		for (int i = numLen(tp) - 1; i >= 0; i--)
			buf[i] = tp % 10 + '0', tp /= 10;
		str += buf;
		for (auto j = num.crbegin() + 1; j != num.crend(); ++j)
		{
			tp = *j;
			for (int i = 3; i >= 0; i--)
				buf[i] = tp % 10 + '0', tp /= 10;
			str += buf;
		}
	}

	bigNum hadd(const bigNum &a, const bigNum &b) const
	{
		bigNum ret(std::max(a.num.size(), b.num.size()));
		short t = 0;
		for (int i = 0; i < ret.num.size(); i++)
		{
			// ret.num[i]=(a.num[i])+(b.num[i]);
			if (i < a.num.size())
				t += a.num[i];
			if (i < b.num.size())
				t += (b.num[i]);
			ret.num[i] = t % 10000, t /= 10000;
		}
		if (t > 0)
			ret.num.push_back(t);
		return ret;
	}

	bigNum hsub(const bigNum &a, const bigNum &b) const
	{
		bigNum ret;
		ret.num.resize(std::max(a.num.size(), b.num.size()) + 1);
		for (int i = 0; i < ret.num.size(); i++)
		{
			ret.num[i] = a.num[i] - b.num[i];
			if (ret.num[i] < 0)
				ret.num[i] += 10000,
					ret.num[i + 1]--;
		}
		while (!num.empty() && !*num.crbegin())
			ret.num.pop_back();
		return ret;
	}

	bigNum hmul(const bigNum &x, const bigNum &y) const
	{
		bigNum ret;
		ret.num.resize(x.num.size(), y.num.size());
		for (int i = 0; i < x.num.size(); i++)
			for (int j = 0; j < y.num.size(); j++)
			{
				int tmp = x.num[i] * y.num[j];
				int k = i + j - 1;
				ret.num[k] += tmp % 10000;
				tmp /= 10000;
				tmp += ret.num[k] / 10000;
				ret.num[k] %= 10000;
				while ((ret.num[++k] += tmp) >= 10000)
				{
					ret.num[k + 1] += ret.num[k] / 10000;
					ret.num[k] %= 10000, tmp /= 10000;
				}
			}
		while (!num.empty() && !*num.crbegin())
			ret.num.pop_back();
		return ret;
	}

public:
	/* The old input system
	void input() {
		char buf[1 << 16] = { 0 };
		scanf("%s", buf);
		*this = buf;
	} */

	/* The old print system
	void print(const char *end){
		if(len<1){printf("ERR\n"); return;}
		if(sign==-1) printf("-");
		printf("%hd",num[len]);
		for(int i=len-1;i>0;i--)
			printf("%04hd",num[i]);
		printf("%s",end);
	} */

	inline bigNum(std::string s)
	{
		if (!okstr(s))
			std::__throw_invalid_argument("Bad string format.");
		num.clear();
		if (*s.cbegin() == '-')
			sign = -1, s.erase(s.begin());
		else
			sign = 1;
		int l = s.length();
		num.resize((l + 3) / 4);
		for (int i = 0, k = l - 1; i < num.size(); i++)
		{
			short tn = 0, t = 1;
			for (int j = 0; j < 4 && k >= 0; j++, k--, t *= 10)
				tn += (s[k] - '0') * t;
			num[i] = tn;
		}
		while (!num.empty() && !*num.crbegin())
			num.pop_back();
		numToStr();
	}

	inline bigNum(long long n)
	{
		char buf[15] = {0};
		int p = 0, i;
		long long j;
		if (n < 0)
			n = -n, buf[p++] = '-';
		for (i = p, j = n; j > 0; j /= 10, i++)
			buf[i] = j % 10 + '0';
		for (i--; p < i; p++, i--)
			buf[i] ^= buf[p] ^= buf[i] ^= buf[p];
		*this = bigNum(buf);
	}

	inline bigNum() : sign(1), num({0}), str("0") {}

	inline bigNum &operator=(const long long &n) { return *this = bigNum(n); }

	inline bigNum &operator=(const std::string &s) { return *this = bigNum(s); }

	friend std::istream &operator>>(std::istream &, bigNum &);

	friend std::ostream &operator<<(std::ostream &, bigNum &);

	inline bool operator==(const bigNum &n) const
	{
		return num == n.num;
	}

	inline bool operator<(const bigNum &n) const
	{
		if (sign == -1 && n.sign == 1)
			return 1;
		if (sign == 1 && n.sign == -1)
			return 0;
		bool f = 1;
		if (sign == -1 && n.sign == -1)
			f = 0;
		if (num.size() < n.num.size())
			return f;
		if (num.size() > n.num.size())
			return !f;
		if (num < n.num)
			return f;
		else
			return !f;
	}

	inline bool operator!=(const bigNum &n) const { return !(*this == n); }

	inline bool operator>=(const bigNum &n) const { return !(*this < n); }

	inline bool operator>(const bigNum &n) const { return !(*this < n) && *this != n; }

	inline bool operator<=(const bigNum &n) const { return !(*this > n); }

	inline bigNum operator-() const
	{
		bigNum ret(*this);
		ret.sign *= -1;
		return ret;
	}

	inline bigNum abs() const
	{
		bigNum ret(*this);
		ret.sign = 1;
		return ret;
	}

	inline bigNum operator+(const bigNum &n) const
	{
		bigNum ret;
		if (sign == n.sign)
		{
			ret = hadd(*this, n);
			ret.sign = sign;
		}
		else
		{
			if (abs() > n.abs())
			{
				ret = hmul(*this, n);
				ret.sign = sign;
			}
			else
			{
				ret = hmul(n, *this);
				ret.sign = n.sign;
			}
		}
		ret.numToStr();
		return ret;
	}

	inline bigNum &operator+=(const bigNum &n) { return (*this = *this + n); }

	inline bigNum operator-(const bigNum &n) const { return *this + (-n); }

	inline bigNum &operator-=(const bigNum &n) { return (*this = *this - n); }

	inline bigNum operator*(const bigNum &n) const
	{
		bigNum ret;
		ret = hmul(*this, n);
		ret.sign = sign * n.sign;
		ret.numToStr();
		return ret;
	}

	inline bigNum &operator*=(const bigNum &n) { return (*this = *this * n); }

	// inline bigNum operator%=(const bigNum n) { return (*this = *this % n); }

	// inline bigNum &operator/=(const bigNum &n) { return (*this = *this / n); }

	/* inline bigNum operator^(bigNum n) const
	{
		bigNum ans(1), base = *this;
		while (n > (bigNum)(1))
		{
			if (n % 2 == 1)
				ans *= base;
			base *= base;
			n /= (bigNum)2;
		}
		return ans;
	}

	inline bigNum operator^=(bigNum &n) { return (*this = *this ^ n); } */

	inline bigNum &operator++() { return *this += 1; }

	inline bigNum operator++(int)
	{
		bigNum tp = *this;
		*this += 1;
		return tp;
	}

	inline bigNum &operator--() { return *this -= 1; }

	inline bigNum operator--(int)
	{
		bigNum tp = *this;
		*this -= 1;
		return tp;
	}

	inline operator std::string() { return str; }

#ifdef _HS_BIGNUM_TEST
	inline const char *opStr()
	{
		return str.c_str();
	}
#endif
};

inline bigNum abs(const bigNum &n) { return n.abs(); }

std::istream &operator>>(std::istream &is, bigNum &n)
{
	char buf[1 << 16] = {0};
	is >> buf;
	n = buf;
	return is;
}

std::ostream &operator<<(std::ostream &os, bigNum &n)
{
	os << n.str;
	return os;
}
#endif // !defined(_INC_HS_BIGNUM)