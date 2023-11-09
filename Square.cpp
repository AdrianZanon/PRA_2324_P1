#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"
#include "Rectangle.h"
#include "Square.h"

bool Square::check(Point2D* vertices){
	if(Point2D::distance(vertices[0],vertices[1]) == Point2D::distance(vertices[1], vertices[2]) && Point2D::distance(vertices[2],vertices[3]) == Point2D::distance(vertices[3], vertices[0])){
		return 1;
			}
	else{
		return 0;
	}
}

Square::Square(){
	vs = new Point2D[4];
        vs[0] = Point2D(-1 , 1);
        vs[1] = Point2D( 1 , 1);
        vs[2] = Point2D( 1 , -1);
        vs[3] = Point2D(-1 , -1);
}

Square::Square(std::string color, Point2D* vertices){
	if(check(vertices) == 0){
                throw std::invalid_argument ("Figura inválida. \n");
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

void Square::set_vertices(Point2D* vertices){
	if(check(vertices) == 0){
        	throw std::invalid_argument ("Figura inválida. \n");
        }
        else{
        	for(int i = 0 ; i < 4 ; i++){
        		vs[i] = vertices[i];
		}
	}
}

std::ostream& operator<<(std::ostream &out, const Square &square){
	for(int i = 0 ; i < 4 ; i++){
        	out << square.vs[i] << " ";
        }
	return out << square.color;
}

void Square::print(){
	std::cout << *this << std::endl;
}
