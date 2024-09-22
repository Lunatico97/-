
#include <iostream>
#include <cmath>
#include <iomanip>

inline float func(float x){
	return log(x) + x*x ;
}

float bisection(float a, float b, float E){
	float c ;
	int max_iterations = (log(b-a) - log(E)) / log(2) ;
	std::cout << "MAX_ITERATIONS: " << max_iterations << std::endl ;
	int iterations = 0 ;
	
	if(func(a)*func(b) > 0) std::cout << "Doesn't exist within the range " << "(" << a << ", "  << b << ")" << std::endl ;
	
	else if(func(a)*func(b) == 0){
		if(func(a) == 0) std::cout << a << std::endl ;
		if(func(b) == 0) std::cout << b << std::endl ;
	}
	
	else{
		std::cout << std::setw(10) << "A" << std::setw(10) << "B" << std::setw(10) << "C" 
				  << std::setw(20) << "f(C)" << std::endl ;
		std::cout << "-------------------------------------------------------" << std::endl ;
		do{
			c = (a + b) / 2 ;
			
			if(func(a)*func(c) < 0) b = c ;
			else a = c ;
			
			iterations ++ ;
			
			std::cout << std::setw(10) << a << std::setw(10) << b << std::setw(10) << c 
			          << std::setw(20) << func(c) << std::endl ;
			
			if(iterations > max_iterations) break ;
		}
		while(fabs(func(c))> E) ;
		return c ;
	}
}

int main(int argc, char *argv[]){
	
	std::cout << "!!!!!!!!!!!!!!!!! BISECTION METHOD !!!!!!!!!!!!!!!!!!!!!!!!!!!! " << std::endl ;
	std::cout << "Input the interval in which the solution seems to exist: " << std::endl ;
	float a, b, E ;
	std::cout << "Lower Interval(A): " ;
	std::cin >> a ;
	std::cout << "Higher Interval(B): " ;
	std::cin >> b ;
	std::cout << "Tolerance(E): " ;
	std::cin >> E ;
	std::cout << "\nSolution: " << bisection(a, b, E) << std::endl ;
	
	return 0 ;
}
