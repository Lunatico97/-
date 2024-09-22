#include <iostream>
#define SIZE 20
//Implement selection sort

void selection_sort(int arr[], int n){
	int temp ;
	for(int i=0; i<n-1; i++){ //Alternative: min=0 at first and assign j to min if arr[j] < arr[min] 
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[i]){
				temp = arr[i] ; arr[i] = arr[j] ; arr[j] = temp ; // Alternative: std::swap(arr[i], arr[j]) ;
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
	std::cout << "!!! SELECTION SORT !!!" << std::endl ;
	std::cout << "No. of elements: " ;
	std::cin >> n ;
	std::cout << "Input the elements: " << std::endl ;
	for(int i=0; i<n; i++){
		std::cin >> arr[i] ;
	}
	std::cout << "Before sorting : " ;
	display(arr, n) ;
	std::cout << "\nAfter sorting  : " ;
	selection_sort(arr, n) ;
	display(arr, n) ; 
	return 0 ;  
}


