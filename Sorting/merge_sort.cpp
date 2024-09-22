#include <iostream>
#define SIZE 20
//Implement merge sort

void merge(int arr[], int l, int mid, int r){
	int i = l ; 
	int j = mid+1 ;
	int k = l ;
	int tmp_arr[r-l+1] ;
	while(i<=mid && j<=r){
		if(arr[i] <= arr[j]){
			tmp_arr[k] = arr[i] ;
			i++ ;
		}
		else{
			tmp_arr[k] = arr[j] ;
			j++ ;
		}
		k++ ;
	}
	while(j<=r){
		tmp_arr[k] = arr[j] ;
		j++ ;
		k++ ;
	}
	while(i<=mid){
		tmp_arr[k] = arr[i] ;
		i++ ;
		k++ ;
	}
	for(int i=l; i<=r; i++){
		arr[i] = tmp_arr[i] ;
	}
}

void merge_sort(int arr[], int l, int r){
	if(l<r){
		int mid = (l+r)/2 ;
		merge_sort(arr, l, mid) ;
		merge_sort(arr, mid+1, r) ;
		merge(arr, l, mid, r) ;
	}
}

void display(int arr[], int n){
	for(int i=0; i<n; i++){
		std::cout << arr[i] << "\t" ;
	}
}

int main(int argc, char *argv[]){
	int n, arr[SIZE] ;
	std::cout << "!!! MERGE SORT !!!" << std::endl ;
	std::cout << "No. of elements: " ;
	std::cin >> n ;
	std::cout << "Input the elements: " << std::endl ;
	for(int i=0; i<n; i++){
		std::cin >> arr[i] ;
	}
	std::cout << "Before sorting : " ;
	display(arr, n) ;
	std::cout << "\nAfter sorting  : " ;
	merge_sort(arr, 0, n-1) ;
	display(arr, n) ; 
	return 0 ;  
}


