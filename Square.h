#ifndef Square_H
#define Square_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"
#include "Rectangle.h"

class Square : public Rectangle{
	private:
		static bool check(Point2D* vertices);
	public:
		Square();
		Square(std::string color, Point2D* vertices);
		void set_vertices(Point2D* vertices) override final;
		friend std::ostream& operator<<(std::ostream &out, const Square &square);
		void print() override final;
};

#endif
