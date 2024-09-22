#include <iostream>
#define SIZE 20
//Implement radix sort

int getMax(int arr[], int n){
	int max = arr[0] ;
	for(int i=1; i<n; i++){
		if(arr[i] > max){
			max = arr[i] ;
		}
	}
	return max ;
}

void count_sort(int arr[], int n, int digit){
	int tmp_arr[n], count[10] = {0};
	
	for(int i=0; i<n; i++){
		count[(arr[i]/digit)%10] += 1 ;
	}
	for(int i=1; i<10; i++){
		count[i] += count[i-1] ;
	}
	for(int i=n-1; i>=0; i--){
		tmp_arr[count[(arr[i]/digit)%10]-1] = arr[i] ;
		count[(arr[i]/digit)] -= 1 ;
	}
	for(int i=0; i<n; i++){
		arr[i] = tmp_arr[i] ;
	}
}

void radix_sort(int arr[], int n){
	int max = getMax(arr, n) ;
	for(int digit=1; max/digit > 0; digit*=10){
		count_sort(arr, n, digit) ;
	}
}

void display(int arr[], int n){
	for(int i=0; i<n; i++){
		std::cout << arr[i] << "\t" ;
	}
}

int main(int argc, char *argv[]){
	int n, arr[SIZE] ;
	std::cout << "!!! RADIX SORT !!!" << std::endl ;
	std::cout << "No. of elements: " ;
	std::cin >> n ;
	std::cout << "Input the elements: " << std::endl ;
	for(int i=0; i<n; i++){
		std::cin >> arr[i] ;
	}
	std::cout << "Before sorting : " ;
	display(arr, n) ;
	std::cout << "\nAfter sorting  : " ;
	radix_sort(arr, n) ;
	display(arr, n) ; 
	return 0 ;  
}
