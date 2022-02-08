#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
namespace numbers {
class Rational
{
public:
	Rational(int a_numerator = 0, int a_denominator = 1, bool a_reduced = true);

	Rational& add(Rational const& a_rational);
	Rational& sub(Rational const& a_rational);
	Rational& mul(Rational const& a_rational);
	Rational& div(Rational const& a_rational);
	

	void reduce();
	void inverse();
	void display() const;

	int getNumerator() const;
	int getDenominator() const;

	int compare(Rational a_rational) const;
	bool equal(Rational a_rational) const;
	bool notEqual(Rational a_rational) const;

	
	Rational& operator+(Rational& a_rational);
	Rational& operator-(Rational& a_rational);
	Rational& operator*(Rational& a_rational);
	Rational& operator/(Rational& a_rational);
	Rational& operator+=(Rational& a_rational);
	Rational& operator-=(Rational& a_rational);
	Rational& operator*=(Rational& a_rational);
	Rational& operator/=(Rational& a_rational);
	
	Rational& operator++();
	Rational operator++(int a);
	Rational& operator--();
	Rational operator--(int a);
	Rational operator-();
	Rational& operator+();

	bool operator==(Rational& a_rational) const;
	bool operator!=(Rational& a_rational) const;
	bool operator<(Rational& a_rational) const;
	bool operator>(Rational& a_rational) const;
	bool operator>=(Rational& a_rational) const;
	bool operator<=(Rational& a_rational) const;
	std::ostream& print(std::ostream& os) const;
private:
	void axioms() const;

private:
	int m_numerator;
	int m_denominator;
};

Rational add(Rational a, Rational b);
Rational sub(Rational a, Rational b);
Rational mul(Rational a, Rational b);
Rational div(Rational a, Rational b);
Rational operator+(Rational const& a_first, Rational const& a_second);
Rational operator-(Rational const& a_first, Rational const& a_second);
Rational operator*(Rational const& a_first, Rational const& a_second);
Rational operator/(Rational const& a_first, Rational const& a_second);
}

#endif /*#ifndef RATIONAL_H */
