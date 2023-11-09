#include <ostream>
#include "Circle.h"
#include <cmath>

Circle::Circle(){
	color = "red";
	center.x = 0;
	center.y = 0;
	radius = 1.0;
}

Circle::Circle(std::string color, Point2D center, double radius){
	this->color = color;
	this->center = center;
	//this->center.y = center.y;
	this->radius = radius;

}

Point2D Circle::get_center() const{
	return center;
}

void Circle::set_center(Point2D p){
	center = p;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	radius = r;
}

std::ostream& operator <<(std::ostream &out, const Circle &c){
	out<<"[ Radio: "<< c.radius << " Coordenadas centro:  " << c.center << " Color:  " << c.color <<"]";
	return out;
}

double Circle::area() const{
	return M_PI * pow(radius, 2);
}

double Circle::perimeter() const{
	return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY){
	center.x = center.x + incX;
	center.y = center.y + incY;
}

void Circle::print(){
	std::cout<< *this << std::endl;
}
