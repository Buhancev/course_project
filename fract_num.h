#pragma once
#include <iostream>

class fract_num
{
private:

	long int numerator;
	long int denominator;

	int gcd(long int a, long int b);
public:

	//конструктор по умолчанию
	fract_num();

	//конструктор с двумя параметрами
	fract_num(long int n, long int d);

	//конструктор копии
	fract_num(const fract_num& a);

	//деструктор
	~fract_num() { }

	//вывод на экран
	friend std::ostream& operator<< (std::ostream& os, const fract_num& a);

	//бинарные арифметические с операндами
	// 
	//ТД и ТД
	friend fract_num operator+ (const fract_num& a, const fract_num& b);
	friend fract_num operator- (const fract_num& a, const fract_num& b);
	friend fract_num operator* (const fract_num& a, const fract_num& b);
	friend fract_num operator/ (const fract_num& a, const fract_num& b);
	//
	//ТД и базовый
	friend fract_num operator+ (const fract_num& a, const int& b);
	friend fract_num operator- (const fract_num& a, const int& b);
	friend fract_num operator* (const fract_num& a, const int& b);
	friend fract_num operator/ (const fract_num& a, const int& b);
	//базовый и ТД
	friend fract_num operator+ (const int& a, const fract_num& b);
	friend fract_num operator- (const int& a, const fract_num& b);
	friend fract_num operator* (const int& a, const fract_num& b);
	friend fract_num operator/ (const int& a, const fract_num& b);

	//арифметика с накоплением
	fract_num operator+= (const fract_num& b);
	fract_num operator-= (const fract_num& b);

	//унарные
	//префиксная
	friend fract_num operator++ (const fract_num& a);
	friend fract_num operator-- (const fract_num& a);
	//
	//постфиксная
	friend fract_num operator++ (const fract_num& a, int);
	friend fract_num operator-- (const fract_num& a, int);

	//логические
	friend bool operator< (const fract_num& a, const fract_num& b);
	friend bool operator> (const fract_num& a, const fract_num& b);
	friend bool operator== (const fract_num& a, const fract_num& b);
	friend bool operator!= (const fract_num& a, const fract_num& b);

	//преобразование к базовому
	operator int();
	operator double();
};

