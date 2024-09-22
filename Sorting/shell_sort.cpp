#include <iostream>
#define SIZE 20
//Implement shell sort

void shell_sort(int arr[], int n){
	int temp, j ;
	for(int gap=n/2; gap>0; gap/=2){
		for(int i=gap; i<n; i++){
			temp = arr[i] ;
			for(j=i; j>=gap && arr[j-gap]>temp; j-=gap){
				arr[j] = arr[j-gap] ;
			}
			arr[j] = temp ;
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
	std::cout << "!!! SHELL SORT !!!" << std::endl ;
	std::cout << "No. of elements: " ;
	std::cin >> n ;
	std::cout << "Input the elements: " << std::endl ;
	for(int i=0; i<n; i++){
		std::cin >> arr[i] ;
	}
	std::cout << "Before sorting : " ;
	display(arr, n) ;
	std::cout << "\nAfter sorting  : " ;
	shell_sort(arr, n) ;
	display(arr, n) ; 
	return 0 ;  
}


