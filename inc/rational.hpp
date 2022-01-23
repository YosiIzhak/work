class Rational
{
public:
	/*second parameter can't be 0*/
	Rational(int num, int den);
	
	Rational add(Rational number);
	
	Rational sub(Rational number);
	
	Rational mul(Rational number);
	
	Rational inv();
	
	int get_num();
	
	int get_den();
	
	void display();
	
	int gcd(int x, int y);

private:
	int m_num;
	int m_den;
};
