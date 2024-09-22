#include <iostream>
#define QUEUE_SIZE 5

//Implementing a queue data structure

template <class T> class Queue
{		
	public :
		Queue() ;
		void enqueue(T element) ;
		T dequeue() ;
		T getFront() ;
		bool isFull() ;
		bool isEmpty() ;
	
	private :
		int front, rear ; 
		T *array ;
		
} ;

template <class T> Queue<T>::Queue(){
	array = new T[QUEUE_SIZE] ;
	front = -1 ;
	rear = -1 ;
}

template <class T> bool Queue<T>::isFull(){
	if(rear == (QUEUE_SIZE-1))
			return true ;
	else 
		return false ;
}

template <class T> bool Queue<T>::isEmpty(){
	if(front == -1 || front > rear)
			return true ;
	else 
		return false ;
}

template <class T> void Queue<T>::enqueue(T element){
	if(isFull())
		std::cout << "Queue Is Full !" << std::endl ;
	else{
		if(front == -1) front += 1 ;
		rear += 1 ;
		*(array+rear) = element ;
	}
}

template <class T> T Queue<T>::dequeue(){
	if(isEmpty())
		std::cout << "Queue Is Empty !" << std::endl ;
	else{
		T getOut = *(array+front);
		front += 1 ;
		return getOut ;
	}
}

template <class T> T Queue<T>::getFront(){
	T getOut = *(array+front) ;
	return getOut ;
}

int main(int argc, char *argv[]){
	
	Queue<int> queue ;
		
	queue.enqueue(10) ;
	queue.enqueue(20) ;
	queue.enqueue(30) ;
	queue.enqueue(40) ;	
	queue.enqueue(50) ;	
	std::cout << "Front Of The Queue: " << queue.getFront() << std::endl ;
	
	queue.enqueue(60) ;
	
	std::cout << "Elements in the Queue are : " << std::endl ;
	for(int i=0; i<5; i++ )
		std::cout << queue.dequeue() << std::endl ;
	
	queue.dequeue() ;
	
	return 0 ;
} 
