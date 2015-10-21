#ifndef __POINT2D_H__
#define __POINT2D_H__

template <class TYPE>
class Point2D
{
public:
	TYPE x, y;

	~Point2D(){  };

	/*const Point2D& operator = (const Point2D& a)
	{
		x = a.x;
		y = a.y;

		return (*this);
	}*/

	bool operator == (const Point2D& a) const
	{
		return (x == a.x && y == a.y) ? true : false;
	}

	bool operator != (const Point2D& a) const
	{
		return (x != a.x && y != a.y) ? true : false;
	}

	const Point2D& operator += (const Point2D& a)
	{
		x = x + a.x;
		y = y + a.y;

		return (*this);
	}

	const Point2D& operator -= (const Point2D& a)
	{
		x = x - a.x;
		y = y - a.y;

		return (*this);
	}

	Point2D operator + (const Point2D& a) const
	{
		Point k;
		k.x = x + a.x;
		k.y = y + a.y;

		return k;
	}

	Point2D operator - (const Point2D& a) const
	{
		Point k;
		k.x = x - a.x;
		k.y = y - a.y;

		return k;
	}

	bool IsZero() const
	{
		if (x == 0 && y == 0)
			return true;

		return false;
	}

	Point2D SetZero()
	{
		x = 0;
		y = 0;
	}

	Point2D Negate()
	{
		x = -x;
		y = -y;
	}
};

typedef Point2D<int> iPoint2D;
typedef Point2D<float> fPoint2D;

#endif