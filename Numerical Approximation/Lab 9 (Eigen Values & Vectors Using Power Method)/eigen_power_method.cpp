#include <iostream>
#include <cmath>
#define ALMOST_ZERO 0.0000001

void eigen_power_method(int n){
	float mat[n][n], guess[n], ans[n], error[n], error_max, lambda, E ;
	std::cout << "Enter the elements of matrix: " << std::endl ;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			std::cin >> mat[i][j] ;
		}
	}
	std::cout << "Enter the initial guess for eigen vector: " << std::endl ;
	for(int i=0; i<n; i++){
		std::cin >> guess[i] ;
	}
	std::cout << "Tolerance(E): " ;
	std::cin >> E ;
	do{
		//Product 
		for(int i=0; i<n; i++){
			ans[i] = 0 ;
			for(int k=0; k<n; k++){
			    ans[i] += mat[i][k]*guess[k] ; 
			}
		}
		//Largest Element
		lambda = 0 ; 
		for(int i=0; i<n; i++){
			if(ans[i] > lambda) lambda = ans[i] ;
		}
		
		for(int i=0; i<n; i++){
			ans[i] /= lambda ;
		}
		
		//Error Between Iterations
		for(int i=0; i<n; i++)
			error[i] = fabs(ans[i]-guess[i]) ;
			
		error_max = 0 ;
		for(int i=0; i<n; i++){
			if(error[i] > error_max) error_max = error[i] ;
		}	
			
		for(int i=0; i<n; i++){
			guess[i] = ans[i] ;
		}
	
	}while(fabs(error_max) > E) ;
	
	std::cout << "Eigen Value: " << lambda << std::endl ;
	std::cout << "Eigen Vector: " << std::endl ;
    for(int i=0; i<n; i++){
		std::cout << ans[i] << std::endl ;
	}	
		}

int main(int argc, char *argv[]){
	int n ;
	std::cout << "!!!!! EIGEN VALUE & VECTOR USING POWER METHOD !!!!! " << std::endl ;
	std::cout << "Input:\nOrder(n): "  ;
	std::cin >> n ;
	eigen_power_method(n) ;
	return 0 ;
	
}
