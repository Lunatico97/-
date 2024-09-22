
#include<iostream>
#include<vector>

using namespace std;

class Queue{
	private:
		int size;
		int front;
		int rear;
		vector <int> intArray;
		
	public:
		Queue(int size){
			this->size=size;
			this->front=0;
			this->rear=-1;
			intArray.reserve(size);
			
		}
		
		
		
		bool isEmpty(){
			return front==size;
		}
		
		void addAtEnd(int item){
				if(rear==size-1){
				// queue is full
				cout<<"Queue is full"<<endl;
			}
			intArray[++rear] = item;
		}
		
		void addAtBeginning(int item){
				if(rear==size-1){
				// queue is full
				cout<<"Queue is full"<<endl;
			}
			else if (front<=0){front = size ;
			}
			intArray[--front] = item;
			
		}
		
		int deleteFromBeginning(){
			if(front == size){
				cout<<"Queue is empty"<<endl;
				front=0;
			}
			
			int temp = intArray[front];
			front++;
			return temp;
			
		}
		
		int deleteFromEnd(){
				if(front == size){
				cout<<"Queue is empty"<<endl;
			}
			
			else if(rear < 0){
				rear = -1;
			}
			
			int temp = intArray[--rear];
			return temp;
		}
		
		void showdata(){
			for(int i=0;i<=size-1;i++){
				cout<<intArray[i]<<endl;
			}
		}
		
		
};

int main(){
	Queue queueobj(3);
	
	queueobj.addAtEnd(10);
	queueobj.addAtEnd(20);
	queueobj.addAtBeginning(30);
	
	queueobj.showdata();
}
