#include <iostream>
#include <cmath>
#include <iomanip>

/*
//First order simultaneous ODE
inline float f(float x, float y, float z){
	return 3*x+y-z ; 
}

inline float g(float x, float y, float z){
	return 2*x-y+z ;
}
*/

//Second order ODE (broken into simultaneous first order ODE)
inline float f(float x, float y, float z){
	return z ; 
}

inline float g(float x, float y, float z){
	return x*z*z - y*y ;
}

void runge_kutta(float x0, float y0, float z0, float xN, float step_size){
	int steps = (xN - x0) / step_size ;
	float x, y, z, k1, k2, k3, k4, k, l1, l2, l3, l4, l ;
	std::cout << "Steps(n): " << steps << std::endl ;	
	std::cout << std::setw(10)  << "X" << std::setw(20) << "Y" << std::setw(20) << "Z" <<  std::endl ;
	std::cout << "--------------------------------------------------------" << std::endl ;  
	for(int i=0; i<steps; i++){
		k1 = step_size * f(x0, y0, z0) ;
		l1 = step_size * g(x0, y0, z0) ;
		k2 = step_size * f(x0 + (0.5*step_size), y0 + (0.5*k1), z0 + (0.5*l1)) ;
		l2 = step_size * g(x0 + (0.5*step_size), y0 + (0.5*k1), z0 + (0.5*l1)) ;
		k3 = step_size * f(x0 + (0.5*step_size), y0 + (0.5*k2), z0 + (0.5*l2)) ;
		l3 = step_size * g(x0 + (0.5*step_size), y0 + (0.5*k2), z0 + (0.5*l2)) ;
		k4 = step_size * f(x0 + step_size, y0 + k3, z0 + l3) ;
		l4 = step_size * g(x0 + step_size, y0 + k3, z0 + l3) ;
		k = (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4) ;
		l = (1.0/6.0)*(l1 + 2*l2 + 2*l3 + l4) ;
		x = x0 + step_size ;
		y = y0 + k ;
		z = z0 + l ;
		x0 = x ;
		y0 = y ;
		z0 = z ;
		std::cout << std::setw(10)  << k3 << std::setw(20) << l3 << std::setw(20) << z << std::endl ; 
		std::cout << std::setw(10)  << x << std::setw(20) << y << std::setw(20) << z << std::endl ; 
	}
}

int main(int argc, char *argv[]){
	float x0, y0, z0, xN, step_size ;
	std::cout << "!!!!! RUNGE-KUTTA METHOD !!!!! " << std::endl ;
	std::cout << "Input:\nInitial X (x0): "  ;
	std::cin >> x0 ;
	std::cout << "Initial Y (y0): " ;
	std::cin >> y0 ;
	std::cout << "Initial Y (y0): " ;
	std::cin >> z0 ;
	std::cout << "For X : "  ;
	std::cin >> xN ;
	std::cout << "Step-size (h): "  ;
	std::cin >> step_size ;
	
	runge_kutta(x0, y0, z0, xN, step_size) ;
	
	return 0 ;
}
