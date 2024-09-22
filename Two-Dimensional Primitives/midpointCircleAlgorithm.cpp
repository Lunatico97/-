
#include <iostream>
#include <cmath>
#include <graphics.h>

class Circle{	
	public:	
		Circle() ;
		void generateCircle(int x, int y, int radius) ;
		
	private:	
		int pixelX, pixelY, pvalue ;
};

Circle::Circle(){}

void Circle::generateCircle(int x, int y, int radius){
	int graphicsDriver = DETECT, graphicsMode, color ;	
	pixelX = 0 ;
	pixelY = radius ;
	pvalue = 1 - radius ;
	
	initgraph(&graphicsDriver, &graphicsMode, "....\\WINBGIM\\BGI") ;
	//draw here
	
	do{
		if(pvalue <= 0){
			pixelX += 1 ;
			pvalue += ((2*pixelX) + 1) ;
		}
		else{
			pixelX += 1 ;
			pixelY -= 1 ;
			pvalue += ((2*pixelX)-(2*pixelY)+1) ;
		}
		
		// 8-way symmetry
		putpixel(pixelX+x, pixelY+y, RED) ;
		putpixel(-pixelX+x, pixelY+y, BLUE) ;
		putpixel(pixelX+x, -pixelY+y, GREEN) ;
		putpixel(-pixelX+x, -pixelY+y, YELLOW) ;
		
		putpixel(pixelY+x, pixelX+y, RED) ;
		putpixel(-pixelY+x, pixelX+y, BLUE) ;
		putpixel(pixelY+x, -pixelX+y, GREEN) ;
		putpixel(-pixelY+x, -pixelX+y, YELLOW) ;
		
	} while (pixelX <= pixelY) ;
	
	while(!kbhit()) delay(1) ;
	closegraph() ;
}

int main(int argc, char *argv[]){
	
	int x, y, radius ;
	Circle *circle = new Circle() ;
	std::cout << "Enter center for the circle: " << std::endl ;
	std::cout << "X: " ;
	std::cin >> x ;
	std::cout << "Y: " ;
	std::cin >> y ;
	std::cout << "Enter the radius: " ;
	std::cin >> radius ;
	circle->generateCircle(x, y, radius) ;
	delete circle ;
	return 0 ;
	
}
