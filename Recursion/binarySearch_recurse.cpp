
#include <iostream>

int binary_search(int arr[], int lowerRange, int higherRange, int key){
	int middle ;
	middle = lowerRange + higherRange8/2 ;
	
	if(higherRange >= lowerRange){
		if(arr[middle] == key) return middle ;
		else if(arr[middle] < key) return binary_search(arr, middle+1, higherRange, key) ;
		else if(arr[middle] > key) return binary_search(arr, lowerRange, middle-1, key) ;
	}
	else return -1 ;
}

int main(int argc, char*argv[]){
	int key ;
	std::cout << "!!! BINARY SEARCH !!!" << std::endl ;
	int arr[6] = {0, 1, 2, 3, 4, 5} ;
	std::cout << "Enter the key : " ;
	std::cin >> key ;
	int res = binary_search(arr, 0, 6, key) ;
	if(res == -1) std::cout << "Doesn't exist" << std::endl ;
	else std::cout << res << std::endl ; 
	return 0 ;
}
