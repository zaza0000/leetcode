//Given a linked list, remove the n-th node from the end of list and return its head.
//Solution 1: Do the traversal of the list two times. Record the length ah the first time.
//Solution 2: create a forehead, use two pointer, set the distance between the two as n+1

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

void display(ListNode *headnode){
	while(headnode != NULL){
		cout<<headnode->val<<", ";
		headnode = headnode->next;
	}
	cout<<endl;

}

//solution 2:
class Solution{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n){
		ListNode *p, *q;
		p = new ListNode(0);
		p->next = head;
		q = p;
		head = p;
		for(int i = 0; i < n+1; i++){
			p = p->next;
		}
		while(p != NULL){
			p = p->next;
			q = q->next;
		}
		q->next = q->next->next;
		return head->next;
	}

};

int main(){
	ListNode *head, *p;
	head = new ListNode(1);
	p = head;
	for(int i = 1; i < 5; i++){
		p->next = new ListNode(i+1);
		p = p->next;
	}
	display(head);
	Solution s;
	display(s.removeNthFromEnd(head,5));

	cout<<"helloworld"<<endl;
	return 0;
}