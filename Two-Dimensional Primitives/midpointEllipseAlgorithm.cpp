
#include <iostream>
#include <cmath>
#include <graphics.h>

class GimmeEllipse{	
	public:	
		GimmeEllipse() ;
		void generateEllipse(int x, int y, int xradius, int yradius) ;
		
	private:	
		int pixelX, pixelY, pvalue ;
};

GimmeEllipse::GimmeEllipse(){}

void GimmeEllipse::generateEllipse(int x, int y, int xradius, int yradius){
	int graphicsDriver = DETECT, graphicsMode, color ;	
	pixelX = 0 ;
	pixelY = yradius ;
	pvalue = (yradius*yradius) - (xradius*xradius*yradius) + ((xradius*xradius)/4) ;
	
	initgraph(&graphicsDriver, &graphicsMode, "....\\WINBGIM\\BGI") ;
	//draw here
	
	do{
		if(pvalue <= 0){
			pixelX += 1 ;
			pvalue += ((2*yradius*yradius*pixelX) + (yradius*yradius)) ;
		}
		else{
			pixelX += 1 ;
			pixelY -= 1 ;
			pvalue += ((2*yradius*yradius*pixelX) - (2*xradius*xradius*pixelY) + (yradius*yradius)) ;
		}
		
		// 4-way symmetry
		putpixel(pixelX+x, pixelY+y, RED) ;
		putpixel(-pixelX+x, pixelY+y, BLUE) ;
		putpixel(pixelX+x, -pixelY+y, GREEN) ;
		putpixel(-pixelX+x, -pixelY+y, YELLOW) ;
		
	}while((2*yradius*yradius*pixelX) < (2*xradius*xradius*pixelY)) ;
	
	pvalue = ((pixelX + (1/2))*(pixelX + (1/2))) + ((pixelY - 1)*(pixelY - 1)) + (xradius*xradius*yradius*yradius) ;
	
	do{
		if(pvalue <= 0){
			pixelX += 1 ;
			pixelY -= 1 ;
			pvalue += ((2*yradius*yradius*pixelX) - (2*xradius*xradius*pixelY) + (xradius*xradius)) ;
		}
		else{
			pixelY -= 1 ;
			pvalue += ((-2*xradius*xradius*pixelY) + (xradius*xradius)) ;
		}
		
		// 4-way symmetry
		putpixel(pixelX+x, pixelY+y, RED) ;
		putpixel(-pixelX+x, pixelY+y, BLUE) ;
		putpixel(pixelX+x, -pixelY+y, GREEN) ;
		putpixel(-pixelX+x, -pixelY+y, YELLOW) ;
		
	}while(pixelY != 0) ;
	
	while(!kbhit()) delay(1) ;
	closegraph() ;
}

int main(int argc, char *argv[]){
	
	int x, y, xradius, yradius ;
	GimmeEllipse *ellipse = new GimmeEllipse() ;
	std::cout << "Enter center for the ellipse: " << std::endl ;
	std::cout << "X: " ;
	std::cin >> x ;
	std::cout << "Y: " ;
	std::cin >> y ;
	std::cout << "Enter the x-radius: " ;
	std::cin >> xradius ;
	std::cout << "Enter the y-radius: " ;
	std::cin >> yradius ;
	ellipse->generateEllipse(x, y, xradius, yradius) ;
	delete ellipse ;
	return 0 ;
	
}
