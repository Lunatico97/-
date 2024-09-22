#include <iostream>
#define SIZE 20
//Implement exchange sort 

void exchange_sort(int arr[], int n){
	int temp ;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(arr[i] > arr[j]){
				temp = arr[j] ; arr[j] = arr[i] ; arr[i] = temp ; // Alternative: std::swap(arr[i], arr[j]) ;	
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
	std::cout << "!!! EXCHANGE SORT !!!" << std::endl ;
	std::cout << "No. of elements: " ;
	std::cin >> n ;
	std::cout << "Input the elements: " << std::endl ;
	for(int i=0; i<n; i++){
		std::cin >> arr[i] ;
	}
	std::cout << "Before sorting : " ;
	display(arr, n) ;
	std::cout << "\nAfter sorting  : " ;
	exchange_sort(arr, n) ;
	display(arr, n) ; 
	return 0 ;  
}
