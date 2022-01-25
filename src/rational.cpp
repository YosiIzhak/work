#include <cstdio>
#include <cassert>
#include <cstdlib>
#include "../inc/rational.hpp"

/******Constructor*******/

Rational::Rational(int a_numerator, int a_denominator, bool a_redused)
  :m_numerator(a_numerator)
  ,m_denominator (a_denominator)
{
	assert(a_denominator != 0);
	if(a_denominator < 0)
	{
		m_numerator *= (-1);
		m_denominator *= (-1);
	}

	if(a_numerator == 0)
	{
		m_denominator = 1;
		return;
	}

	if(a_redused)
	{
		reduce();
	}
}

/******add*******/

void Rational::add(Rational a_rational)
{
	m_numerator = (m_numerator * a_rational.m_denominator) + (m_denominator * a_rational.m_numerator);
    m_denominator = m_denominator * a_rational.m_denominator;
	reduce();
	axioms();
}

/******sub*******/

void Rational::sub(Rational a_rational)
{
	m_numerator = (m_numerator * a_rational.m_denominator) - (m_denominator * a_rational.m_numerator);
    m_denominator = m_denominator * a_rational.m_denominator;
	reduce();
	axioms();
}

/******mul*******/

void Rational::mul(Rational a_rational)
{	
	m_numerator = a_rational.m_numerator * m_numerator; 
	m_denominator = a_rational.m_denominator * m_denominator;
	reduce();
	axioms();
}

/******div*******/

void Rational::div(Rational a_rational)
{	
	m_numerator = (m_numerator * a_rational.m_denominator);
    m_denominator =  (m_denominator * a_rational.m_numerator);

	if(m_denominator < 0)
	{
		m_numerator *= (-1);
		m_denominator *= (-1);
	}
	reduce();
	axioms();
}

/******reduce*******/

void Rational::reduce()
{
int num1 = (int) abs((double)m_numerator);
int num2 = (int) abs((double)m_denominator);
int min;
int max;

	if(m_numerator == 0)
	{
		m_denominator = 1;
		return;
	}

	 if(num1 <= num2)
	 {
		 min = num1;
		 max = num2;
	 }
	 else
	 {
		min = num2;
		max = num1;
	 }
		
	for(int i = min; i > 0; i--)
	{
		if(min % i == 0 && max % i == 0)
		{
			m_numerator = m_numerator/i;
			m_denominator = m_denominator/i;
			break;
		}
	}

	axioms();
}

/******inverse*******/

void Rational::inverse()
{	
	assert(m_numerator != 0);
	int temp = 	m_numerator;
	m_numerator = m_denominator;
	m_denominator = temp;

	if(m_denominator < 0)
	{
		m_numerator *= (-1);
		m_denominator *= (-1);
	}
	reduce();
	axioms();
}

/******display*******/

void Rational::display() const
{
	printf("%d/%d\n", m_numerator, m_denominator);
	axioms();
}

/******getNumerator*******/

int Rational::getNumerator() const
{
	axioms();
	return m_numerator;
}

/******getDenominator*******/

int Rational::getDenominator() const
{
	axioms();
	return m_denominator;
}

/******compare*******/

int Rational::compare(Rational a_rational) const
{
 double num1 =  (double) getNumerator()/getDenominator(); 
 double num2 =  (double) a_rational.getNumerator()/a_rational.getDenominator(); 

	if(num1 > num2)
	{
		axioms();
		return 1;
	}
	if(num1 < num2)
	{
		axioms();
		return -1;
	}

axioms();
return 0;

}

/******equal*******/

bool Rational::equal(Rational a_rational) const
{
	bool result = (getNumerator() == a_rational.getNumerator() && getDenominator() == a_rational.getDenominator());
	axioms();
	return result;
}

/******notEqual*******/

 bool Rational::notEqual(Rational a_rational) const
 {
	bool result = ( !!! (getNumerator() == a_rational.getNumerator() && getDenominator() == a_rational.getDenominator()));
	axioms();
	return result;
 }

/******axioms*******/

void Rational::axioms() const
{
	assert(m_denominator != 0);
}

/******add*******/

Rational add(Rational a, Rational b)
{
int numerator = (a.getNumerator() * b.getDenominator()) + (a.getDenominator() * b.getNumerator());
int denominator =  a.getDenominator() * b.getDenominator();

	Rational result(numerator, denominator);

return result;
}

/******sub*******/

Rational sub(Rational a, Rational b)
{
int numerator = (a.getNumerator() * b.getDenominator()) - (a.getDenominator() * b.getNumerator());
int denominator =  a.getDenominator() * b.getDenominator();

	Rational result(numerator, denominator);

return result;
}

/******mul*******/

Rational mul(Rational a, Rational b)
{
int numerator = a.getNumerator() * b.getNumerator();
int denominator = a.getDenominator() * b.getDenominator();

	Rational result (numerator, denominator);

return result;
}

/******div*******/

Rational div(Rational a, Rational b)
{
int numerator = a.getNumerator() * b.getDenominator();
int denominator = a.getDenominator() * b.getNumerator();

	Rational result (numerator, denominator);

return result;
}



