#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

class Point2D{
	public :

		double x;
		double y;

		Point2D(double x=0, double y=0);

		static double distance(const Point2D&, const Point2D&);
		
		friend  bool operator==(const Point2D&, const Point2D&);

		friend bool operator!=(const Point2D&, const Point2D&);

		friend std::ostream& operator<<(std::ostream&, const Point2D&);
};

#endif
