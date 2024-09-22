   
#include <iostream>
#include <cmath>
#define ALMOST_ZERO 0.0000001

void gauss_elimination(int n){
	float aug_mat[n][n+1], res[n], sum ;
	float ratio ;
	std::cout << "Enter the coefficients of the system: " << std::endl ;
	for(int i=0; i<n; i++){
		for(int j=0; j<n+1; j++){
			std::cin >> aug_mat[i][j] ;
		}
	}
	
	for(int i=0; i<n; i++){
		if(fabs(aug_mat[i][i]) < ALMOST_ZERO){
		    std::cout << "!!! PIVOT ZERO !!!" << std::endl ;
		    exit(1) ; 
		}
		for(int j=0; j<n; j++){
			if(i<j){
		    	ratio = aug_mat[j][i] / aug_mat[i][i] ;
				for(int k=i; k<n+1; k++){
			    	aug_mat[j][k] -= ratio*aug_mat[i][k] ; 
				}
			}
		}
	}
	
	std::cout << "!!! UPPER TRIANGULAR FORM !!!" << std::endl ;
	for(int i=0; i<n; i++){
		for(int j=0; j<=n; j++){
			std::cout << aug_mat[i][j] << "\t" ; 
		}
		std::cout << "\n" ;
	} 
	
	//Backward substitution
	res[n-1] = aug_mat[n-1][n]/aug_mat[n-1][n-1] ;
	for(int i=n-2; i>=0; i--){
		sum = 0 ;
		res[i] = aug_mat[i][n] ;
		for(int j=i+1; j<n; j++){
			sum += aug_mat[i][j]*res[j] ;
		}
		res[i] = (res[i]-sum)/aug_mat[i][i] ;
	}
	
	std::cout << "The solutions are: " << std::endl ;
    for(int i=0; i<n; i++){
    	std::cout << res[i] << "\t" ;                                                       
	}
}

int main(int argc, char *argv[]){
	int n ;
	std::cout << "!!!!! GAUSS ELIMINATION METHOD !!!!! " << std::endl ;
	std::cout << "Input:\nOrder(n): "  ;
	std::cin >> n ;
	gauss_elimination(n) ;
	return 0 ;
	
}
