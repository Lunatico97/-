#include <iostream>
//Calculate factorial of a number using recursion
int fact(int num){
	if(num <= 1) return 1 ;
	else return num*fact(num-1) ;
}

int main(int argc, char *argv[]){
	int num ;
	std::cout << "!!! FACTORIAL !!!" << std::endl ;
	std::cout << "Enter a number: " ;
	std::cin >> num ;
	std::cout << "FACTORIAL(" << num << ") : " << fact(num) << std::endl ;
	return 0 ;  
}
