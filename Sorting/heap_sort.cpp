#include <iostream>
#define SIZE 20
//Implement heap sort

void heapify(int arr[], int n, int i){
	int temp ;
	int max = i ;
	int l = 2*i+1 ;
	int r = 2*i+2 ;
	
	if(l<n && arr[l]>arr[max]) max = l ;
	if(r<n && arr[r]>arr[max]) max = r ;
	if(max!=i){
		temp = arr[i] ; arr[i] = arr[max] ; arr[max] = temp ; //Alternative : std::swap(arr[i], arr[max]) ;
		heapify(arr, n, max) ;
	}
}

void heap_sort(int arr[], int n){
	int temp ;
	for(int i=n/2-1; i>=0; i--){
		heapify(arr, n, i) ;
	}
	for(int i=n-1; i>0; i--){
		temp = arr[0] ; arr[0] = arr[i] ; arr[i] = temp ; //Alternative : std::swap(arr[0], arr[i]) ;
		heapify(arr, i, 0) ;
	}
}

void display(int arr[], int n){
	for(int i=0; i<n; i++){
		std::cout << arr[i] << "\t" ;
	}
}

int main(int argc, char *argv[]){
	int n, arr[SIZE] ;
	std::cout << "!!! HEAP SORT !!!" << std::endl ;
	std::cout << "No. of elements: " ;
	std::cin >> n ;
	std::cout << "Input the elements: " << std::endl ;
	for(int i=0; i<n; i++){
		std::cin >> arr[i] ;
	}
	std::cout << "Before sorting : " ;
	display(arr, n) ;
	std::cout << "\nAfter sorting  : " ;
	heap_sort(arr, n) ;
	display(arr, n) ; 
	return 0 ;  
}

