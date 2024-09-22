
#include <iostream>
#include <iomanip>
#include <cmath>

#define MAX_SIZE 20
#define MAX_DEG 8
#define ALMOST_ZERO 0.000001

class PolyCurveFit
{
	public:
		PolyCurveFit() ;
		void calcAugMat() ;
		void gauss_jordan() ;
		void getDataset() ;
		void displayDataset() ;
		void displayPolyFit() ;
		
	private:		
		typedef struct {
			float x, y ;
		} pair ;
		int n, m ;
		float aug_mat[MAX_DEG+1][MAX_DEG+2] ;
		pair dataset[MAX_SIZE] ;
		float constants[MAX_DEG+1] ;
};

PolyCurveFit::PolyCurveFit(){}

void PolyCurveFit::getDataset(){
	std::cout << "!!!!! POLYNOMIAL CURVE FITTING !!!!!" << std::endl ;
	std::cout << "Input the number of points in the dataset to fit: " ;
	std::cin >> n ;
	std::cout << "Input the order of polynomial to fit: " ;
	std::cin >> m ;
	if(n > MAX_SIZE){
		std::cout << "Element limit exceeded !" << std::endl ;
	}
	else if(m > MAX_DEG){
		std::cout << "Degree limit exceeded !" << std::endl ;
	}
	else{
		std::cout << "Dataset -> " << std::endl ;
		for(int i=0; i<n; i++){
			std::cout << i+1 << ". " ;
			std::cout << "X: " ; 
			std::cin >> dataset[i].x ;
			std::cout << "   Y: " ; 
			std::cin >> dataset[i].y ;
		}		
	}
}

void PolyCurveFit::calcAugMat(){	
	for(int i=0; i<=m; i++){
		for(int j=0; j<=m; j++){
			aug_mat[i][j] = 0 ;
			for(int k=0; k<n; k++)
				aug_mat[i][j] += pow(dataset[k].x, i+j) ;
		}
	}                       -  	
	for(int i=0; i<=m; i++){
		aug_mat[i][m+1] = 0 ;
		for(int k=0; k<n; k++)
			aug_mat[i][m+1] += pow(dataset[k].x, i)*dataset[k].y ;
	}
}

void PolyCurveFit::gauss_jordan(){
	float ratio ;
	m += 1 ;
	for(int i=0; i<m; i++){
		if(fabs(aug_mat[i][i]) < ALMOST_ZERO){
		    std::cout << "!!! PIVOT ZERO !!!" << std::endl ;
		    exit(1) ; 
		}
		for(int j=0; j<m; j++){
		    if(i!=j){
			    ratio = aug_mat[j][i] / aug_mat[i][i] ;
			    for(int k=i; k<m+1; k++){
			        aug_mat[j][k] -= ratio*aug_mat[i][k] ; 
				}
			}
		}
	}

    for(int i=0; i<m; i++){
    	constants[i] =  (aug_mat[i][m] / aug_mat[i][i]) ;
	}
}

void PolyCurveFit::displayDataset(){
	std::cout << std::setw(10) << "X" << std::setw(10) << "Y" << std::endl ;
	std::cout << "------------------------------" << std::endl ;	
	for(int i=0; i<n; i++){
		std::cout << std::setw(10) << dataset[i].x << std::setw(10) << dataset[i].y << std::endl ;
	}
}

void PolyCurveFit::displayPolyFit(){
	std::cout << "The polynomial fit is: y =  " << constants[0] << "x0" ;
	for(int k=1; k<m; k++){
			std::cout << " + " << constants[k] ;
    	 	std::cout << "x" << k ;
	}
}

int main(int argc, char *argv[]){
	PolyCurveFit *cf = nullptr ;
	cf = new PolyCurveFit() ;
	cf->getDataset() ; 
	cf->calcAugMat() ;
	cf->gauss_jordan() ;
	cf->displayDataset() ;
	cf->displayPolyFit() ;
	delete cf ;
	return 0 ;
}
