#include <iostream>
#define SIZE 20
//Implement quick sort

int partition(int arr[], int l, int r){
	int pivot = arr[r] ;
	int i = l-1 ;
	int temp ;
	
	for(int j=l; j<r; j++){
		if(arr[j]<pivot){
			i++ ;
			temp = arr[i] ; arr[i] = arr[j] ; arr[j] = temp ; //Alternative : std::swap(arr[i], arr[j]) ;
		}
	}
	temp = arr[i+1] ; arr[i+1] = arr[r] ; arr[r] = temp ; //Alternative : std::swap(arr[i+1], arr[r]) ;
	return i+1 ;
}

void quick_sort(int arr[], int l, int r){
	if(l<r){
		int pivot = partition(arr, l, r) ;
		quick_sort(arr, l, pivot-1) ;
		quick_sort(arr, pivot+1, r) ;
	}
}

void display(int arr[], int n){
	for(int i=0; i<n; i++){
		std::cout << arr[i] << "\t" ;
	}
}

int main(int argc, char *argv[]){
	int n, arr[SIZE] ;
	std::cout << "!!! QUICK SORT !!!" << std::endl ;
	std::cout << "No. of elements: " ;
	std::cin >> n ;
	std::cout << "Input the elements: " << std::endl ;
	for(int i=0; i<n; i++){
		std::cin >> arr[i] ;
	}
	std::cout << "Before sorting : " ;
	display(arr, n) ;
	std::cout << "\nAfter sorting  : " ;
	quick_sort(arr, 0, n-1) ;
	display(arr, n) ; 
	return 0 ;  
}


