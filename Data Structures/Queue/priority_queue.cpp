
#include <iostream>
#define PQUEUE_SIZE 5

//Implementing a priority queue

template <class T> class PQueue
{		
	public :
		PQueue() ;
		void enqueue(T element) ;
		T dequeue() ;
		bool isFull() ;
		bool isEmpty() ;
	
	private :
		int front, rear ; 
		T *array ;
		
} ;

template <class T> PQueue<T>::PQueue(){
	array = new T[PQUEUE_SIZE] ;
	rear = 0 ;
}

template <class T> bool PQueue<T>::isFull(){
	if(rear == PQUEUE_SIZE - 1)
			return true ;
	else 
		return false ;
}

template <class T> bool PQueue<T>::isEmpty(){
	if(rear == 0)
			return true ;
	else 
		return false ;
}

template <class T> void PQueue<T>::enqueue(T element){
	if(isFull())
		std::cout << "Queue Is Full !" << std::endl ;
	else{
		front = rear - 1;
		while(front >= 0 && element < *(array+front)){
			*(array+front+1) = *(array+front) ;
			front -- ;
		}
		*(array+front+1) = element ;
		rear += 1 ;
	}
}

template <class T> T PQueue<T>::dequeue(){
	if(isEmpty())
		std::cout << "Queue Is Empty !" << std::endl ;
	else{
		T getOut = *(array+rear-1);
		rear -= 1 ;
		return getOut ;
	}
}

int main(int argc, char *argv[]){
	
	PQueue<int> pqueue ;
		
	pqueue.enqueue(60) ;
	pqueue.enqueue(10) ;
	pqueue.enqueue(30) ;	
	pqueue.enqueue(20) ;
	std::cout << "Elements in the Queue are : " << std::endl ;
	for(int i=0; i<4; i++ )
		std::cout << pqueue.dequeue() << std::endl ;
	
	pqueue.dequeue() ;
	
	return 0 ;
} 
