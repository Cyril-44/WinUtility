#ifndef _INC_HS_BIGNUM
#define _INC_HS_BIGNUM
/*
 * High accuracy class named "bigNum".
 * Defined class in namespace "hs".
 * Code by Hardsoft Corp. (Cyril Zhang)
 * Built on 18th Feb. 2022.
 * Powered by Microsoft Visual Studio 2022,
 * 			& Microsoft Visual Stutio Code.
 * Formatted by Microsoft Visual C++ Clang-Style Formatter.
 */
#include <iostream>
namespace hs {
	class bigNum {
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

		short numArr[(1 << 14) + 1];
		char numStr[1 << 16];
		size_t len;

#ifndef _INC_STRING
		size_t strlen(const char* s) {
			int n = 0;
			for (n = 0; s[n]; n++);
			return n;
		}
		void memset(void* s, int n, size_t l) {
			for (char* p = (char*)s; l > 0; p++, l--) *p = n;
		}
#endif

		bool okNumStr(const char* s) const {
			if (*s == '\0') return 0;
			int i = 0; if (*s == '-') i++;
			for (; *(s + i) != '\0'; i++) if (*(s + i) < '0' || *(s + i) > '9') return 0;
			return 1;
		}

		size_t numLen(int n) const {
			size_t len = 1;
			while (n /= 10)
				len++;
			return len;
		}

		void swap(bigNum& a, bigNum& b) {
			bigNum tp;
			tp = a, a = b, b = tp;
		}

		size_t max(size_t x, size_t y) const {
			return (x > y ? x : y);
		}

		void numToStr(char* buf) const {
			int tp = this->numArr[this->len];
			size_t tl = numLen(tp);
			if (this->numArr[0] == -1)
				*buf++ = '-';
			for (int i = tl - 1, k = tl; k > 0; i--, k--)
				buf[i] = tp % 10 + '0', tp /= 10;
			for (int j = (this->len) - 1; j > 0; j--) {
				tp = this->numArr[j];
				for (int i = (tl += 4) - 1, k = 4; k > 0; i--, k--)
					buf[i] = tp % 10 + '0', tp /= 10;
			}
			buf[tl] = '\0';
		}

		/* The old checking system
		void check(){
			for(size_t i=1;i<=this->len;i++){
				if(this->numArr[i]>9999)
					this->numArr[i+1]+=this->numArr[i]/10000,
					this->numArr[i]%=10000;
				if(i==this->len && this->numArr[i+1]!=0) this->len++;
			}
		} */

		bigNum hadd(const bigNum a, const bigNum b) const {
			bigNum ret; int t = 0;
			ret.len = max(a.len, b.len);
			for (size_t i = 1; i <= ret.len; i++) {
				// ret.numArr[i]=(a.numArr[i])+(b.numArr[i]);
				t += (a.numArr[i]) + (b.numArr[i]);
				ret.numArr[i] = t % 10000, t /= 10000;
			}
			if (t > 0) ret.numArr[++ret.len] = t;
			// ret.check();
			return ret;
		}

		bigNum hsub(const bigNum a, const bigNum b) const {
			bigNum ret;
			for (int i = 1; i <= a.len; i++) {
				ret.numArr[i] = a.numArr[i] - b.numArr[i];
				if (ret.numArr[i] < 0)
					ret.numArr[i] += 10000,
					ret.numArr[i + 1]--;
			}
			for (int i = a.len; i > 0; i--)
				if (ret.numArr[i] != 0) {
					ret.len = i;
					break;
				}
			return ret;
		}

		bigNum hmul(const bigNum x, const bigNum y) const {
			bigNum ret;
			for (int i = 1; i <= x.len; i++)
				for (int j = 1; j <= y.len; j++) {
					int tmp = x.numArr[i] * y.numArr[j];
					int k = i + j - 1;
					ret.numArr[k] += tmp % 10000;
					tmp /= 10000;
					tmp += ret.numArr[k] / 10000;
					ret.numArr[k] %= 10000;
					while ((ret.numArr[++k] += tmp) >= 10000) {
						ret.numArr[k + 1] += ret.numArr[k] / 10000;
						ret.numArr[k] %= 10000, tmp /= 10000;
					}
				}
			ret.len = x.len + y.len - 1;
			if (ret.numArr[ret.len + 1] != 0) ret.len++;
			// ret.check();
			return ret;
		}

