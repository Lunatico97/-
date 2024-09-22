
#include <iostream>
#define CQUEUE_SIZE 5

//Implementing a circular queue

template <class T> class CQueue
{		
	public :
		CQueue() ;
		void enqueue(T element) ;
		T dequeue() ;
		bool isFull() ;
		bool isEmpty() ;
		int getSize() ;
	
	private :
		int front, rear ; 
		T *array ;
		
} ;

template <class T> CQueue<T>::CQueue(){
	array = new T[CQUEUE_SIZE] ;
	front = -1 ;
	rear = -1 ;
}

template <class T> bool CQueue<T>::isFull(){
	if(front == (rear+1) % CQUEUE_SIZE)
			return true ;
	else 
		return false ;
}

template <class T> bool CQueue<T>::isEmpty(){
	if(front == -1)
			return true ;
	else 
		return false ;
}

template <class T> void CQueue<T>::enqueue(T element){
	if(isFull())
		std::cout << "Queue Is Full !" << std::endl ;
	else{
		if(front == -1) front += 1 ;
		rear = (rear+1) %  CQUEUE_SIZE ;
		*(array+rear) = element ;
	}
}

template <class T> T CQueue<T>::dequeue(){
	if(isEmpty())
		std::cout << "Queue Is Empty !" << std::endl ;
	else{
		T getOut = *(array+front);
		if(front == rear){
			front = -1 ;
			rear = -1 ;
		}
		else front = (front+1) % CQUEUE_SIZE ;
		return getOut ;
	}
}

template <class T> int CQueue<T>::getSize(){
	if(rear >= front) return (rear - front) + 1 ;
	else return CQUEUE_SIZE - (front - rear) + 1 ;
}

int main(int argc, char *argv[]){
	
	CQueue<int> cqueue ;
		
	cqueue.enqueue(10) ;
	cqueue.enqueue(20) ;
	cqueue.enqueue(30) ;
	cqueue.enqueue(40) ;
	cqueue.enqueue(50) ;	
	std::cout << "Size Of Circular Queue: " << cqueue.getSize() << std::endl ;
	cqueue.enqueue(60) ;
	int size = cqueue.getSize() ;
	std::cout << "Elements in the Queue are : " << std::endl ;
	for(int i=0; i<size; i++ )
		std::cout << cqueue.dequeue() << std::endl ;
	
	cqueue.dequeue() ;
	
	return 0 ;
} 
