

#include <iostream>
#include <iomanip>
#include <cmath>

#define MAX_SIZE 20
#define ALMOST_ZERO 0.000001

inline float func(float x){
	return 2*x*x - 1 ;
}

class Trapezoidal
{
	public:
		Trapezoidal() ;
		float integrate() ;
		void getDataset() ;
		void displayDataset() ;
		
	private:		
		typedef struct {
			float x, y ;
		} pair ;
		int n, mode ;
		float h ;
		pair dataset[MAX_SIZE+1] ;
};

Trapezoidal::Trapezoidal(){}

void Trapezoidal::getDataset(){
	std::cout << "!!!!! TRAPEZOIDAL INTEGRATION !!!!!" << std::endl ;
	std::cout << "Input the number of sub-intervals: " ;
	std::cin >> n ;
	std::cout << "Will you give dataset or, use the function defined ?" << std::endl ;
	std::cin >> mode ;
	switch(mode){
		case 0 : 
			std::cout << "Enter x0: " ;
			std::cin >> dataset[0].x ;
			std::cout << "Enter xN: " ;
			std::cin >> dataset[n].x ;
		break ;
		
		case 1 :	
			if(n > MAX_SIZE){
				std::cout << "Element limit exceeded !" << std::endl ;
			}
			else{
				std::cout << "Dataset -> " << std::endl ;
				for(int i=0; i<n+1; i++){
					std::cout << i+1 << ". " ;
					std::cout << "X: " ; 
					std::cin >> dataset[i].x ;
					std::cout << "   Y: " ; 
					std::cin >> dataset[i].y ;
				}
			}
		break ;	
		
		default :
			break ;
	}
	h = (dataset[n].x - dataset[0].x) / n ;	
	std::cout << "Step-size(h) : " << h	<< std::endl ;
}

float Trapezoidal::integrate(){
	float sum = 0 ;
	if(!mode) dataset[0].y = func(dataset[0].x) ;
	sum += dataset[0].y ;
	
	for(int i=1; i<n; i+=1){
		if(!mode){
			dataset[i].x = dataset[i-1].x + h ;
			dataset[i].y = func(dataset[i].x) ;
		}	
		 sum += 2*dataset[i].y ;	
	}
	
	if(!mode) dataset[n].y = func(dataset[n].x) ;
	sum += dataset[n].y ;
	sum *= (h/2) ;
	
	return sum ;
}


void Trapezoidal::displayDataset(){
	std::cout << std::setw(10) << "X" << std::setw(10) << "Y" << std::endl ;
	std::cout << "------------------------------" << std::endl ;	
	for(int i=0; i<n+1; i++){
		std::cout << std::setw(10) << dataset[i].x << std::setw(10) << dataset[i].y << std::endl ;
	}
}

int main(int argc, char *argv[]){
	Trapezoidal *tp = nullptr ;
	tp = new Trapezoidal() ;
	tp->getDataset() ;
	float ans = tp->integrate() ;
	tp->displayDataset() ;
	std::cout << "Solution: " << ans << std::endl ;
	delete tp ;
	return 0 ;
}
