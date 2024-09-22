   
#include <iostream>
#include <iomanip>
#include <cmath>

#define MAX_SIZE 20
#define ALMOST_ZERO 0.000001

class Lagrange
{
	public:
		Lagrange() ;
		float interpolate(float x) ;
		void getDataset() ;
		void displayDataset() ;
		
	private:		
		typedef struct {
			float x, y ;
		} pair ;
		int n ;
		pair dataset[MAX_SIZE] ;
};

Lagrange::Lagrange(){}

void Lagrange::getDataset(){
	std::cout << "!!!!! LAGRANGE INTERPOLATION !!!!!" << std::endl ;
	std::cout << "Input the number of points in the dataset to fit: " ;
	std::cin >> n ;
	if(n > MAX_SIZE){
		std::cout << "Element limit exceeded !" << std::endl ;
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

float Lagrange::interpolate(float x){
	float pro ;
	float sum = 0 ;
	for(int i=0; i<n; i++){
		pro = 1 ;   
		for(int j=0; j<n; j++){
			if(i != j) {
				pro *= ((x-dataset[j].x)/(dataset[i].x-dataset[j].x)) ;
			}
		}
		pro *= dataset[i].y ;
		sum += pro ; 
	}
	return sum ;
}


void Lagrange::displayDataset(){
	std::cout << std::setw(10) << "X" << std::setw(10) << "Y" << std::endl ;
	std::cout << "------------------------------" << std::endl ;	
	for(int i=0; i<n; i++){
		std::cout << std::setw(10) << dataset[i].x << std::setw(10) << dataset[i].y << std::endl ;
	}
}

int main(int argc, char *argv[]){
	Lagrange *lg = nullptr ;
	lg = new Lagrange() ;
	lg->getDataset() ;
	float x ;
	std::cout << "Feed a value to interpolate: " ;
	std::cin >> x ;	
	lg->displayDataset() ;
	std::cout << "Solution: " << "f(" << x << ") = " << lg->interpolate(x) ;
	delete lg ;
	return 0 ;
}
