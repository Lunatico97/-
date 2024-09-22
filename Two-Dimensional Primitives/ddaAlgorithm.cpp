
#include <iostream>
#include <cmath>
#include <graphics.h>

class DDA{
	
	public:
	
		DDA() ;
		void generateLine(int x1, int y1, int x2, int y2) ;
		
	private:
		
		float xInc, yInc, pixelX, pixelY ;
		int delX, delY, steps ;
};

DDA::DDA(){}

void DDA::generateLine(int x1, int y1, int x2, int y2){
	int graphicsDriver = DETECT, graphicsMode, color ;
	
	delX = x2 - x1 ;
	delY = y2 - y1 ;
	
	if(abs(delY) > abs(delX)) steps = delY ;
	else steps = delX ;
	
	pixelX = x1 ;
	pixelY = y1 ;
	
	xInc = delX / float(steps) ;
	yInc = delY / float(steps) ;
	
	initgraph(&graphicsDriver, &graphicsMode, "....\\WINBGIM\\BGI") ;
	//draw here
	for(int i=0; i<steps; i++){
		putpixel(pixelX, pixelY, BLUE) ;
		pixelX += xInc ;
		pixelY += yInc ;	
	}
	
	while(!kbhit()) delay(1) ;
	closegraph() ;
}

int main(int argc, char *argv[]){
	
	int x1, y1, x2, y2 ;
	DDA *dda = new DDA() ;
	std::cout << "Enter endpoints for the line: " << std::endl ;
	std::cout << "X1: " ;
	std::cin >> x1 ;
	std::cout << "Y1: " ;
	std::cin >> y1 ;
	std::cout << "X2: " ;
	std::cin >> x2 ;
	std::cout << "Y2: " ;
	std::cin >> y2 ;
	dda->generateLine(x1, y1, x2, y2) ;
	delete dda ;
	return 0 ;
	
}
