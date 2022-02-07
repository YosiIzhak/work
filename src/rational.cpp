#include <cstdio>
#include <cassert>
#include <cstdlib>
#include "rational.hpp"

/******Constructor*******/

Rational::Rational(int a_numerator, int a_denominator, bool a_reduced)
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

	if(a_reduced)
	{
		reduce();
	}
}

/******add*******/

Rational& Rational::add(Rational const& a_rational)
{
	m_numerator = (m_numerator * a_rational.m_denominator) + (m_denominator * a_rational.m_numerator);
    m_denominator = m_denominator * a_rational.m_denominator;
	reduce();
	axioms();
	return *this;
}

/******sub*******/

Rational&  Rational::sub(Rational const& a_rational)
{
	m_numerator = (m_numerator * a_rational.m_denominator) - (m_denominator * a_rational.m_numerator);
    m_denominator = m_denominator * a_rational.m_denominator;
	reduce();
	axioms();
	return *this;
}

/******mul*******/

Rational& Rational::mul(Rational const& a_rational)
{	
	m_numerator = a_rational.m_numerator * m_numerator; 
	m_denominator = a_rational.m_denominator * m_denominator;
	reduce();
	axioms();
	return *this;
}

/******div*******/

Rational& Rational::div(Rational const& a_rational)
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
	return *this;
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

Rational& Rational::operator+(Rational& a_rational)
{
	return this->add(a_rational);
}
Rational& Rational::operator-(Rational& a_rational)
{
	return this->sub(a_rational);
}
Rational& Rational::operator*(Rational& a_rational)
{
	return this->mul(a_rational);
}
Rational& Rational::operator/(Rational& a_rational)
{
	return this->div(a_rational);
}
Rational& Rational::operator+=(Rational& a_rational)
{
	return this->add(a_rational);
}
Rational& Rational::operator-=(Rational& a_rational)
{
	return this->sub(a_rational);
}
Rational& Rational::operator*=(Rational& a_rational)
{
	return this->mul(a_rational);
}
Rational& Rational::operator/=(Rational& a_rational)
{
	return this->div(a_rational);
}
Rational& Rational::operator++()
{
	 m_numerator += m_denominator;
	return *this;
}
Rational Rational::operator++(int a)
{
 	  Rational temp = *this;
       m_numerator += m_denominator;
       return temp;
}
Rational& Rational::operator--()
{
	 m_numerator -= m_denominator;
	return *this;
}
Rational Rational::operator--(int a)
{
	 Rational temp = *this;
      m_numerator -= m_denominator;
	  return temp;
} 
Rational& Rational::operator-()
{
	m_numerator *= -1;
	return *this;
}
Rational& Rational::operator+()
{
	m_numerator *= +1;
	return *this;
}
bool Rational::operator==(Rational& a_rational) const
{
	return (m_numerator == a_rational.getNumerator() && m_denominator ==  a_rational.getDenominator());
}
bool Rational::operator!=(Rational& a_rational) const
{
	return !(*this == a_rational);
}
bool Rational::operator<(Rational& a_rational) const
{
	if (m_numerator / m_denominator < a_rational.m_numerator / a_rational.m_denominator)
	{
		return true;
	}
	return false;
}
bool Rational::operator>(Rational& a_rational) const
{
	if (!(*this == a_rational) && !(*this < a_rational))
	{
		return true;
	}
	return false;
}
bool Rational::operator>=(Rational& a_rational) const
{
	if (*this == a_rational || *this > a_rational)
	{
		return true;
	}
	return false;
}
bool Rational::operator<=(Rational& a_rational) const
{
	if (*this == a_rational || *this < a_rational)
	{
		return true;
	}
	return false;
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
Rational operator+(Rational const& a_first, Rational const& a_second)
{
	Rational res = a_first;
	res.mul(a_second);
	return res;
}
Rational operator-(Rational const& a_first, Rational const& a_second)
{
	Rational res = a_first;
	res.sub(a_second);
	return res;
}
Rational operator*(Rational const& a_first, Rational const& a_second)
{
	Rational res = a_first;
	res.mul(a_second);
	return res;
}
Rational operator/(Rational const& a_first, Rational const& a_second)
{
	Rational res = a_first;
	res.div(a_second);
	return res;
}