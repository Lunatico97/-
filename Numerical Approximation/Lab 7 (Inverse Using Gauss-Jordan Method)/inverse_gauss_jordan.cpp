#include <iostream>
#include <cmath>
#define ALMOST_ZERO 0.0000001

void inverse_gauss_jordan(int n){
	float aug_mat[n][2*n] ;
	float ratio ;
	std::cout << "Enter the elements of matrix: " << std::endl ;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			std::cin >> aug_mat[i][j] ;
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=n; j<2*n; j++){
			if((i+n) == j) aug_mat[i][j] = 1 ;
			else aug_mat[i][j] = 0 ;
		}
	}
	
	std::cout << "Augmented Matrix: " << std::endl ;
	for(int i=0; i<n; i++){
		for(int j=0; j<2*n; j++){
			std::cout << aug_mat[i][j] << " " ;
		}
		std::cout << "\n" ;
	}
	
	
	for(int i=0; i<n; i++){
		if(fabs(aug_mat[i][i]) < ALMOST_ZERO){
		    std::cout << "!!! PIVOT ZERO !!!" << std::endl ;
		    exit(1) ; 
		}
		for(int j=0; j<n; j++){
		    if(i!=j){
			    ratio = aug_mat[j][i] / aug_mat[i][i] ;
			    for(int k=i; k<2*n; k++){
			        aug_mat[j][k] -= ratio*aug_mat[i][k] ; 
				}
			}
		}
	}

	std::cout << "The inverse is: " << std::endl ;
    for(int i=0; i<n; i++){
		for(int j=n; j<2*n; j++){
			std::cout << aug_mat[i][j]/aug_mat[i][i] << " " ;
		}
		std::cout << "\n" ;
	}
	
}

int main(int argc, char *argv[]){
	int n ;
	std::cout << "!!!!! INVERSE USING GAUSS-JORDAN METHOD !!!!! " << std::endl ;
	std::cout << "Input:\nOrder(n): "  ;
	std::cin >> n ;
	inverse_gauss_jordan(n) ;
	return 0 ;
	
}
