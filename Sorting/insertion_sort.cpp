#include <iostream>
#define SIZE 20
//Implement insertion sort

void insertion_sort(int arr[], int n){
	int current, j ;
	for(int i=1; i<n; i++){
	 	current = arr[i] ;
		j = i-1 ;                                     
		while(j>=0 && arr[j] > current){
			arr[j+1] = arr[j] ; 
			j-- ; 
		}
		arr[j+1] = current ;
	}
	
}

void display(int arr[], int n){
	for(int i=0; i<n; i++){
		std::cout << arr[i] << "\t" ;
	}
}

int main(int argc, char *argv[]){
	int n, arr[SIZE] ;
	std::cout << "!!! INSERTION SORT !!!" << std::endl ;
	std::cout << "No. of elements: " ;
	std::cin >> n ;
	std::cout << "Input the elements: " << std::endl ;
	for(int i=0; i<n; i++){
		std::cin >> arr[i] ;
	}
	std::cout << "Before sorting : " ;
	display(arr, n) ;
	std::cout << "\nAfter sorting  : " ;
	insertion_sort(arr, n) ;
	display(arr, n) ; 
	return 0 ;  
}