	public:

		bigNum operator=(const char* s) {
			if (!okNumStr(s)) {
				bigNum ret;
				ret.len = -1;
				ret.numArr[0] = 0;
				return ret;
			}
			memset(this->numArr, 0, sizeof(this->numArr));
			if (*s == '-') this->numArr[0] = -1, s++;
			else this->numArr[0] = 1;
			size_t l = strlen(s);
			this->len = (l + 3) / 4;
			for (int i = 1, k = l - 1; i <= this->len; i++) {
				int tn = 0, t = 1;
				for (int j = 0; j < 4 && k >= 0; j++, k--, t *= 10)
					tn += (s[k] - '0') * t;
				this->numArr[i] = tn;
			}
			while (this->len > 1 && this->numArr[this->len] == 0) this->len--;
			this->numToStr(this->numStr);
			return *this;
		}

		bigNum operator=(long long n) {
			memset(this->numArr, 0, sizeof(this->numArr));
			if (n < 0) this->numArr[0] = -1, n = -n;
			else this->numArr[0] = 1;
			size_t l = numLen(n);
			this->len = (l + 3) / 4;
			for (int i = 1; i <= this->len; i++) {
				this->numArr[i] = n % 10000;
				n /= 10000;
			}
			this->numToStr(this->numStr);
			return *this;
		}

		/* The old input system
		void input() {
			char buf[1 << 16] = { 0 };
			scanf("%s", buf);
			*this = buf;
		} */

		/* The old print system
		void print(const char *end){
			if(len<1){printf("ERR\n"); return;}
			if(this->numArr[0]==-1) printf("-");
			printf("%hd",this->numArr[this->len]);
			for(int i=this->len-1;i>0;i--)
				printf("%04hd",this->numArr[i]);
			printf("%s",end);
		} */

		inline char* opStr() { return this->numStr; }

		friend std::istream& operator>>(std::istream&, bigNum&);

		friend std::ostream& operator<<(std::ostream&, bigNum&);

		bool operator==(const bigNum n) const {
			if (this->numArr[0] != n.numArr[0]) return 0;
			if (this->len != n.len) return 0;
			for (int i = n.len; i > 0; i--)
				if (this->numArr[i] != n.numArr[i]) return 0;
			return 1;
		}

		bool operator<(const bigNum n) const {
			if (*this == n) return 0;
			if (this->numArr[0] == -1 && n.numArr[0] == 1) return 1;
			if (this->numArr[0] == 1 && n.numArr[0] == -1) return 0;
			bool f = 1;
			if (this->numArr[0] == -1 && n.numArr[0] == -1) f = 0;
			if (this->len < n.len) return f;
			if (this->len > n.len) return !f;
			for (int i = n.len; i > 0; i--) {
				if (this->numArr[i] < n.numArr[i]) return f;
				if (this->numArr[i] > n.numArr[i]) return !f;
			}
			return !f;
		}

		bool operator!=(const bigNum n) const { return !(*this == n); }

		bool operator>=(const bigNum n) const { return !(*this < n); }

		bool operator>(const bigNum n) const { return !(*this < n) && *this != n; }

		bool operator<=(const bigNum n) const { return !(*this > n); }

		bigNum operator+(const bigNum n) const {
			bigNum ret; bool f = 1; int pn = 1;
			if (this->numArr[0] == -1 && n.numArr[0] == -1) pn = -1;
			else if (this->numArr[0] == 1 && n.numArr[0] == 1) pn = 1;
			else if (this->numArr[0] == 1 && n.numArr[0] == -1) {
				f = 0; bigNum a = *this, b = n;
				b.numArr[0] = 1;
				pn *= 1;
				if (b > a) {
					bigNum tp = a;
					a = b; b = tp;
					pn *= -1;
				}
				ret = hsub(a, b);
			}
			else if (this->numArr[0] == -1 && n.numArr[0] == 1) {
				f = 0; bigNum a = *this, b = n;
				a.numArr[0] = 1;
				pn *= 1;
				if (a > b) {
					bigNum tp = a;
					a = b; b = tp;
					pn *= -1;
				}
				ret = hsub(b, a);
			}
			if (f) ret = hadd(*this, n);
			ret.numArr[0] = pn;
			ret.numToStr(ret.numStr);
			bigNum zero; zero = "-0";
			if (ret == zero) ret.numArr[0] = 1;
			return ret;
		}

