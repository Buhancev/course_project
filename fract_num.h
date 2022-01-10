#pragma once
#include <iostream>

class fract_num
{
private:

	long int numerator;
	long int denominator;

	int gcd(long int a, long int b);
public:

	//����������� �� ���������
	fract_num();

	//����������� � ����� �����������
	fract_num(long int n, long int d);

	//����������� �����
	fract_num(const fract_num& a);

	//����������
	~fract_num() { }

	//����� �� �����
	friend std::ostream& operator<< (std::ostream& os, const fract_num& a);

	//�������� �������������� � ����������
	// 
	//�� � ��
	friend fract_num operator+ (const fract_num& a, const fract_num& b);
	friend fract_num operator- (const fract_num& a, const fract_num& b);
	friend fract_num operator* (const fract_num& a, const fract_num& b);
	friend fract_num operator/ (const fract_num& a, const fract_num& b);
	//
	//�� � �������
	friend fract_num operator+ (const fract_num& a, const int& b);
	friend fract_num operator- (const fract_num& a, const int& b);
	friend fract_num operator* (const fract_num& a, const int& b);
	friend fract_num operator/ (const fract_num& a, const int& b);
	//������� � ��
	friend fract_num operator+ (const int& a, const fract_num& b);
	friend fract_num operator- (const int& a, const fract_num& b);
	friend fract_num operator* (const int& a, const fract_num& b);
	friend fract_num operator/ (const int& a, const fract_num& b);

	//���������� � �����������
	fract_num operator+= (const fract_num& b);
	fract_num operator-= (const fract_num& b);

	//�������
	//����������
	friend fract_num operator++ (const fract_num& a);
	friend fract_num operator-- (const fract_num& a);
	//
	//�����������
	friend fract_num operator++ (const fract_num& a, int);
	friend fract_num operator-- (const fract_num& a, int);

	//����������
	friend bool operator< (const fract_num& a, const fract_num& b);
	friend bool operator> (const fract_num& a, const fract_num& b);
	friend bool operator== (const fract_num& a, const fract_num& b);
	friend bool operator!= (const fract_num& a, const fract_num& b);

	//�������������� � ��������
	operator int();
	operator double();
};

