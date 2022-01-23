#include <cstdio>
#include <cassert>
#include "../inc/rational.hpp"
Rational::Rational(int _num, int _den)
{
    m_num = _num;
	assert(_den != 0);
	m_den = _den;
}

Rational Rational::add(Rational number)
{
	int div; 
	Rational c(0,1);
	c.m_num = m_num*number.m_den + m_den * number.m_num;
	c.m_den = m_den*number.m_den;
	div = gcd(c.m_num, c.m_den);
	c.m_num /= div;
	c.m_den /= div;
	return c;
}
Rational Rational::sub(Rational number)
{
   int div; 
   Rational c(0,1);
    c.m_num = m_num*number.m_den - m_den * number.m_num;
    c.m_den = m_den*number.m_den;
    div = gcd(c.m_num, c.m_den);
	c.m_num /= div;
	c.m_den /= div;
    return c;
}	
Rational Rational::mul(Rational number)
{
	int div; 
	Rational c(0,1);
	c.m_num = m_num * number.m_num;
    c.m_den = m_den * number.m_den;
    div = gcd(c.m_num, c.m_den);
	c.m_num /= div;
	c.m_den /= div;
    return c;
}
Rational Rational::inv()
{
	int div; 
	Rational c(1,1);
	c.m_num =  m_den;
	c.m_den = m_num;
	assert(c.m_den != 0);
	div = gcd(c.m_num, c.m_den);
	c.m_num /= div;
	c.m_den /= div;
	 return c;
}
int Rational::get_num()
{
	return m_num;
}

int Rational::get_den()
{
	return m_den;
}

void Rational::display()
{
	printf("%d/%d\n", m_num, m_den);
}
int Rational::gcd(int x, int y)
{
	if(y == 0)
	{
		return x;
	}
	else
	{
		return gcd(y, x%y);
	} 
}




