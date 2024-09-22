
#include <iostream>
#define LIST_SIZE 3

//Implementing a static list

template <class T> class static_list
{		
	public :
		static_list() ;
		bool isFull() ;
		bool isEmpty() ;
		void insert(T element, int pos) ;
		T remove(int pos) ;
	
	private :
		T *array ;
		int size ;
		
} ;

template <class T> static_list<T>::static_list(){
	array = new T[LIST_SIZE] ;
	size = -1 ;
	
}

template <class T> bool static_list<T>::isFull(){
	if(size == LIST_SIZE - 1)
			return true ;
	else 
		return false ;
}

template <class T> bool static_list<T>::isEmpty(){
	if(size == -1)
			return true ;
	else 
		return false ;
}

template <class T> void static_list<T>::insert(T element, int pos){
	if(isFull())
			std::cout << "List Is Full !" << std::endl ;
	else{
		size += 1 ;
		*(array + pos - 1) = element ;
	} 
		
}

template <class T> T static_list<T>::remove(int pos){
	if(isEmpty())
			std::cout << "List Is Empty !" << std::endl ;
	else{
		T element = *(array + pos - 1) ;
		while(pos-1 < size){
			*(array+pos-1) = *(array+pos) ;
			pos += 1 ;
		}		
		return element ;
	} 		
}

int main(int argc, char *argv[]){
	static_list<int> slist ;
	slist.remove(1) ;
	slist.insert(10, 1) ;
	slist.insert(20, 2) ;
	slist.insert(30, 3) ;
	slist.insert(40, 4) ;
	std::cout << slist.remove(1) << std::endl ;
	std::cout << slist.remove(2) << std::endl ;
	return 0 ;
} 
