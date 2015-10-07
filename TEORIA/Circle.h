#define PI 3,1415

#ifndef __CIRCLE__
#define __CIRCLE__

class Circle
{
public:
	int rad;

	Circle operator=(const Circle& r)
	{
		rad = r.rad;
	}

	bool operator==(const Circle& r) const
	{
		return (rad == r.rad) ? true : false;
	}
	 
	bool operator!=(const Circle& r) const
	{
		return (rad != r.rad) ? true : false;
	}

	Circle operator+=(const Circle& r)
	{
		rad += r.rad;
	}

	Circle operator-=(const Circle& r)
	{
		rad -= r.rad;
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