
#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

class Bresenham{
	
	public:
	
		Bresenham() ;
		void generateLine(SDL_Renderer *r, Uint8 r, Uint8 g, Uint8 b, int x1, int y1, int x2, int y2) ;
		
	private:
		
		int xInc, yInc, pInc, pixelX, pixelY, delX, delY, steps, pvalue ;
};

Bresenham::Bresenham(){}

void Bresenham::generateLine(SDL_Renderer *r, Uint8 r, Uint8 g, Uint8 b, int x1, int y1, int x2, int y2){
	int graphicsDriver = DETECT, graphicsMode, color ;
	
	delX = abs(x2 - x1) ;
	delY = abs(y2 - y1) ;
	
	if(x2 > x1) xInc = 1 ;
	else xInc = -1 ;
	if(y2 > y1) yInc = 1 ;
	else yInc = -1 ;
	
	if(delX > delY){
		pvalue = 2*delY - delX ;
		steps = delX ;	
	}
	else{
		pvalue = 2*delX - delY ;
		steps = delY ;
	}
	
	pixelX = x1 ;
	pixelY = y1 ;
	
	//draw here
	for(int i=0; i<steps; i++){
		SDL_SetRenderDrawColor(ren, r, g, b, 255)
		SDL_RenderDrawPoint(ren, pixelX, pixelY) ;
		
		if(delX > delY){
			if(pvalue <= 0){
			pvalue += 2*delY ;
			pixelX += xInc ;
			}
			else{
			pvalue += 2*(delY - delX) ;
			pixelX += xInc ;
			pixelY += yInc ;
			}
		}
		else{
			if(pvalue <= 0){
			pvalue += 2*delX ;
			pixelY += yInc ;
			}
			else{
			pvalue += 2*(delX - delY) ;
			pixelX += xInc ;
			pixelY += yInc ;
			}
		}	
	}

}


}
