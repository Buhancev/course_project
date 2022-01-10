#include "fract_num.h"

//������� ��� ���������� �����
int fract_num::gcd(long int a, long int b) {
	int c;
	while (b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}

//����������� �� ���������
fract_num::fract_num()
{
	numerator = 0;
	denominator = 0;
}

//����������� � ����� �����������
fract_num::fract_num(long int n, long int d) 
{
	int k = gcd(n, d);
	
	if (k > 0)
	{
		numerator = n / k;
		denominator = d / k;
	}

	else
	{
		numerator = n;
		denominator = d;
	}
}

//����������� �����
fract_num::fract_num(const fract_num& a)
{
	int k = gcd(a.numerator, a.denominator);

	if (k > 0)
	{
		numerator = a.numerator / k;
		denominator = a.denominator / k;
	}

	else
	{
		numerator = a.numerator;
		denominator = a.denominator;
	}
}

//����� �� �����
std::ostream& operator<<(std::ostream& os, const fract_num& a)
{
	os << a.numerator << "/" << a.denominator << '\n';
	return os;
}

//�������� �������������� � ����������

//�� � ��
fract_num operator+ (const fract_num& a, const fract_num& b)
{
	if (a.denominator == b.denominator)
		return fract_num(a.numerator + b.numerator, a.denominator);

	else
		return fract_num(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
}
fract_num operator- (const fract_num& a, const fract_num& b)
{
	if (a.denominator == b.denominator)
		return fract_num(a.numerator - b.numerator, a.denominator);

	else
		return fract_num(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
}
fract_num operator* (const fract_num& a, const fract_num& b)
{
	return fract_num(a.numerator * b.numerator, a.denominator * b.denominator);
}
fract_num operator/ (const fract_num& a, const fract_num& b)
{
	return fract_num(a.numerator * b.denominator, b.numerator * a.denominator);
}

//�� � �������
fract_num operator+ (const fract_num& a, const int& b)
{
	return fract_num(a.numerator + b * a.denominator, a.denominator);
}
fract_num operator- (const fract_num& a, const int& b)
{
	return fract_num(a.numerator - b * a.denominator, a.denominator);
}
fract_num operator* (const fract_num& a, const int& b)
{
	return fract_num(a.numerator * b, a.denominator);
}
fract_num operator/ (const fract_num& a, const int& b)
{
	return fract_num(a.numerator, a.denominator * b);
}

//������� � ��
fract_num operator+ (const int& a, const fract_num& b)
{
	return fract_num(a * b.denominator + b.numerator, b.denominator);
}
fract_num operator- (const int& a, const fract_num& b)
{
	return fract_num(a * b.denominator - b.numerator, b.denominator);
}
fract_num operator* (const int& a, const fract_num& b)
{
	return fract_num(a * b.numerator, b.denominator);
}
fract_num operator/ (const int& a, const fract_num& b)
{
	return fract_num(a * b.denominator, b.numerator);
}

//���������� � �����������
fract_num fract_num::operator+= (const fract_num& b)
{
	if (this->denominator == b.denominator)
	{
		this->numerator = this->numerator + b.numerator;
	}

	else
	{
		this->numerator = this->numerator * b.denominator + b.numerator * this->denominator;
		this->denominator = this->denominator * b.denominator;
	}

	return *this;
}
fract_num fract_num::operator-= (const fract_num& b)
{
	if (this->denominator == b.denominator)
	{
		this->numerator = this->numerator - b.numerator;
	}

	else
	{
		this->numerator = this->numerator * b.denominator - b.numerator * this->denominator;
		this->denominator = this->denominator * b.denominator;
	}

	return *this;
}

//�������
//����������
fract_num operator++ (const fract_num& a)
{
	return fract_num(a.numerator + a.denominator, a.denominator);
}
fract_num operator-- (const fract_num& a)
{
	return fract_num(a.numerator - a.denominator, a.denominator);
}

//�����������
fract_num operator++ (const fract_num& a, int)
{
	return fract_num(a.numerator + a.denominator, a.denominator);
}
fract_num operator-- (const fract_num& a, int)
{
	return fract_num(a.numerator - a.denominator, a.denominator);
}

//����������
bool operator< (const fract_num& a, const fract_num& b)
{
	return (a.numerator * b.denominator < b.numerator * a.denominator) ?  true :  false;
}
bool operator> (const fract_num& a, const fract_num& b)
{
	return (a.numerator * b.denominator > b.numerator * a.denominator) ? true : false;
}
bool operator== (const fract_num& a, const fract_num& b)
{
	return (a.numerator * b.denominator == b.numerator * a.denominator) ? true : false;
}
bool operator!= (const fract_num& a, const fract_num& b)
{
	return (a.numerator * b.denominator != b.numerator * a.denominator) ? true : false;
}

//�������������� � ��������
fract_num::operator int() { return numerator/denominator; }
fract_num::operator double() { return double(numerator) / double(denominator); }

