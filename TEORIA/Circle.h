#define PI 3,1415

#ifndef __CIRCLE__
#define __CIRCLE__

class Circle
{
public:
	int rad;

	const Circle operator=(const Circle& r)
	{
		rad = r.rad;
		return (*this);
	}

	bool operator==(const Circle& r) const
	{
		return (rad == r.rad) ? true : false;
	}
	 
	bool operator!=(const Circle& r) const
	{
		return (rad != r.rad) ? true : false;
	}

	const Circle operator+=(const Circle& r)
	{
		rad += r.rad;
		return (*this);
	}

	const Circle operator-=(const Circle& r)
	{
		rad -= r.rad;
		return (*this);
	}

	Circle operator+(const Circle& r) const
	{
		Circle c;

		c.rad = r.rad + rad;

		return c;
	}

	Circle operator-(const Circle& r) const
	{
		Circle c;

		c.rad = r.rad - rad;

		return c;
	}
	
	float GetArea() const
	{
		return(PI*rad^2);
	}
	
};

#endif