#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class BigInt{
public:
	BigInt();
	BigInt(const string& str);
	BigInt(const BigInt& other);
	BigInt(int num);
	BigInt(long long num);
	BigInt(unsigned long long num);
	BigInt(const char* str);
	BigInt(const wchar_t* str);
	BigInt(const BigInt& other);
	BigInt(const BigInt&& other);
	BigInt(const BigInt& other) = default;
	
	BigInt& operator=(const BigInt& other);
	BigInt& operator=(const BigInt&& other);
	BigInt& operator=(const BigInt& other) = default;


	BigInt& operator+=(const BigInt& other);
	BigInt& operator-=(const BigInt& other);
	BigInt& operator*=(const BigInt& other);
	BigInt& operator/=(const BigInt& other);
	BigInt& operator%=(const BigInt& other);
	BigInt& operator&=(const BigInt& other);
	BigInt& operator|=(const BigInt& other);
	BigInt& operator^=(const BigInt& other);
	BigInt& operator<<=(const BigInt& other);
	BigInt& operator>>=(const BigInt& other);

	BigInt operator+(const BigInt& other) const;
	BigInt operator-(const BigInt& other) const;
	BigInt operator*(const BigInt& other) const;
	BigInt operator/(const BigInt& other) const;
	BigInt operator%(const BigInt& other) const;
	BigInt operator&(const BigInt& other) const;
	BigInt operator|(const BigInt& other) const;
	BigInt operator^(const BigInt& other) const;
	BigInt operator<<(const BigInt& other) const;
	BigInt operator>>(const BigInt& other) const;

	BigInt operator+(int num) const;
	BigInt operator-(int num) const;
	BigInt operator*(int num) const;
	BigInt operator/(int num) const;
	BigInt operator%(int num) const;
	BigInt operator&(int num) const;
	BigInt operator|(int num) const;
	BigInt operator^(int num) const;
	BigInt operator<<(int num) const;
	BigInt operator>>(int num) const;
	
	BigInt operator+(long long num) const;
	BigInt operator-(long long num) const;
	BigInt operator*(long long num) const;
	BigInt operator/(long long num) const;
	BigInt operator%(long long num) const;
	BigInt operator&(long long num) const;
	BigInt operator|(long long num) const;
	BigInt operator^(long long num) const;
	BigInt operator<<(long long num) const;
	BigInt operator>>(long long num) const;
	
	BigInt operator+(unsigned long long num) const;
	BigInt operator-(unsigned long long num) const;
	BigInt operator*(unsigned long long num) const;
	BigInt operator/(unsigned long long num) const;
	BigInt operator%(unsigned long long num) const;
	BigInt operator&(unsigned long long num) const;
	BigInt operator|(unsigned long long num) const;
	BigInt operator^(unsigned long long num) const;
	BigInt operator<<(unsigned long long num) const;
	BigInt operator>>(unsigned long long num) const;

	BigInt operator+(const char* str) const;
	BigInt operator-(const char* str) const;
	BigInt operator*(const char* str) const;
	BigInt operator/(const char* str) const;
	BigInt operator%(const char* str) const;
	BigInt operator&(const char* str) const;
	BigInt operator|(const char* str) const;
	BigInt operator^(const char* str) const;
	BigInt operator<<(const char* str) const;
	BigInt operator>>(const char* str) const;

	BigInt operator+(const wchar_t* str) const;
	BigInt operator-(const wchar_t* str) const;
	BigInt operator*(const wchar_t* str) const;
	BigInt operator/(const wchar_t* str) const;
	BigInt operator%(const wchar_t* str) const;
	BigInt operator&(const wchar_t* str) const;
	BigInt operator|(const wchar_t* str) const;
	BigInt operator^(const wchar_t* str) const;
	BigInt operator<<(const wchar_t* str) const;
	BigInt operator>>(const wchar_t* str) const;



};



ostream& operator<<(ostream& os, const BigInt& other);
istream& operator>>(istream& is, BigInt& other);


// what the fuck is this?
float InvSquareRoot(float x){
	float xhalf = 0.5f * x;
	int i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float*)&i;
	x = x * (1.5f - xhalf * x * x);
	return x;
}
int main(){
	return 0;
}