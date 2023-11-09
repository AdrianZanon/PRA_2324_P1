#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Point2D.h"

Rectangle::Rectangle(){
	vs = new Point2D[4];
	vs[0] = Point2D(-1 , 0.5);
	vs[1] = Point2D( 1 , 0.5);
	vs[2] = Point2D( 1 , -0.5);
	vs[3] = Point2D(-1 , -0.5);
}

Rectangle::~Rectangle(){
	delete[] vs;
}

Rectangle::Rectangle(std::string color, Point2D* vertices){
	if(check(vertices) == 0){
		throw std::invalid_argument ("No es un rectángulo");
}
	else{
		vs = new Point2D[4];
                for(int i = 0 ; i < 4 ; i++){
			vs[i] = vertices[i];
			vs[i] = vertices[i];
		}
	this->color = color;
	}
}

Rectangle::Rectangle(const Rectangle &r){
	vs = new Point2D[4];
	for(int i = 0 ; i < 4 ; i++){
		vs[i] = r.vs[i];
	}
	color = r.color;
}

Point2D Rectangle::get_vertex(int ind) const{
	if(ind > 3){
		throw std::out_of_range ("No existe ese vértice");
	}
	else{
		return vs[ind];
	}
}

Point2D Rectangle::operator[](int ind) const{
	if(ind > 3){
        	throw std::out_of_range ("No existe ese vértice");
        }
        else{
        	return vs[ind];
	}
}

void Rectangle::set_vertices(Point2D* vertices){
	if(check(vertices) == 0){
        	throw std::invalid_argument ("No es un rectángulo");
        }
        else{
        	for(int i = 0 ; i < 4 ; i++){
                	vs[i] = vertices[i];
                }
        }
}


Rectangle& Rectangle::operator=(const Rectangle &r){
	vs = r.vs;
        color = r.color;
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	for(int i = 0 ; i < 4 ; i++){
		out << r.vs[i];
	}
	return out << r.color;
}


double Rectangle::area() const{
	return Point2D::distance(vs[0],vs[1]) * Point2D::distance(vs[1],vs[2]);
}

double Rectangle::perimeter() const{
	return Point2D::distance(vs[0],vs[1]) * 2 +  Point2D::distance(vs[1],vs[2]) * 2;
}

void Rectangle::translate(double incX, double incY){
	for(int i = 0 ; i < 4 ; i++){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

void Rectangle::print(){
	std::cout << *this << std::endl;
}

bool Rectangle::check(Point2D* vertices){
	if(Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[2] , vertices[3]) && Point2D::distance(vertices[1],vertices[2]) == Point2D::distance(vertices[3] , vertices[0])){
		return 1;
	}
	else{
		return 0;
	}
}
