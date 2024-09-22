	#include <iostream>
	#include <cmath>
	#include <iomanip>
	
	inline float func(float x, float y){
		return x*x + y ; 
	}
	
	void euler(float x0, float y0, float xN, int steps){
		float step_size = (xN - x0) / steps ;
		float slope, x, y ;
		std::cout << "Step Size (h):" << step_size << std::endl ;	
		std::cout << std::setw(10)  << "X" << std::setw(20) << "Y" << std::endl ;
		std::cout << "-------------------------------------------" << std::endl ;  
		for(int i=0; i<steps; i++){
			slope = func(x0, y0) ;
			x = x0 + step_size ;
			y = y0 + slope * step_size ;
			x0 = x ;
			y0 = y ;
			std::cout << std::setw(10)  << x << std::setw(20) << y << std::endl ; 
		}
	}
	
	int main(int argc, char *argv[]){
		float x0, y0, xN, steps ;
		std::cout << "!!!!! EULER METHOD !!!!! " << std::endl ;
		std::cout << "Input:\nInitial X (x0): "  ;
		std::cin >> x0 ;
		std::cout << "Initial Y (y0): " ;
		std::cin >> y0 ;
		std::cout << "Final X (xN): "  ;
		std::cin >> xN ;
		std::cout << "Steps (n): "  ;
		std::cin >> steps ;
		
		euler(x0, y0, xN, steps) ;
		
		return 0 ;
	}
