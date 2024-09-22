#include <iostream>
//Solve Tower Of Hanoi for 'n' discs using recursion
void towerOfHanoi(int num, char src, char des, char aux){
	if(num == 0) return ;
	towerOfHanoi(num-1, src, aux, des) ;
	std::cout << "Move the upper disc from " << src << " to " << des << " {DISC NO: " << num << "}" << std::endl ;
	towerOfHanoi(num-1, aux, des, src) ;
}

int main(int argc, char *argv[]){
	int num ;
	std::cout << "!!! TOWER OF HANOI !!!" << std::endl ;
	std::cout << "Enter number of discs: " ;
	std::cin >> num ;
	std::cout << "INSTRUCTIONS: " << std::endl ;
	towerOfHanoi(num, 'A', 'C', 'B') ;
	return 0 ;  
}
