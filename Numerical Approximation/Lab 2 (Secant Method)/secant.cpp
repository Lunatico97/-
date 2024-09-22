   


#include <iostream>
#include <cmath>

#define MAX_ITERATIONS 500
#define FLOAT_ZERO 0.00000000001

inline float func(float x){
	return x*x - x - 1 ; 
}

float secant(float a, float b, float E){
	float c ;
	int iterations = 0 ;
	
	do{
		if(fabs(func(a) - func(b)) < FLOAT_ZERO){
			std::cout << "Doesn't exist within the range ! " << std::endl ;
			break ;
		}
		
		c = (a*func(b) - b*func(a)) / (func(b) - func(a)) ;
		a = b ;
		b = c ;
		
		iterations ++ ;
		
		if(iterations > MAX_ITERATIONS){
			std::cout << "Can't Solve ! " << std::endl ;
			break ;
		}
	}
	while(fabs(c) > E) ;
	
	return c ;
}

int main(int argc, char *argv[]){
	float a, b, E ;
	std::cout << "!!!!! SECANT METHOD !!!!! " << std::endl ;
	std::cout << "Input:\nFirst Guess(A): "  ;
	std::cin >> a ;
	std::cout << "Second Guess(B): " ;
	std::cin >> b ;
	std::cout << "Tolerance(E): "  ;
	std::cin >> E ;
	
	std::cout << "Solution: " << secant(a, b, E) ;
	return 0 ;
	
}