		bigNum& operator+=(const bigNum n) { return (*this = *this + n); }

		bigNum operator-(const bigNum n) const {
			if (this->numArr[0] == -1 && n.numArr[0] == -1) {
				bigNum a = *this, b = n;
				a.numArr[0] = 1;
				b.numArr[0] = 1;
				int pn = 1;
				if (a > b) {
					bigNum tp = a;
					a = b; b = tp;
					pn *= -1;
				}
				bigNum ret = hsub(b, a);
				ret.numArr[0] = pn;
				ret.numToStr(ret.numStr);
				bigNum zero; zero = "-0";
				if (ret == zero) ret.numArr[0] = 1;
				return ret;
			}
			else if (this->numArr[0] == 1 && n.numArr[0] == -1) {
				bigNum b = n;
				b.numArr[0] = 1;
				bigNum ret = hadd(*this, b);
				ret.numArr[0] = 1;
				ret.numToStr(ret.numStr);
				return ret;
			}
			else if (this->numArr[0] == -1 && n.numArr[0] == 1) {
				bigNum b = *this;
				b.numArr[0] = 1;
				bigNum ret = hadd(*this, n);
				ret.numArr[0] = -1;
				ret.numToStr(ret.numStr);
				return ret;
			}
			else {
				bigNum ret, a, b; int f = 1;
				if (*this >= n) a = *this, b = n;
				else a = n, b = *this, f = -1;
				ret = hsub(a, b);
				ret.numArr[0] = f;
				ret.numToStr(ret.numStr);
				bigNum zero; zero = "-0";
				if (ret == zero) ret.numArr[0] = 1;
				return ret;
			}
		}

		bigNum& operator-=(const bigNum n) { return (*this = *this - n); }

		bigNum operator*(const bigNum n) const {
			bigNum ret;
			ret = hmul(*this, n);
			if (this->numArr[0] == -1 && n.numArr[0] == -1) ret.numArr[0] = 1;
			else if (this->numArr[0] == 1 && n.numArr[0] == 1) ret.numArr[0] = 1;
			else ret.numArr[0] = -1;
			ret.numToStr(ret.numStr);
			return ret;
		}

		bigNum& operator*=(const bigNum n) { return (*this = *this * n); }

		bigNum operator/(const bigNum n) const {
			bigNum ret, tp = *this;
			if (tp.numArr[0] == n.numArr[0]) ret.numArr[0] = 1;
			else ret.numArr[0] = -1;
			while (tp >= n) tp -= n, ret += 1;
			bigNum zero; zero = "-0";
			if (ret == zero) ret.numArr[0] = 1;
			return ret;
		}

		inline bigNum& operator/=(const bigNum n) { return (*this = *this / n); }

		bigNum operator%(const bigNum n) const {
			bigNum ret, tp = *this;
			if (tp.numArr[0] == n.numArr[0]) ret.numArr[0] = 1;
			else ret.numArr[0] = -1;
			while (tp >= n) tp -= n, ret += 1;
			return tp;
		}

		bigNum operator%=(const bigNum n) { return (*this = *this % n); }

		bigNum operator^(bigNum n) const {
			if (n == (bigNum)1) return 1;
			bigNum ans(1), base = *this;
			while (n > (bigNum)(1)) {
				if (n % 2 == 1) ans *= base;
				base *= base;
				n /= (bigNum)2;
			}
			return ans;
		}

		inline bigNum operator^=(bigNum& n) { return (*this = *this ^ n); }

		inline bigNum& operator++() { return *this += 1; }

		bigNum& operator++(int) {
			bigNum tp = *this;
			*this += 1;
			return tp;
		}

		inline bigNum& operator--() { return *this -= 1; }

		bigNum& operator--(int) {
			bigNum tp = *this;
			*this -= 1;
			return tp;
		}

		inline bigNum(const long long n = 0) { *this = n; }

		inline bigNum(const char buf[1 << 16]) { *this = buf; }

		operator char* () { return this->numStr; }

		inline bool error() { return this->len == -1; }

