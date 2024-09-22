   
#include <iostream>
#include <cmath>
#include <graphics.h>

class Transformation{	
	public:	
		Transformation() ;
		void drawObject() ;
		void translate(int tx, int ty) ;
		void scale(int sx, int sy) ;
		void rotate(double angle) ;
		void reflectX() ;
		void reflectY() ;
		
	private:		
		int vertices[3][2] = {{50,50},{100,100},{150,50}} ;
		int offset ;
};

Transformation::Transformation(){}

void Transformation::drawObject(){	
		line(vertices[0][0], vertices[0][1], vertices[1][0], vertices[1][1]) ;
		line(vertices[1][0], vertices[1][1], vertices[2][0], vertices[2][1]) ;
		line(vertices[2][0], vertices[2][1], vertices[0][0], vertices[0][1]) ;
}

void Transformation::translate(int tx, int ty){
	for(int i=0; i<3; i++){
		vertices[i][0] += tx ;
		vertices[i][1] += ty ;
	}	
}

void Transformation::scale(int sx, int sy){
	for(int i=0; i<3; i++){
		vertices[i][0] *= sx ;
		vertices[i][1] *= sy ;
	}	
}

void Transformation::rotate(double angle){
	double theta = (angle*3.1415f)/180 ;
	int x, y ;
	for(int i=0; i<3; i++){
		x = vertices[i][0] ;
		y = vertices[i][1] ;
		vertices[i][0] = x*cos(theta) - y*sin(theta) ;
		vertices[i][1] = x*sin(theta) + y*cos(theta) ;
	}	
}

int main(int argc, char *argv[]){
	
	int graphicsDriver = DETECT, graphicsMode, color ;
	Transformation *transform = new Transformation() ;
	
	initgraph(&graphicsDriver, &graphicsMode, "....\\WINBGIM\\BGI") ;
	setcolor(RED) ;
	transform->drawObject() ;
	transform->translate(100, 50) ;
	setcolor(BLUE) ;
	transform->drawObject() ;
	transform->scale(2, 2) ;
	setcolor(GREEN) ;
	transform->drawObject() ;
	transform->rotate(15) ;
	setcolor(YELLOW) ;
	transform->drawObject() ;

	while(!kbhit()) delay(1) ;
	closegraph() ;
	
	delete transform ;
	return 0 ;
	
}
