#include <iostream>
#include <cmath>
#include <iomanip>

inline float func(float x, float y){
	return x*x + y ; 
}

void runge_kutta(float x0, float y0, float xN, float step_size){
	int steps = (xN - x0) / step_size ;
	float x, y, k1, k2, k3, k4, k ;
	std::cout << "Steps(n): " << steps << std::endl ;	
	std::cout << std::setw(10)  << "X" << std::setw(20) << "Y" << std::endl ;
	std::cout << "-------------------------------------------" << std::endl ;  
	for(int i=0; i<steps; i++){
		k1 = step_size * func(x0, y0) ;
		k2 = step_size * func(x0 + (0.5*step_size), y0 + (0.5*k1)) ;
		k3 = step_size * func(x0 + (0.5*step_size), y0 + (0.5*k2)) ;
		k4 = step_size * func(x0 + step_size, y0 + k3) ;
		k = (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4) ;
		x = x0 + step_size ;
		y = y0 + k * step_size ;
		x0 = x ;
		y0 = y ;
		std::cout << std::setw(10)  << x << std::setw(20) << y << std::endl ; 
	}
}

int main(int argc, char *argv[]){
	float x0, y0, xN, step_size ;
	std::cout << "!!!!! RUNGE-KUTTA METHOD !!!!! " << std::endl ;
	std::cout << "Input:\nInitial X (x0): "  ;
	std::cin >> x0 ;
	std::cout << "Initial Y (y0): " ;
	std::cin >> y0 ;
	std::cout << "Final X (xN): "  ;
	std::cin >> xN ;
	std::cout << "Step-size (h): "  ;
	std::cin >> step_size ;
	
	runge_kutta(x0, y0, xN, step_size) ;
	
	return 0 ;
}
