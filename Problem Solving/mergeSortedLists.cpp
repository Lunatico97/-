// Merge two sorted lists to generate a sorted list
// Input lists will be already sorted in ascending order
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
int sizeList(ListNode* list)
{
	int count = 0 ;
	ListNode *temp = list;
	while(temp != nullptr)
	{
		count += 1;
		std::cout << temp->val << std::endl;
		temp = temp->next;
	}
	return count;
}

void pushIntoList(ListNode* list, int value)
{
	ListNode *newNode = new ListNode(value);
	if(list == nullptr)
	{
		list = newNode;
	}
	else
	{
		ListNode *temp = list;
		while(temp->next != nullptr)
		{
			temp = temp->next ; 
		}
		temp->next = newNode;
	}	
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode *head = new ListNode();
	ListNode *result = head;
	// All we do is check which list's first element is smaller and 
	// then shift its pointer to next element for next comparison to do same stuff till one list runs out of elements
	while(list1 != nullptr && list2 != nullptr)
	{
		if(list1->val <= list2->val)
		{
			result->next = list1;
			list1 = list1->next;
		}
		else 
		{
			result->next = list2;
			list2 = list2->next;
		}
		result = result -> next;
	}
	// At last we check which element has some elements left and if list is non-empty, attach it to the result list
	if(list1 != nullptr)
	{
		result->next = list1;
	}
	if(list2 != nullptr)
	{
		result->next = list2;	
	}
	// Since the list actually started with zero element by default while creating node,
	// we skip that while returning result.
	return head->next;
}

int main(int argc, char *argv[])
{
	ListNode *list1 = new ListNode(10);
	pushIntoList(list1, 20);
	pushIntoList(list1, 30);
	pushIntoList(list1, 40);
	
	ListNode *list2 = new ListNode(9);
	pushIntoList(list2, 15);
	pushIntoList(list2, 18);
	pushIntoList(list2, 39);
	
	ListNode *list3 = mergeTwoLists(list1, list2);
	std::cout << "Count: " << sizeList(list3);
	
	delete list1;
	delete list2;
	delete list3;	
	return 0;
}
