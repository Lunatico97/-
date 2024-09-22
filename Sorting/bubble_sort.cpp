#include <iostream>
#define SIZE 20
//Implement bubble sort

void bubble_sort(int arr[], int n){
	int temp ;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j] ; arr[j] = arr[j+1] ; arr[j+1] = temp ; // Alternative: std::swap(arr[j], arr[j+1]) ;	
			}
		}
	}
}

void display(int arr[], int n){
	for(int i=0; i<n; i++){
		std::cout << arr[i] << "\t" ;
	}
}

int main(int argc, char *argv[]){
	int n, arr[SIZE] ;
	std::cout << "!!! BUBBLE SORT !!!" << std::endl ;
	std::cout << "No. of elements: " ;
	std::cin >> n ;
	std::cout << "Input the elements: " << std::endl ;
	for(int i=0; i<n; i++){
		std::cin >> arr[i] ;
	}
	std::cout << "Before sorting : " ;
	display(arr, n) ;
	std::cout << "\nAfter sorting  : " ;
	bubble_sort(arr, n) ;
	display(arr, n) ; 
	return 0 ;  
}
