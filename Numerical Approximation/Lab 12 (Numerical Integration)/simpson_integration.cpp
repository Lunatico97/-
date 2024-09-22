
#include <iostream>
#include <iomanip>
#include <cmath>

#define MAX_SIZE 20
#define ALMOST_ZERO 0.000001

#define ONE_THIRD 0
#define THIRD_EIGHT 1

inline float func(float x){
	return log(x)/x ;
}

class Simpson
{
	public:
		Simpson() ;
		float integrate() ;
		void getDataset() ;
		void displayDataset() ;
		
	private:		
		typedef struct {
			float x, y ;
		} pair ;
		int n, mode, rule ;
		float h ;
		pair dataset[MAX_SIZE+1] ;
};

Simpson::Simpson(){}

void Simpson::getDataset(){
	std::cout << "!!!!! SIMPSON INTEGRATION !!!!!" << std::endl ;
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

float Simpson::integrate(){
	float sum = 0 ;
	if(!mode) dataset[0].y = func(dataset[0].x) ;
	sum += dataset[0].y ;
	
	if(n%2==0 || n%3==0){
		if(n%2 == 0) rule = ONE_THIRD ;
		else if(n%3 == 0) rule = THIRD_EIGHT ;
		else rule = ONE_THIRD ;
	}
	
	for(int i=1; i<n; i+=1){
		if(!mode){
			dataset[i].x = dataset[i-1].x + h ;
			dataset[i].y = func(dataset[i].x) ;
		}
		switch(rule){
			case ONE_THIRD :
				std::cout << "Using Simpson's 1/3 rule ... " << std::endl ;
				if(i%2==0) sum += 2*dataset[i].y ;
				else sum += 4*dataset[i].y ;
				break ;
				
			case THIRD_EIGHT :
				std::cout << "Using Simpson's 3/8 rule ... " << std::endl ;
				if(i%3==0) sum += 2*dataset[i].y ;
				sum += 3*dataset[i].y ;
				break ;
				
			default :
				break ;
		}
	}
	
	if(!mode) dataset[n].y = func(dataset[n].x) ;
	sum += dataset[n].y ;
	if(rule == ONE_THIRD) sum *= (h/3) ;
	else sum *= (3*h/8) ;
	
	return sum ;
}


void Simpson::displayDataset(){
	std::cout << std::setw(10) << "X" << std::setw(10) << "Y" << std::endl ;
	std::cout << "------------------------------" << std::endl ;	
	for(int i=0; i<n+1; i++){
		std::cout << std::setw(10) << dataset[i].x << std::setw(10) << dataset[i].y << std::endl ;
	}
}

int main(int argc, char *argv[]){
	Simpson *sp = nullptr ;
	sp = new Simpson() ;
	sp->getDataset() ;
	float ans = sp->integrate() ;
	sp->displayDataset() ;
	std::cout << "Solution: " << ans << std::endl ;
	delete sp ;
	return 0 ;
}
