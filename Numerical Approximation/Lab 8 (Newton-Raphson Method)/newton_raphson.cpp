   
#include <iostream>
#include <cmath>

#define MAX_ITERATIONS 500
#define ALMOST_ZERO 0.00000001

inline float func(float x){
	return sin(x) + (1/x) ; 
}

inline float func_der(float x){
	return cos(x) + (-1/(x*x)) ;
}

float newton_raphson(float x0, float E){
	float x ;
	int iterations = 0 ;
	
	while(fabs(func(x0)/func_der(x0)) > E){
		if(fabs(func_der(x0)) < ALMOST_ZERO){
			std::cout << "!!! ERROR !!!" << std::endl ;
			break ;
		}
		
		x = x0 - (func(x0)/func_der(x0)) ;
		x0 = x ;
		
		iterations ++ ;
		
		if(iterations > MAX_ITERATIONS){
			std::cout << "ITERATIONS EXCEEDED" << std::endl ;
			break ;
		}
	}
	return x ;
}

int main(int argc, char *argv[]){
	float x0, E ;
	std::cout << "!!!!! NEWTON-RAPHSON METHOD !!!!! " << std::endl ;
	std::cout << "Input:\nInitial Guess(A): "  ;
	std::cin >> x0 ;
	std::cout << "Tolerance(E): "  ;
	std::cin >> E ;
	std::cout << "Solution: " << newton_raphson(x0, E) ;
	return 0 ;
}
