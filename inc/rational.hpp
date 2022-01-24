#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
public:
	Rational(int a_numerator = 0, int a_denominator = 1, bool a_reduced = true);

	void add(Rational a_rational);
	void sub(Rational a_rational);
	void mul(Rational a_rational);
	void div(Rational a_rational);

	void reduce();
	void inverse();
	void display() const;

	int getNumerator() const;
	int getDenominator() const;

	int compare(Rational a_rational) const;
	bool equal(Rational a_rational) const;
	bool notEqual(Rational a_rational) const;

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

#endif /*#ifndef RATIONAL_H */
