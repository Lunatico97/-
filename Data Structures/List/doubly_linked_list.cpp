#include <iostream>
#define LIST_SIZE 5

//Implementing a doubly linked list

template <class T> class dlinked_list
{		
	public :
		dlinked_list() ;
		bool isEmpty() ;
		void insert(T element) ;
		void insertAtHead(T element) ;
		void insertAtIndex(T element, int index) ;
		T remove(T getout) ;
		T removeAtHead() ;
		T removeAtIndex(int index) ;
		bool search(T testcase) ;
		void print() ;
	
	private :	
		struct Node{
			T value ;
			Node *next = nullptr ; // points to the address of the next node to it
			Node *prev = nullptr ; // points to the address of the previous node to it
		};
		
		Node *head ; // stores the address of the first node                  		
} ;

template <class T> dlinked_list<T>::dlinked_list(){
	head = nullptr ;
}

template <class T> bool dlinked_list<T>::isEmpty(){
	if(head == nullptr) return true ;
	else return false ;
}

template <class T> void dlinked_list<T>::insert(T element){
	Node *newNode = new Node ;
	newNode->value = element ;
	if(isEmpty()) // if there are no pre-existing nodes, it will be the first node i.e. 'head'
		insertAtHead(element) ;
	else{
		Node *temp = head ;
		while(temp->next != nullptr){
			temp = temp->next ; }
		temp->next = newNode ;
		newNode->prev = temp ;
	}	
}

template <class T> void dlinked_list<T>::insertAtHead(T element){
	Node *newNode = new Node ;
	newNode->value = element ;
	newNode->next = head ;
	if(head != nullptr) head->prev = newNode ;
	head = newNode ;
}

template <class T> bool dlinked_list<T>::search(T testcase){
	std::cout << "Searching for: " << testcase << " -> ";
	Node *temp = head ;
	while (temp != nullptr){
		if(temp->value == testcase){
			return true ;	
		} 
		temp = temp->next ;
	}
	return false ;
}

template <class T> void dlinked_list<T>::print(){
	Node *temp = head ;
	while (temp != nullptr){
		std::cout << temp->value << std::endl ;
		temp = temp->next ;
	}
}

template <class T> T dlinked_list<T>::removeAtHead(){
	Node *temp = head ;
	// New 'head' is choosen which is at address pointed by 'next' pointer of the 'head'
	head = head->next ; 
	head->prev = nullptr ;
	T get = temp->value ;
	delete temp ;
	return get ;
}

template <class T> T dlinked_list<T>::remove(T getout){
	if(search(getout)){
		std::cout << "Removed: " << getout << std::endl ;
		Node *temp = head ;
		// If a list is empty, there is no element to remove
		if(isEmpty()) 
			return -1;
		// If a list has a single element pointing to nothing, there is only one element to remove i.e. 'head'	
		else if(head->next == nullptr) 
			return removeAtHead() ;
		// If a list has multiple elements and the element to delete is the 'head'	
		else if(head->value == getout)
			return removeAtHead() ;
		else{
			while(temp->next->value != getout){
			  temp = temp->next ;
			}
			Node *wasteNode = temp->next ;
			temp->next = temp->next->next ;
			temp->next->prev = temp ;
			delete wasteNode ;
			return getout ;
		}
	}else{
		std::cout << "Remove failed : Doesn't exist !" << std::endl ;
	}	
}

template <class T> T dlinked_list<T>::removeAtIndex(int index){
	Node *temp = new Node ;
	temp = head ;
	for(int i=1; i<index-1; i++)
	    temp = temp->next ;
	Node *wasteNode = temp->next ;
	T getOut = wasteNode->value ;
	temp->next = temp->next->next ;
	temp->next->prev = temp ;
	delete wasteNode ;
	return getOut ;
}

template <class T> void dlinked_list<T>::insertAtIndex(T element, int index){
	Node *newNode = new Node ;
	newNode->value = element ;
	Node *temp = head ;
	for(int i=1; i<index-1; i++)
	    temp = temp->next ;
	newNode->prev = temp ;
	temp->next->prev = newNode ;
	newNode->next = temp->next ;
	temp->next = newNode ;
}

int main(int argc, char *argv[]){
		
	dlinked_list<char> list  ;
	list.insert('B') ;
	list.insert('C') ;
	list.insert('D') ;
	list.insertAtHead('A') ;
	std::cout << "Elements in the list are: " << std::endl ;
	list.print() ;
	if(list.search('C')) std::cout << "Got it on the list !" << std::endl ;
	else std::cout << "Nowhere on the list" << std::endl ;
	list.remove('B') ;
	std::cout << "Elements in the list are: " << std::endl ;
	list.print() ;
	list.remove('E') ;
	list.removeAtIndex(2) ;
	std::cout << "Removed : Element at index 2 " << std::endl ;
	std::cout << "Elements in the list are: " << std::endl ;
	list.print() ;
	list.insertAtIndex('F', 2) ;
	std::cout << "Elements in the list are: " << std::endl ;
	list.print() ;
	return 0 ;
} 
