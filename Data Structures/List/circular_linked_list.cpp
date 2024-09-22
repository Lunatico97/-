#include <iostream>
#define LIST_SIZE 5

//Implementing a circular linked list

template <class T> class clinked_list
{		
	public :
		clinked_list() ;
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
		};
		
		Node *head ; // stores the address of the first node                  		
} ;

template <class T> clinked_list<T>::clinked_list(){
	head = nullptr ;
}

template <class T> bool clinked_list<T>::isEmpty(){
	if(head == nullptr) return true ;
	else return false ;
}

template <class T> void clinked_list<T>::insert(T element){
	Node *newNode = new Node ;
	newNode->value = element ;
	if(isEmpty()) // if there are no pre-existing nodes, it will be the first node i.e. 'head'
		insertAtHead(element) ;
	else{
		Node *temp = head ;
		while(temp->next != head){
			temp = temp->next ; }
		temp->next = newNode ;
		newNode->next = head ;
	}	
}

template <class T> void clinked_list<T>::insertAtHead(T element){
	Node *newNode = new Node ;
	newNode->value = element ;
	if(isEmpty()){
		newNode->next = newNode ;
		head = newNode ;
	} else{
		Node *temp = head ;
		while(temp->next != head){
			temp = temp->next ;
		}
		temp->next = newNode ;
		newNode->next = head ;
		head = newNode ;
	}
}

template <class T> bool clinked_list<T>::search(T testcase){
	std::cout << "Searching for: " << testcase << " -> ";
	Node *temp = head ;
	do{
		if(temp->value == testcase){
			return true ;	
		} 
		temp = temp->next ;
	}while (temp != head) ;
	return false ;
}

template <class T> void clinked_list<T>::print(){
	Node *temp = head ;
	do{
		std::cout << temp->value << std::endl ;
		temp = temp->next ;
	}while (temp != head) ;
}

template <class T> T clinked_list<T>::removeAtHead(){
	Node *temp = head ;
	while(temp->next != head){
		temp = temp->next ;
	}
	Node *wasteNode = head ;
	temp->next = head->next ;
	head = head->next ;
	delete wasteNode ; 
}

template <class T> T clinked_list<T>::removeAtIndex(int index){
	Node *temp = head ;
	for(int i=1; i<index-1; i++)
	    temp = temp->next ;
	Node *wasteNode = new Node ; 
	wasteNode = temp->next ;
	T getOut = wasteNode->value ;
	temp->next = temp->next->next ;
	delete wasteNode ;
	return getOut ;
}

template <class T> void clinked_list<T>::insertAtIndex(T element, int index){
	Node *newNode = new Node ;
	newNode->value = element ;
	Node *temp = new Node ;
	temp = head ;
	for(int i=1; i<index-1; i++)
	    temp = temp->next ;
	newNode->next = temp->next ;
	temp->next = newNode ;
}

int main(int argc, char *argv[]){
		
	clinked_list<char> list  ;
	list.insert('B') ;
	list.insert('C') ;
	list.insert('D') ;
	list.insertAtHead('A') ;
	std::cout << "Elements in the list are: " << std::endl ;
	list.print() ;
	if(list.search('C')) std::cout << "Got it on the list !" << std::endl ;
	else std::cout << "Nowhere on the list" << std::endl ; 
	list.removeAtIndex(2) ;
	std::cout << "Elements in the list are: " << std::endl ;
	list.print() ;
	list.removeAtIndex(2) ;
	std::cout << "Removed : Element at index 2 " << std::endl ;
	std::cout << "Elements in the list are: " << std::endl ;
	list.print() ;
	list.insertAtIndex('F', 2) ;
	std::cout << "Elements in the list are: " << std::endl ;
	list.print() ;
	return 0 ;
} 
