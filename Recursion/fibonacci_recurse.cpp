#include <iostream>
//Generate Fibonacci series upto 'n' terms using recursion
int fibo(int num){
	if(num == 0) return 0 ;
	else if(num == 1) return 1 ;
	else return fibo(num-1) + fibo(num-2) ;
}

int main(int argc, char *argv[]){
	int num ;
	std::cout << "!!! FIBONACCI SERIES !!!" << std::endl ;
	std::cout << "Enter number of terms to obtain for the series: " ;
	std::cin >> num ;
	std::cout << "FIBONACCI SERIES UPTO " << num << " TERMS : " << std::endl ;
	for(int i=0; i<num; i++)
	std::cout << fibo(i) << "\t " ;
	return 0 ;  
}
