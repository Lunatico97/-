
#include <iostream>
#define STACK_SIZE 5

//Implementing a stack data structure

template <class T> class Stack
{		
	public :
		Stack() ;
		void push(T element) ;
		T pop() ;
		T peek() ;
		bool isFull() ;
		bool isEmpty() ;
	
	private :
		int top ; 
		T *array ;
		
} ;

template <class T> Stack<T>::Stack(){
	array = new T[STACK_SIZE] ;
	top = -1 ;
	for(int i=0; i<STACK_SIZE; i++){
		*(arr+i) = NULL ;
	}
}

template <class T> bool Stack<T>::isFull(){
	if(top == (STACK_SIZE-1))
			return true ;
	else 
		return false ;
}

template <class T> bool Stack<T>::isEmpty(){
	if(top == -1)
			return true ;
	else 
		return false ;
}

template <class T> void Stack<T>::push(T element){
	if(isFull())
		std::cout << "Stack Overflow" << std::endl ;
	else{
		top += 1 ;
		array[top] = element ;
	}
}

template <class T> T Stack<T>::pop(){
	if(isEmpty())
		std::cout << "Stack Underflow" << std::endl ;
	else{
		T getOut = array[top] ;
		top -= 1 ;
		return getOut ;
	}
}

template <class T> T Stack<T>::peek(){
	T getOut = array[top] ;
	return getOut ;
}

int main(int argc, char *argv[]){
	
	Stack<int> stack ;
		
	stack.push(10) ;
	stack.push(20) ;
	stack.push(30) ;
	stack.push(40) ;	
	stack.push(50) ;	
	std::cout << "Top Of The Stack: " << stack.peek() << std::endl ;
	
	stack.push(60) ;
	
	std::cout << "Elements in the stack are : " << std::endl ;
	for(int i=0; i<5; i++ )
		std::cout << stack.pop() << std::endl ;
	
	stack.pop() ;
	
	return 0 ;
} 