	#ifdef _ENABLE_OVERFLOW
		operator long long() {
			long long ans = 0;
			size_t p = 0;
			if (this->numStr[0] == '-') p++;
			for (; this->numStr[p]; p++)
				ans = ans * 10 + this->numStr[p] - '0';
			if (this->numStr[0] == '-') ans *= -1;
			return ans;
		}
	#endif
	};

	std::istream& operator>>(std::istream& is, bigNum& n) {
		char buf[1 << 16] = { 0 };
		is >> buf;
		n = buf;
		return is;
	}

	std::ostream& operator<<(std::ostream& os, bigNum& n) {
		if (n.numArr[0] == -1) os << "-";
		os << n.numArr[n.len];
		for (int i = n.len - 1; i > 0; i--)
			os << n.numArr[i];
		return os;
	}

	bool operator<(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a < b;
	}

	bool operator<(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a < b;
	}

	bool operator<(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a < b;
	}

	bool operator<(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a < b;
	}

	bool operator<=(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a <= b;
	}

	bool operator<=(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a <= b;
	}

	bool operator<=(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a <= b;
	}

	bool operator<=(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a <= b;
	}

	bool operator>(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a > b;
	}

	bool operator>(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a > b;
	}

	bool operator>(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a > b;
	}

	bool operator>(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a > b;
	}

	bool operator>=(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a >= b;
	}

	bool operator>=(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a >= b;
	}

	bool operator>=(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a >= b;
	}

	bool operator>=(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a >= b;
	}

	bool operator==(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a == b;
	}

	bool operator==(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a == b;
	}

	bool operator==(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a == b;
	}

	bool operator==(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a == b;
	}

	bool operator!=(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a != b;
	}

	bool operator!=(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a != b;
	}

	bool operator!=(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a != b;
	}

	bool operator!=(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a != b;
	}

	bigNum operator+(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a + b;
	}

	bigNum operator+(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a + b;
	}

	bigNum operator+(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a + b;
	}

	bigNum operator+(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a + b;
	}

	bigNum& operator+=(bigNum& a, const long long _b) {
		bigNum b(_b);
		return (a = a + b);
	}

	bigNum& operator+=(bigNum& a, const char* _b) {
		bigNum b(_b);
		return (a = a + b);
	}

	bigNum operator-(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a - b;
	}

	bigNum operator-(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a - b;
	}

	bigNum operator-(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a - b;
	}

	bigNum operator-(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a - b;
	}

	bigNum& operator-=(bigNum& a, const long long _b) {
		bigNum b(_b);
		return (a = a - b);
	}

	bigNum& operator-=(bigNum& a, const char* _b) {
		bigNum b(_b);
		return (a = a - b);
	}

	bigNum operator*(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a * b;
	}

	bigNum operator*(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a * b;
	}

	bigNum operator*(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a * b;
	}

	bigNum operator*(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a * b;
	}

	bigNum& operator*=(bigNum& a, const long long _b) {
		bigNum b(_b);
		return (a = a * b);
	}

	bigNum& operator*=(bigNum& a, const char* _b) {
		bigNum b(_b);
		return (a = a * b);
	}

	bigNum operator/(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a / b;
	}

	bigNum operator/(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a / b;
	}

	bigNum operator/(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a / b;
	}

	bigNum operator/(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a / b;
	}

	bigNum& operator/=(bigNum& a, const long long _b) {
		bigNum b(_b);
		return (a = a / b);
	}

	bigNum& operator/=(bigNum& a, const char* _b) {
		bigNum b(_b);
		return (a = a / b);
	}

	bigNum operator%(const long long _a, const bigNum b) {
		bigNum a(_a);
		return a % b;
	}

	bigNum operator%(const char* _a, const bigNum b) {
		bigNum a(_a);
		return a % b;
	}

	bigNum operator%(const bigNum a, const long long _b) {
		bigNum b(_b);
		return a % b;
	}

	bigNum operator%(const bigNum a, const char* _b) {
		bigNum b(_b);
		return a % b;
	}

	bigNum& operator%=(bigNum& a, const long long _b) {
		bigNum b(_b);
		return (a = a % b);
	}

	bigNum& operator%=(bigNum& a, const char* _b) {
		bigNum b(_b);
		return (a = a % b);
	}
}
#endif